
#include "Display.hpp"

#include "mxrp/base/io/IoData.hpp"
#include "mxrp/base/io/IoHandler.hpp"
#include "mxrp/base/Number.hpp"
#include "mxrp/base/String.hpp"
#include "mxrp/base/util/str_utils.hpp"

#include <cstdio>
#include <cstdlib>

using namespace oe;

IMPLEMENT_SUBCLASS(Display, "TestIoDisplay")

BEGIN_SLOTTABLE(Display)
   "ioHandler",   // 1: I/O data handler
   "item",        // 2: Item number [ 1 ... TBL_SIZE ]
   "di",          // 3: DI channel number for last 'item'
   "ai",          // 4: AI channel number for last 'item'
   "label"        // 5: (optional) Label
END_SLOTTABLE(Display)

BEGIN_SLOT_MAP(Display)
    ON_SLOT(1, setSlotIoHandler, base::IoHandler)
    ON_SLOT(2, setSlotItem,      base::Number)
    ON_SLOT(3, setSlotDiChannel, base::Number)
    ON_SLOT(4, setSlotAiChannel, base::Number)
    ON_SLOT(5, setSlotLabel,     base::String)
END_SLOT_MAP()

Display::Display()
{
   STANDARD_CONSTRUCTOR()
   initData();
}

void Display::initData()
{
   ioHandler = nullptr;

   // Item/Channel mapping
   for (unsigned int i = 0; i < TBL_SIZE; i++) {
      types[i] = Type::NONE;
   }

   // Display buffers
   for (unsigned int i = 0; i < TBL_SIZE; i++) {
      table_typeRo[i] = R_BLANK;
      table_Label[i] = labelBuffs[i];
   }

}

void Display::copyData(const Display& org, const bool cc)
{
   BaseClass::copyData(org);
   if (cc) initData();

   if (org.ioHandler != nullptr) {
      base::IoHandler* copy = org.ioHandler->clone();
      setSlotIoHandler(copy);
      copy->unref();
   }
   else setSlotIoHandler(nullptr);

   // Item/Channel mapping
   for (unsigned int i = 0; i < TBL_SIZE; i++) {
      types[i] = org.types[i];
      channels[i] = org.channels[i];
      labelFlags[i] = org.labelFlags[i];
      base::utStrcpy(labels[i], sizeof(labels[i]), org.labels[i]);
      base::utStrcpy(labelBuffs[i], sizeof(labelBuffs[i]), org.labelBuffs[i]);
   }
   item = org.item;

   // Display buffers
   for (unsigned int i = 0; i < TBL_SIZE; i++) {
      table_typeRo[i] = org.table_typeRo[i];
      table_Label[i] = labelBuffs[i];
      table_ai[i] = org.table_ai[i];
   }
}

void Display::deleteData()
{
   setSlotIoHandler(nullptr);
}

//-----------------------------------------------------------------------------
// onEscKey() - from event handler
//-----------------------------------------------------------------------------
bool Display::onEscKey()
{
   std::cout<<"Display::onEscKey() -- Exit by the ESC key!"<<std::endl;
   std::exit(EXIT_FAILURE);
}

void Display::reset()
{
   BaseClass::reset();
   setNormColor( getColor("NormalText") );
   setHighlightColor( getColor("HighlightText") );

   // Reset the I/O Handler
   if (ioHandler != nullptr) {
      ioHandler->event(RESET_EVENT);
   }
}

void Display::updateTC(const double dt)
{
   // I/O Handler
   if (ioHandler != nullptr) {
      ioHandler->inputDevices(dt);
      //ioHandler->updateTC(dt);
      ioHandler->outputDevices(dt);
   }

   BaseClass::updateTC(dt);
}

void Display::updateData(const double dt)
{
   // I/O Handler
   if (ioHandler != nullptr) {
      //ioHandler->updateData(dt);
   }

   // Update the display buffers
   updateDisplay();

   // Left column (column1)
   {
      unsigned int idx = 0;
      send( "column1.%d.label",   UPDATE_VALUE,   &table_Label[idx],     &table_LabelSD[idx],     ROWS );
      send( "column1.%d.typeRo",  SELECT,         &table_typeRo[idx],    &table_typeRoSD[idx],    ROWS );
      send( "column1.%d.typeRo.ai", UPDATE_VALUE, &table_ai[idx],       &table_aiSD[idx],        ROWS );
   }

   // Center column (column2)
   {
      unsigned int idx = ROWS;
      send( "column2.%d.label",   UPDATE_VALUE,   &table_Label[idx],     &table_LabelSD[idx],     ROWS );
      send( "column2.%d.typeRo",  SELECT,         &table_typeRo[idx],    &table_typeRoSD[idx],    ROWS );
      send( "column2.%d.typeRo.ai", UPDATE_VALUE, &table_ai[idx],       &table_aiSD[idx],        ROWS );
   }

   // Right column (column3)
   {
      unsigned int idx = ROWS*2;
      send( "column3.%d.label",   UPDATE_VALUE,   &table_Label[idx],     &table_LabelSD[idx],     ROWS );
      send( "column3.%d.typeRo",  SELECT,         &table_typeRo[idx],    &table_typeRoSD[idx],    ROWS );
      send( "column3.%d.typeRo.ai", UPDATE_VALUE, &table_ai[idx],       &table_aiSD[idx],        ROWS );
   }

   BaseClass::updateData(dt);
}

