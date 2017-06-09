#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "QDebug"
#include "enemy.h"

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    bulletsound = new QMediaPlayer();
    bulletsound -> setMedia(QUrl("qrc:/Sound/Bullet.mp3"));

    //player->setRect(0,0,100,100);

    //Draw player
    setPixmap(QPixmap(":/Images/Kanga_player.jpg"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    /*
    To check, can use qDebug() << "Player knows that you pressed a key.";
    Info abt event including what key is pressed is stored inside.
    */
    if (event->key() == Qt::Key_Left)   {
        if (pos().x() > 0)
        {
            setPos(x()-10, y()); //keep current y but move x to the left
        }
    }
    else if (event->key() == Qt::Key_Right)    {
        if (pos().x() + 100 < 800)
        {
            setPos(x()+10, y()); //keep current y but move x to the right
        }
    }
    /*
    If you want player to move up and down:
    else if (event->key() == Qt::Key_Up)    {
        setPos(x(), y()-10); //keep current x but move y up
    }
    else if (event->key() == Qt::Key_Down)    {
        setPos(x(), y()+10); //keep current x but move y down
    }
    */
    else if (event->key() == Qt::Key_Space){
        //1. Create bullet
        Bullet* bullet = new Bullet(); //qDebug() << "Bullet created";
        //2. Set position of bullet
        bullet -> setPos(x(), y());
        //3. Add bullet to scene and scene() returns & to the scene Player (player) is in
        scene()->addItem(bullet);
        //4. To get it to move go back to main

        //5. play bullet sound
        if (bulletsound -> state() == QMediaPlayer::PlayingState)
        {
            bulletsound -> setPosition(0); //reset sound
        }
        else if (bulletsound -> state() == QMediaPlayer::StoppedState)
        {
            bulletsound -> play();
        }

    }
}

void Player::spawn()
{
  //1. Create enemy
  Enemy * enemy = new Enemy();
  scene() -> addItem(enemy);
}
