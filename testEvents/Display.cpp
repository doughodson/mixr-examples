
#include "Display.hpp"
#include "TestObject.hpp"

#include "mixr/base/colors/Color.hpp"

#include "mixr/base/numbers/Number.hpp"

#include "mixr/base/util/math_utils.hpp"
#include "mixr/base/util/system_utils.hpp"

#include "mixr/graphics/Material.hpp"

#include <random>
#include <cstring>
#include <array>

using namespace mixr;

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(Display, "SendDataDisplay")
EMPTY_SERIALIZER(Display)

Display::Display()
{
    STANDARD_CONSTRUCTOR()

    obj = new TestObject();
    myColor = new base::Color();
    myColor->setRed(0.0);
    myColor->setBlue(0.0);
    myColor->setGreen(0.0);

    std::array<base::Vec4d, MAX_MATERIALS> diffColor;

    std::random_device rd;                       // used to generate random seed for generator
    std::mt19937 gen(rd());                      // mersenne_twister_engine
    std::uniform_real_distribution<double> dis(0, 1);  // uniform distribution from [0, 1)

    for (unsigned int i = 0; i < MAX_MATERIALS; i++) {
        materials[i] = new graphics::Material();
        materialSD[i].empty();
        diffColor[i].set(dis(gen), dis(gen), dis(gen), 1);
        //std::cout << "DIFF COLOR = " << diffColor[i].x() << ", " << diffColor[i].y() << ", " << diffColor[i].z() << std::endl;
        materials[i]->setDiffuseColor(diffColor[i]);
        // set up initial different colors
        diffColorRate[i].set(1,1,1);
        rotations[i] = 0.0;
        rotationsSD[i].empty();
    }
}

void Display::copyData(const Display& org, const bool)
{
    BaseClass::copyData(org);

    myBool = org.myBool;
    boolSD.empty();
    myInt = org.myInt;
    intSD.empty();
    myFloat = org.myFloat;
    floatSD.empty();
    myDouble = org.myDouble;
    doubleSD.empty();
    if (obj != nullptr) obj->unref();
    if (org.obj != nullptr) {
        obj = org.obj->clone();
    }
    if (myColor != nullptr) myColor->unref();
    if (org.myColor != nullptr) {
        myColor = org.myColor->clone();
    }

    for (int i = 0; i < MAX_MATERIALS; i++) {
        if (materials[i] != nullptr) {
            materials[i]->unref();
            materials[i] = nullptr;
        }
        diffColorRate[i] = org.diffColorRate[i];
        if (org.materials[i] != nullptr) materials[i] = org.materials[i]->clone();
        materialSD[i].empty();
        rotations[i] = org.rotations[i];
        rotationsSD[i].empty();
    }

    myChar = org.myChar;

    counter = org.counter;
}

void Display::deleteData()
{
    if (obj != nullptr) {
        obj->unref();
        obj = nullptr;
    }
    if (myColor != nullptr) {
        myColor->unref();
        myColor = nullptr;
    }
    for (int i = 0; i < MAX_MATERIALS; i++) {
        if (materials[i] != nullptr) {
            materials[i]->unref();
            materials[i] = nullptr;
        }
    }
}

void Display::updateData(const double dt)
{
    BaseClass::updateData(dt);

    counter++;
    if (counter > 1) {
        myBool = !myBool;

        myInt++;
        if (myInt > 999) myInt = 0;

        myFloat += 0.002f;
        if (myFloat > 100) myFloat = 0;

        myDouble += 0.00002f;
        if (myDouble > 2) myDouble = 0;

        if (myChar == "ASCII") {
           myChar = "TEXT";
        } else {
           myChar = "ASCII";
        }

        obj->setBoolean(!obj->getBoolean());
        obj->setInteger(obj->getInteger() + 1);
        obj->setFloat(obj->getFloat() + 0.01f);
        obj->setDouble(obj->getDouble() + 0.0003);
        obj->setReal(obj->getReal() + 0.1f);
        if (obj->getChar() == "ASCII") {
            obj->setChar("TEXT");
        } else {
            obj->setChar("ASCII");
        }
        if (myColor->red() < 0.9f) myColor->setRed(myColor->red() + dt);
        else myColor->setRed(0.0f);
        if (myColor->blue() < 0.9f) myColor->setBlue(myColor->blue() + (2 * dt));
        else myColor->setBlue(0.0);
        if (myColor->green() < 0.9f) myColor->setGreen(myColor->green() + (3 * dt));
        else myColor->setGreen(0.0);

        // our materials
        base::Vec4d diff;
        double x = 0, y = 0, z = 0;
        for (int i = 0; i < MAX_MATERIALS; i++) {
            if (materials[i] != nullptr) {
                if (i == 0) {
                    diff = materials[i]->getDiffuseColor();
                    rotations[i] += 40 * dt;
                }
                else if (i == 1) {
                    diff = materials[i]->getAmbientColor();
                    rotations[i] -= 45 * dt;
                }
                else if (i == 2) {
                    diff = materials[i]->getEmissiveColor();
                    rotations[i] += 30 * dt;
                }
                x = diff.x();
                y = diff.y();
                z = diff.z();
                if (x > 1 || x < 0) diffColorRate[i].x() = -diffColorRate[i].x();
                x += diffColorRate[i].x() * 0.01f;
                if (y > 1 || y < 0) diffColorRate[i].y() = -diffColorRate[i].y();
                y += diffColorRate[i].y() * 0.02f;
                if (z > 1 || z < 0) diffColorRate[i].z() = -diffColorRate[i].z();
                z += diffColorRate[i].z() * 0.025f;
                diff.set(x,y,z,1);
                if (i == 0) materials[i]->setDiffuseColor(diff);
                else if (i == 1) materials[i]->setAmbientColor(diff);
            }
        }

        counter = 0;
    }


    send("boolean", UPDATE_VALUE, myBool, boolSD);
    send("integer", UPDATE_VALUE, myInt, intSD);
    send("float", UPDATE_VALUE, myFloat, floatSD);
    send("double", UPDATE_VALUE, myDouble, doubleSD);
    send("ascii", UPDATE_VALUE, myChar.c_str(), charSD);
    send("objtest", UPDATE_VALUE, obj, objSD);
    send("colors", SET_COLOR, myColor, colorSD);
    // convert materials to objects real quick, so we can send them down
    base::Object* tempMat[MAX_MATERIALS];
    for (int i = 0; i < MAX_MATERIALS; i++) {
        tempMat[i] = static_cast<base::Object*>(materials[i]);
    }
    send("matarray%d", SET_MATERIAL, tempMat, materialSD.data(), MAX_MATERIALS);
    // send rotations to our objects as well
    send("rotators%d", UPDATE_VALUE2, rotations.data(), rotationsSD.data(), MAX_MATERIALS);
}
