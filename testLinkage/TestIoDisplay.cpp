
#include "TestIoDisplay.hpp"

#include "mixr/base/concepts/linkage/AbstractIoData.hpp"
#include "mixr/base/concepts/linkage/AbstractIoHandler.hpp"
#include "mixr/base/numeric/Number.hpp"
#include "mixr/base/String.hpp"

#include <cstdio>
#include <cstdlib>

using namespace mixr;

IMPLEMENT_SUBCLASS(TestIoDisplay, "TestIoDisplay")
EMPTY_DELETEDATA(TestIoDisplay)

BEGIN_SLOTTABLE(TestIoDisplay)
   "ioHandler",   // 1: I/O data handler
   "item",        // 2: Item number [ 1 ... TBL_SIZE ]
   "di",          // 3: DI channel number for last 'item'
   "ai",          // 4: AI channel number for last 'item'
   "label"        // 5: (optional) Label
END_SLOTTABLE(TestIoDisplay)

BEGIN_SLOT_MAP(TestIoDisplay)
    ON_SLOT(1, setSlotIoHandler, base::AbstractIoHandler)
    ON_SLOT(2, setSlotItem,      base::Number)
    ON_SLOT(3, setSlotDiChannel, base::Number)
    ON_SLOT(4, setSlotAiChannel, base::Number)
    ON_SLOT(5, setSlotLabel,     base::String)
END_SLOT_MAP()

TestIoDisplay::TestIoDisplay()
{
   STANDARD_CONSTRUCTOR()
   initData();
}

void TestIoDisplay::initData()
{
   // Display buffers
   for (int i = 0; i < TBL_SIZE; i++) {
      table_typeRo[i] = R_BLANK;
      table_Label[i] = labelBuffs[i].c_str();
   }
}

void TestIoDisplay::copyData(const TestIoDisplay& org, const bool cc)
{
   BaseClass::copyData(org);
   if (cc) initData();

   if (org.ioHandler != nullptr) {
      base::AbstractIoHandler* copy = org.ioHandler->clone();
      setSlotIoHandler(copy);
      copy->unref();
   } else {
      setSlotIoHandler(nullptr);
   }

   // Item/Channel mapping
   types = org.types;
   channels = org.channels;
   labelFlags = org.labelFlags;
   labels = org.labels;
   labelBuffs = org.labelBuffs;
   item = org.item;

   // Display buffers
   for (int i = 0; i < TBL_SIZE; i++) {
      table_typeRo[i] = org.table_typeRo[i];
      table_Label[i] = labelBuffs[i].c_str();
      table_ai[i] = org.table_ai[i];
   }
}

//-----------------------------------------------------------------------------
// onEscKey() - from event handler
//-----------------------------------------------------------------------------
bool TestIoDisplay::onEscKey()
{
   std::cout<<"Display::onEscKey() -- Exit by the ESC key!"<<std::endl;
   std::exit(EXIT_FAILURE);
}

void TestIoDisplay::reset()
{
   BaseClass::reset();
   setNormColor( getColor("NormalText") );
   setHighlightColor( getColor("HighlightText") );

   // Reset the I/O Handler
   if (ioHandler != nullptr) {
      ioHandler->event(RESET_EVENT);
   }
}

void TestIoDisplay::updateTC(const double dt)
{
   // I/O Handler
   if (ioHandler != nullptr) {
      ioHandler->inputDevices(dt);
      //ioHandler->updateTC(dt);
      ioHandler->outputDevices(dt);
   }

   BaseClass::updateTC(dt);
}