void Display::updateDisplay()
{
   base::IoData* ioData = nullptr;
   if (ioHandler != nullptr) ioData = ioHandler->getInputData();

   // Item/channel mapping
   for (unsigned int i = 0; i < TBL_SIZE; i++) {

      bool ok = false;

      if (types[i] != Type::NONE && ioData != nullptr) {

         // Set the data
         if (types[i] == Type::AI) {
            double v = 0;
            ok = ioData->getAnalogInput(channels[i], &v);
            if (ok) {
               table_ai[i] = v;
               table_typeRo[i] = R_AI;
            }
         }
         else if (types[i] == Type::DI) {
            bool flg = false;
            ok = ioData->getDiscreteInput(channels[i], &flg);
            if (ok) {
               if (flg) table_typeRo[i] = R_DI_1;
               else table_typeRo[i] = R_DI_0;
            }
         }

         // Create the label
         {
            // if not provided; make the default label
            if (!labelFlags[i]) {
               char cbuff[32];
               if (types[i] == Type::AI) std::sprintf(cbuff, "AI(%03d)", channels[i]);
               else                std::sprintf(cbuff, "DI(%03d)", channels[i]);
               base::utStrcpy(labels[i], sizeof(labels[i]), cbuff);
            }

            // copy the label with a ':'
            base::utStrcpy(labelBuffs[i], sizeof(labelBuffs[i]), labels[i]);
            base::utStrcat(labelBuffs[i], sizeof(labelBuffs[i]), ":");
         }

      }

      if (!ok) {
         table_ai[i] = 0;
      }

   }
}

//------------------------------------------------------------------------------
// Slot functions
//------------------------------------------------------------------------------

bool Display::setSlotIoHandler(base::IoHandler* const msg)
{
   if (ioHandler != nullptr) {
      ioHandler->container(nullptr);
   }
   ioHandler = msg;
   if (ioHandler != nullptr) {
      ioHandler->container(this);
   }
   return true;
}

bool Display::setSlotItem(const base::Number* const msg)
{
   bool ok = false;
   if (msg != nullptr) {
      int v = msg->getInt();
      if (v >= 1 && v <= TBL_SIZE) {
         item = static_cast<unsigned short>(v);
         types[item-1] = Type::NONE;
         channels[item-1] = 0;
         ok = true;
      }
      else {
         std::cerr << "Display::setSlotItem(): Invalid 'item' number, range: [ 1 ... " << TBL_SIZE << " ]" << std::endl;
      }
   }
   return ok;
}

bool Display::setSlotAiChannel(const base::Number* const msg)
{
   bool ok = false;
   if (msg != nullptr && item >= 1 && item <= TBL_SIZE) {
      int v = msg->getInt();
      if (v >= 0 && v <= 0xFFFF) {
         channels[item-1] = static_cast<unsigned short>(v);
         types[item-1] = Type::AI;
         ok = true;
      }
   }
   else {
      std::cerr << "Display::setSlotAiChannel(): Invalid item number; set using slot 'item'" << std::endl;
   }
   return ok;
}

bool Display::setSlotDiChannel(const base::Number* const msg)
{
   bool ok = false;
   if (msg != nullptr && item >= 1 && item <= TBL_SIZE) {
      int v = msg->getInt();
      if (v >= 0 && v <= 0xFFFF) {
         channels[item-1] = static_cast<unsigned short>(v);
         types[item-1] = Type::DI;
         ok = true;
      }
   }
   else {
      std::cerr << "Display::setSlotAiChannel(): Invalid item number; set using slot 'item'" << std::endl;
   }
   return ok;
}

bool Display::setSlotLabel(const base::String* const msg)
{
   bool ok = false;
   if (item >= 1 && item <= TBL_SIZE) {
      if (msg != nullptr) {
         utStrcpy(labels[item-1], sizeof(labels[item-1]), *msg);
         labelFlags[item-1] = true;
      }
      else {
         labelFlags[item-1] = false;
      }
      ok = true;
   }
   else {
      std::cerr << "Display::setSlotAiChannel(): Invalid item number; set using slot 'item'" << std::endl;
   }
   return ok;
}

std::ostream& Display::serialize(std::ostream& sout, const int i, const bool slotsOnly) const
{
   int j = 0;
   if ( !slotsOnly ) {
      indent(sout,i);
      sout << "( " << getFactoryName() << std::endl;
      j = 4;
   }

   // I/O handlers
   if (ioHandler != nullptr) {
      indent(sout,i+j);
      sout << "ioHandler: " << std::endl;
      ioHandler->serialize(sout,i+j+4);
   }

   // Item/channel mapping
   for (unsigned int idx = 0; idx < TBL_SIZE; idx++) {
      if (types[idx] != Type::NONE) {
         indent(sout,i+j);
         sout << "item: " << (idx+1) << "   ";
         if (types[idx] == Type::AI) {
            sout << "ai: ";
         }
         else if (types[idx] == Type::DI) {
            sout << "di: ";
         }
         sout << channels[idx] << std::endl;
      }
   }

   if ( !slotsOnly ) {
      indent(sout,i);
      sout << ")" << std::endl;
   }

   return sout;
}
