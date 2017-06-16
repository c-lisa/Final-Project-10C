#include "externalobject.h"
#include <QGraphicsScene>
#include "game.h"
#include <QTimer>
#include "stdlib.h"
#include <QList>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), enemy_speed(100)
{
    //Create enemy
    int random_number = rand()%800;
    setPos(random_number, 0);
    setPixmap(QPixmap(":/Images/Enemy Plane.png"));

    //lambda function
    auto inc_enemy_speed = [](int val){
        if((val >= 25) && (val%(25) == 0))
        {
            return true;
        }
        else return false;
    };

    //Increasing speed of enemy
    if(inc_enemy_speed(game->score->getScore()))
    {
        enemy_speed-=15;
    }

    //Get enemy to move
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer-> start(enemy_speed);

}

void Enemy::move()
{
    setPos(x(), y() + 7); //slower than bullets

    //Check if off screen
    if (pos().y() - pixmap().height() > 700 )
    {
        game -> health -> decrease();
        scene()-> removeItem(this);
        delete this;
    }

}
