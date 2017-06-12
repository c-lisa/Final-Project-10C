#include "externalobject.h"
#include <QGraphicsScene>
#include "game.h"
#include <QTimer>
#include "stdlib.h"
#include <QList>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //Create enemy
    int random_number = rand()%800;
    setPos(random_number, 0);
    setPixmap(QPixmap(":/Images/Enemy Plane.png"));

    //Get enemy to move
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer-> start(100);
}

void Enemy::move()
{
    setPos(x(), y() + 7); //slower than bullets

    //Check if off screen
    if (pos().y() - pixmap().height() > 800 )
    {
        game -> health -> decrease();
        scene()-> removeItem(this);
        delete this;
    }

}
