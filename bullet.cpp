#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "game.h"

extern Game * game; //there is external global object called Game

Bullet::Bullet(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent)
{
        //1. Set size of Bullet (length, width)
        setRect(0,0,10,50);
        setBrush(Qt::yellow);

        //2. Add bullet to the scene by going to myrect.cpp (aka Player's file)
        //3. Move the bullet by connecting it to a timer. Everytime the time goes to 0 (aka it times out), it will move.
        //Set timer to 50 milliseconds (aka every 50 milliseconds, the bullet will move).
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer-> start(50);
}

void Bullet::move()
{
    //CONDITION 1: if bullet collides with enemy, destroy both
    QList<QGraphicsItem* > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if (typeid (*(colliding_items[i])) == typeid(Enemy))
        {
            //increase the score
            game->score->increase();

            //remove both
            scene() -> removeItem(colliding_items[i]);
            scene() -> removeItem(this);

            //delete object on heap
            delete colliding_items[i];
            delete this;
            return; //so the below code doesn't run and you access released memory
        }
    }

    //CONDITION 2: Just move bullet.
    setPos(x(), y() - 10); //move up by subtracting 10

    //CONDITION 3: off screen - add height of bullet to delete right when it hits bottom right
    if(pos().y() + rect().height() < 0)
    {
        scene() -> removeItem(this);
        delete this;
    }
}
