#include <game.h>
#include <QImage>
#include <QPixmap>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "externalobject.h"
#include <QMediaPlayer>

Game::Game(QWidget *parent) : enemy_number(2000)
{
    //Create the scene
    scene = new QGraphicsScene();

    //Set background & size of screen
    scene->setSceneRect(0,0, 900, 700);
    setBackgroundBrush(QBrush(QImage(":/Images/Background Image - Level 1.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900, 700);

    //play music
    QMediaPlayer * music = new QMediaPlayer();
    music -> setMedia(QUrl("qrc:/Sound/Background Music.mp3"));
    music->play();

    //true = play game
    cont_game = true;

    //add player into scene
    player = new Player();
    player -> setPos(400,550);

    //focus on player
    player -> setFlag(QGraphicsItem::ItemIsFocusable);
    player -> setFocus();

    //add player to scene
    scene -> addItem(player);

    //create score/health
    score = new Score();
    scene -> addItem(score);
    health = new Health();
    health -> setPos(health->x(), health->y()+25);
    scene -> addItem(health);

    //add enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(generate()));
    if (score->getScore()>0 && score->getScore()%10 == 0)
    {
        enemy_number-=200;
    }

    timer -> start(enemy_number);

    show();
}
