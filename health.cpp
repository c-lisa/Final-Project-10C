#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //1. Initialize health to 3
    health = 3;

    //2. Draw text.
    setPlainText(QString("Health: ") + QString::number(health)); //will look like Score: 0

    //3. Make it prettier: set color, set font type & size
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16)); //font and size
}

void Health::decrease()
{
   --health;
   setPlainText(QString("Health: ") + QString::number(health)); //will look like Score: 0
}

int Health::getHealth()
{
    return health;
}
