#include <game.h>
#include <QImage>
#include <QPixmap>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "externalobject.h"
#include <QMediaPlayer>

Game::Game(QWidget *parent)
{
    //Create the scene
    scene = new QGraphicsScene();

    //Set background & size of screen
    scene->setSceneRect(0,0, 900, 700);
    setBackgroundBrush(QBrush(QImage(":/Images/Background Image - Level 1.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,700);

    //play music
    QMediaPlayer * music = new QMediaPlayer();
    music -> setMedia(QUrl("qrc:/Sound/Background Music.mp3"));
    music->play();

    //add player into scene
    player = new Player();
    player -> setPos(400,500);

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
    timer -> start(2000);

    show();
}
