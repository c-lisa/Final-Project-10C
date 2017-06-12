#include "bullet.h"
#include <QGraphicsScene>
#include "game.h"
#include <QTimer>
#include "externalobject.h"
#include <QList>
#include <typeinfo>

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //Draw bullet
    setPixmap(QPixmap(":/Images/Bullet.png"));

    //Create timer for bullet to run
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer-> start(50);
}

void Bullet::move()
{
    /*
    Possibilities:
    1. Bullet collides with enemy - destroy both
    2. Bullet off screen
    */
    setPos(x(), y()-10); //move up by 10

    //1
    QList<QGraphicsItem* > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i]))== typeid(Enemy))
        {
            //increase score
            game -> score -> increase();

            scene() -> removeItem(colliding_items[i]);
            scene() -> removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
    }


    //2
    if (pos().y() + pixmap().height() < 0)
    {
        scene() -> removeItem(this);
        delete this;
    }

}
