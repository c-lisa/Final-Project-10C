#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include <QMediaPlayer>
#include <QPixmap>
#include <QImage>

Game::Game(QWidget * parent)
{
    //1. Create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); //set scene size
    setBackgroundBrush(QBrush(QImage(":/Images/BackgroundArt.png")));

    //QPixmap backgroundart("qrc:/Images/BackgroundArt.png");
    //scene->addPixmap(backgroundart);

    //2. Add view to visualize scene. Disable scroll bar. Show scene. Set view size AND scene size.
    /*
    //5. Add view to actually visualize scene. Disable scrollbar. Show scene. Set view size AND scene size.
    QGraphicsView* view = new QGraphicsView(scene);
    view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Can also do:
    view -> setScene(scene);
    view is by default a widget, so we need to make it visible.
    view -> show();
    view->setFixedSize(800,600); //set view size
    */
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //3. Create item (player) to put in scene. By default rectangle has (x, y, w, l) - all = to 0.
    //x and y begin from top left corner.
    player = new Player();
    player->setPos(400,500);
    //player->setBrush(Qt::green);
    /*
    player->setPos(view->width()/2, view->height() - player->rect().height()); //set position of item
    */

    //4. Give item (player) ability to be focused on AND then set focus.
    player -> setFlag(QGraphicsItem::ItemIsFocusable);
    player -> setFocus();

    //5. Add item (player) to scene.
    scene->addItem(player);

    //6. Create Score/Health
    score = new Score();
    scene -> addItem(score);
    health = new Health();
    health -> setPos(health->x(), health->y()+25);
    scene -> addItem(health);

    //7. Add the enemies.
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer -> start(2000); //create an enemy eveyr 2000 milliseconds

    //8. Play music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Sound/Background.mp3"));
    music->volumeChanged(1);
    music->play();

    show();
}
