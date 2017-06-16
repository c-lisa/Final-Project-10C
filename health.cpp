#include "health.h"
#include <QFont>
#include "game.h"

extern Game * game;

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //set health to initial value
    health = 3;

    //draw health text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("arial", 16));
}

void Health::decrease()
{
    --health;
    displayHealth();
    if (health == 0)
    {
        emit dead();
    }
}

void Health::increase()
{
    ++health;
    displayHealth();
}

int Health::getHealth()
{
    return health;
}

void Health::displayHealth()
{
    setPlainText(QString("Health: ") + QString::number(health));
}


