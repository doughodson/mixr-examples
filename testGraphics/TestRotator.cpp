
#include "TestRotator.hpp"
#include "mixr/base/units/angle_utils.hpp"

#include <GL/glu.h>
#include <GL/glut.h>

using namespace mixr;

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(TestRotator, "TestRotator")
EMPTY_DELETEDATA(TestRotator)

TestRotator::TestRotator()
{
    STANDARD_CONSTRUCTOR()
    light_position[0] = 1;
    light_position[1] = 1;
    light_position[2] = 1;
    light_position[3] = 0;
}

void TestRotator::copyData(const TestRotator& org, const bool)
{
    BaseClass::copyData(org);
    t1Pos = org.t1Pos;
    t1Rate = org.t1Rate;
}

void TestRotator::drawFunc()
{
    GLfloat currentColor[4]{};
    glGetFloatv(GL_CURRENT_COLOR, currentColor);
    //count++;
    //std::cout << "Count = " << count << std::endl;

    //GLfloat mat_specular[] = { 0, 0, 0, 1 };
    //GLfloat mat_shininess[] = { 50 };
    ////GLfloat mat_emission[] = { t1Pos, t2Pos, t3Pos, 0 };
    //GLfloat white_light[] = {1, 1, 1, 1 };
    ////GLfloat lmodel_ambient[] = { t1Pos, t2Pos, t3Pos, 1.0 };
    //GLfloat lmodel_ambient[] = { 1, 1, 1, 1.0 };
    ////GLfloat mat_amb_diff[] = { t1Pos, t2Pos, t3Pos, 0 };
    //GLfloat mat_amb_diff[] = { 1, 1, 1, 1 };

    //glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    //glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    //glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);

    glPushMatrix();

         //glTranslatef(0, rotate / 75, 0);
         //glRotatef(rotate / 2, 1, 1, 1);
         glutSolidTeapot(5);
    glPopMatrix();

    // after we are finished, disable our lighting.
    //glDisable(GL_LIGHTING);
    //glDisable(GL_LIGHT0);

    glColor4fv(currentColor);

}

void TestRotator::updateData(const double dt)
{
    BaseClass::updateData(dt);

    t1Pos += t1Rate * dt;
    t2Pos += t2Rate * dt;
    t3Pos += t3Rate * dt;
    rotate += rotateRate * dt;
    if (t1Pos > 2) {
        t1Pos = 2;
        t1Rate = -t1Rate;
    }
    if (t1Pos < -2) {
        t1Pos = -2;
        t1Rate = -t1Rate;
    }
    if (t2Pos > 2) {
        t2Pos = 2;
        t2Rate = -t2Rate;
    }
    if (t2Pos < -2) {
        t2Pos = -2;
        t2Rate = -t2Rate;
    }
    if (t3Pos > 2) {
        t3Pos = 2;
        t3Rate = -t3Rate;
    }
    if (t3Pos < -2) {
        t3Pos = -2;
        t3Rate = -t3Rate;
    }
    //if (rotate > 360) {
    //    rotate = 360;
    //    rotateRate = -rotateRate;
    //}
    //if (rotate < -360) {
    //    rotate = -360;
    //    rotateRate = -rotateRate;
    //}

    light_position[0] = static_cast<GLfloat>(std::cos(rotate * base::angle::D2RCC));
    light_position[1] = static_cast<GLfloat>(std::sin(rotate * base::angle::D2RCC));
    light_position[2] = static_cast<GLfloat>(std::sin(rotate * base::angle::D2RCC));
    light_position[3] = 0;
}
