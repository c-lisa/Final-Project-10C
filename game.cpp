#include <game.h>
#include <QImage>
#include <QPixmap>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "externalobject.h"
#include <QMediaPlayer>
#include "button.h"

Game::Game(QWidget *parent) : enemy_number(2000)
{
    //Set background & size of screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900, 700);

    //Create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 900, 700);
    setScene(scene);
}

void Game::start()
{
    scene->clear();

    setBackgroundBrush(QBrush(QImage(":/Images/Background Image - Level 1.png")));

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
    timer -> start(enemy_number);

    //connect gameover stuff
    connect(health, SIGNAL(dead()), this, SLOT(gameover()));

    show();
}

void Game::display_menu()
{
    setBackgroundBrush(QBrush(QImage(":/Images/Intropagebackground.png")));

    //create title menu
    QGraphicsTextItem * title = new QGraphicsTextItem(QString("Little Hippo the Pilot"));
    QFont titlefont ("courier new", 50);
    titlefont.bold();
    title -> setFont(titlefont);
    int title_x = this->width()/2 - title->boundingRect().width()/2;
    int title_y = 100;
    title->setPos(title_x, title_y);

    //creating description
    QGraphicsTextItem * description = new QGraphicsTextItem(QString("Little Hippo is the captain of the airforce in the kingdom of Teddy the \nYorkshire dog. The kingdom is under attack! Defend the kingdom by shooting\nthe enemy planes. Use left and right arrow keys to move and the spacebar\nto shoot."));
    QFont descriptionfont ("courier new", 15);
    description -> setFont(descriptionfont);
    description -> setPos(0, 210);

    scene -> addItem(title);
    scene -> addItem(description);

    play_quit();
}

void Game::gameover()
{
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":/Images/Intropagebackground.png")));

    //GAMEOVER
    QGraphicsTextItem * gameover = new QGraphicsTextItem(QString("GAMEOVER"));
    QFont gameoverfont ("courier new", 70);
    gameoverfont.bold();
    gameover -> setFont(gameoverfont);
    int gameover_x = this->width()/2 - gameover->boundingRect().width()/2;
    int gameover_y = 150;
    gameover->setPos(gameover_x, gameover_y);

    play_quit();
}

void Game::play_quit()
{
    //create play button
    button* playbutton = new button(QString("PLAY"));
    int play_x = this->width()/2 - playbutton->boundingRect().width()/2;
    int play_y = 350;
    playbutton->setPos(play_x, play_y);
    connect (playbutton, SIGNAL(clicked()), this, SLOT(start()));
    scene -> addItem(playbutton);

    //creqte quit button
    button* quitButton = new button(QString("QUIT"));
    int quit_x = this->width()/2 - quitButton->boundingRect().width()/2;
    int quit_y = 450;
    quitButton->setPos(quit_x, quit_y);
    connect(quitButton,SIGNAL(clicked()),this, SLOT(close()));
    scene->addItem(quitButton);
}