void TestIoDisplay::updateData(const double dt)
{
   // I/O Handler
   if (ioHandler != nullptr) {
      //ioHandler->updateData(dt);
   }

   // Update the display buffers
   updateDisplay();

   // Left column (column1)
   {
      int idx{};
      send( "column1.%d.label",   UPDATE_VALUE,   &table_Label[idx],     &table_LabelSD[idx],     ROWS );
      send( "column1.%d.typeRo",  SELECT,         &table_typeRo[idx],    &table_typeRoSD[idx],    ROWS );
      send( "column1.%d.typeRo.ai", UPDATE_VALUE, &table_ai[idx],       &table_aiSD[idx],        ROWS );
   }

   // Center column (column2)
   {
      int idx{ROWS};
      send( "column2.%d.label",   UPDATE_VALUE,   &table_Label[idx],     &table_LabelSD[idx],     ROWS );
      send( "column2.%d.typeRo",  SELECT,         &table_typeRo[idx],    &table_typeRoSD[idx],    ROWS );
      send( "column2.%d.typeRo.ai", UPDATE_VALUE, &table_ai[idx],       &table_aiSD[idx],        ROWS );
   }

   // Right column (column3)
   {
      int idx{ROWS*2};
      send( "column3.%d.label",   UPDATE_VALUE,   &table_Label[idx],     &table_LabelSD[idx],     ROWS );
      send( "column3.%d.typeRo",  SELECT,         &table_typeRo[idx],    &table_typeRoSD[idx],    ROWS );
      send( "column3.%d.typeRo.ai", UPDATE_VALUE, &table_ai[idx],       &table_aiSD[idx],        ROWS );
   }

   BaseClass::updateData(dt);
}

void TestIoDisplay::updateDisplay()
{
   base::AbstractIoData* ioData{};
   if (ioHandler != nullptr) ioData = ioHandler->getInputData();

   // Item/channel mapping
   for (int i = 0; i < TBL_SIZE; i++) {

      bool ok{};

      if (types[i] != Type::NONE && ioData != nullptr) {

         // Set the data
         if (types[i] == Type::AI) {
            double v{};
            ok = ioData->getAnalogInput(channels[i], &v);
            if (ok) {
               table_ai[i] = v;
               table_typeRo[i] = R_AI;
            }
         } else if (types[i] == Type::DI) {
            bool flg{};
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

               char cbuff[32]{};
               if (types[i] == Type::AI)
                  std::sprintf(cbuff, "AI(%03d)", channels[i]);
               else
                  std::sprintf(cbuff, "DI(%03d)", channels[i]);

               labels.at(i) = cbuff;
//               base::utStrcpy(labels[i], sizeof(labels[i]), cbuff);

            }

            // copy the label with a ':'
            labelBuffs[i] = labels[i] + ":";
         }

      }

      if (!ok) {
         table_ai[i] = 0;
      }

   }
}

bool TestIoDisplay::setSlotIoHandler(base::AbstractIoHandler* const msg)
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

bool TestIoDisplay::setSlotItem(const base::Number* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      const int v{msg->getInt()};
      if (v >= 1 && v <= TBL_SIZE) {
         item = v;
         types[item-1] = Type::NONE;
         channels[item-1] = 0;
         ok = true;
      } else {
         std::cerr << "TestIoDisplay::setSlotItem(): Invalid 'item' number, range: [ 1 ... " << TBL_SIZE << " ]" << std::endl;
      }
   }
   return ok;
}

bool TestIoDisplay::setSlotAiChannel(const base::Number* const msg)
{
   bool ok{};
   if (msg != nullptr && item >= 1 && item <= TBL_SIZE) {
      const int v{msg->getInt()};
      if (v >= 0 && v <= 0xFFFF) {
         channels[item-1] = v;
         types[item-1] = Type::AI;
         ok = true;
      }
   } else {
      std::cerr << "TestIoDisplay::setSlotAiChannel(): Invalid item number; set using slot 'item'" << std::endl;
   }
   return ok;
}

bool TestIoDisplay::setSlotDiChannel(const base::Number* const msg)
{
   bool ok{};
   if (msg != nullptr && item >= 1 && item <= TBL_SIZE) {
      const int v{msg->getInt()};
      if (v >= 0 && v <= 0xFFFF) {
         channels[item-1] = v;
         types[item-1] = Type::DI;
         ok = true;
      }
   } else {
      std::cerr << "TestIoDisplay::setSlotAiChannel(): Invalid item number; set using slot 'item'" << std::endl;
   }
   return ok;
}

bool TestIoDisplay::setSlotLabel(const base::String* const msg)
{
   bool ok{};
   if (item >= 1 && item <= TBL_SIZE) {
      if (msg != nullptr) {
         labels[item-1] = *msg;
         labelFlags[item-1] = true;
      } else {
         labelFlags[item-1] = false;
      }
      ok = true;
   } else {
      std::cerr << "TestIoDisplay::setSlotAiChannel(): Invalid item number; set using slot 'item'" << std::endl;
   }
   return ok;
}

