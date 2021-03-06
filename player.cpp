#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "externalobject.h"
#include "bullet.h"

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    //Draw Player
    setPixmap(QPixmap(":/Images/LittleHippo.png"));

    //Initialize bullet sound
    bulletsound = new QMediaPlayer();
    bulletsound -> setMedia(QUrl("qrc:/Sound/Bullet Ricochet.mp3"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //Only want to move left, right, and allow space bar to be clicked
    if (event->key() == Qt::Key_Left)   {
        if (pos().x() > 0)
        {
            setPos(x()-10, y()); //keep current y but move x to the left
        }
    }
    else if (event->key() == Qt::Key_Right)    {
        if (pos().x() + 100 < 900)
        {
            setPos(x()+10, y()); //keep current y but move x to the right
        }
    }
    else if (event -> key() == Qt::Key_Space)
    {
        //Create bullet
        Bullet * bullet = new Bullet();
        bullet -> setPos(x(), y());
        scene()->addItem(bullet);

        //Add sound
        if (bulletsound -> state() == QMediaPlayer::PlayingState)
        {
            bulletsound -> setPosition(0);
        }
        else if (bulletsound -> state() == QMediaPlayer::StoppedState)
        {
            bulletsound -> play();
        }
    }
}

void Player::generate()
{
    Enemy * enemy = new Enemy();
    scene() -> addItem(enemy);
}
