#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "stdlib.h"
#include "game.h"
#include "QDebug"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //1. CREATE ENEMY
    int random_number = rand()%700; //set random #
    setPos(random_number, 0); //set random position
    /*
    setBrush(Qt::red);

    //Default of QGraphicsRectItem is (x, y, length = 0, width = 0)
    setRect(0,0,100,100);
    */
    setPixmap(QPixmap(":/Images/resized_watermelon.jpg"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    //2. ADD BULLET TO SCENE - go to myrect.cpp (aka player)
    //3. CONNECT BULLET TO MOVE - set time and when it goes to 0 (aka timeout), it will move bullet
    //every 50 milliseconds, move bullet
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer-> start(50);
}

void Enemy::move()
{
   //CONDITION 1: move down. add 5 to y() to go slower than bullets
   setPos(x(), y() + 5);

   //CONDIITON 2: check if off screen, add height of bullet to delete when it hits bottom right
   if(pos().y() > 600)
   {
       game -> health -> decrease();
       scene() -> removeItem(this);
       delete this;
       qDebug() << "deleted enemy";
   }
}
