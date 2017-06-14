#include "intro.h"

Intro::Intro(QGraphicsItem *parent)
{
    introgiven = true;

    //give premise for game
    setPlainText(QString("Commander Little Hippo needs to defend the animal kingdom. Help him destroy all the enemy ships. [Press spacebar to continue]");
    setDefaultTextColor(Qt::black);
    setFont(QFont("arial", 16));
}

void Intro::give_directions()
{
    introgiven = false;

    //give premise for game
    setPlainText(QString("Press left and right arrow keys to move horizontally. Press space to shoot. Press escape key anytime to exit. [Press spacebar to continue]");
    setDefaultTextColor(Qt::black);
    setFont(QFont("arial", 16));
}

void Intro::keyPressEvent(QKeyEvent *event)
{
    if (event -> key() == Qt::Key_Space)
    {
        if (introgiven)
        {
            give_directions();
        }
        else
        {
            setPlainText(void);
        }
    }
}

