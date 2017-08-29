
#include "SpdLines.hpp"
#include "mixr/base/numeric/Number.hpp"
#include <iostream>

using namespace mixr;

IMPLEMENT_SUBCLASS(SpdLines, "SpdLines")
EMPTY_DELETEDATA(SpdLines)

BEGIN_EVENT_HANDLER(SpdLines)
    ON_EVENT_OBJ(UPDATE_VALUE, onEventSetIsAltSpdLines, base::Number)
END_EVENT_HANDLER()

BEGIN_SLOTTABLE(SpdLines)
    "isAlt",              // draw for the altitude scale (instead of making a new class)
END_SLOTTABLE(SpdLines)

BEGIN_SLOT_MAP(SpdLines)
    ON_SLOT(1, setSlotIsAlt, base::Number)
END_SLOT_MAP()

SpdLines::SpdLines()
{
    STANDARD_CONSTRUCTOR()
}

void SpdLines::copyData(const SpdLines& org, const bool)
{
    BaseClass::copyData(org);
    isAlt = org.isAlt;
}

void SpdLines::drawFunc()
{
    GLfloat ocolor[4];
    GLfloat lw;
    glGetFloatv(GL_CURRENT_COLOR, ocolor);
    glGetFloatv(GL_LINE_WIDTH, &lw);

    BEGIN_DLIST

        if (!isAlt) {
            double startPoint = 0;
            // now step through and draw all the lines (100 of them)
            // draw the big lines first
            glLineWidth(2);
            for (int i = 0; i < 51; i++) {
                glPushMatrix();
                    glBegin(GL_LINES);
                        lcVertex2(0.6f, startPoint);
                        lcVertex2(0.48f, startPoint);
                    glEnd();
                glPopMatrix();
                // move up to the next line
                startPoint += 0.9f;
            }
            // now draw the small lines
            startPoint = 0.45f;
            for (int i = 0; i < 50; i++) {
                glPushMatrix();
                    glBegin(GL_LINES);
                        lcVertex2(0.6f, startPoint);
                        lcVertex2(0.52f, startPoint);
                    glEnd();
                glPopMatrix();
                // move up to the next line
                startPoint += 0.9f;
            }

            glLineWidth(1);
            glColor3f(0.1f, 0.1f, 0.1f);

            // make the polygon last
            glPushMatrix();
                glBegin(GL_POLYGON);
                    glVertex2f(0, 1500);
                    glVertex2f(0, -1500);
                    glVertex2f(0.6f, -1500);
                    glVertex2f(0.6f, 1500);
                glEnd();
            glPopMatrix();
        }
        else {
            double startPoint = 0;
            // now step through and draw all the lines (approx 280 of them, gets us to about 55,800 feet)
            // draw the big lines first
            glLineWidth(2);
            for (int i = 0; i < 281; i++) {
                glPushMatrix();
                    glBegin(GL_LINES);
                        lcVertex2(0, startPoint);
                        lcVertex2(0.12f, startPoint);
                    glEnd();
                glPopMatrix();
                // move up to the next line
                startPoint += 0.9f;
            }
            // now draw the small lines
            startPoint = 0.45f;
            for (int i = 0; i < 280; i++) {
                glPushMatrix();
                    glBegin(GL_LINES);
                        lcVertex2(0, startPoint);
                        lcVertex2(0.08f, startPoint);
                    glEnd();
                glPopMatrix();
                // move up to the next line
                startPoint += 0.9f;
            }

            glLineWidth(1);
            glColor3f(0.1f, 0.1f, 0.1f);

            // make the polygon last
            glPushMatrix();
                glBegin(GL_POLYGON);
                    glVertex2f(0, 1500);
                    glVertex2f(0, -1500);
                    glVertex2f(0.879f, -1500);
                    glVertex2f(0.879f, 1500);
                glEnd();
            glPopMatrix();
        }
    END_DLIST

    glColor4fv(ocolor);
    glLineWidth(lw);
}

// Event function
bool SpdLines::onEventSetIsAltSpdLines(const base::Number* const x)
{
    bool ok = false;
    if (x != nullptr) ok = setIsAlt(x->getBoolean());
    return ok;
}

//------------------------------------------------------------------------------
// sets our altitude flag
//------------------------------------------------------------------------------
bool SpdLines::setSlotIsAlt(const base::Number* const newAltFlag)
{
    bool ok = false;
    if (newAltFlag != nullptr) ok = setIsAlt(newAltFlag->getBoolean());
    return ok;
}

