#include <QApplication>
#include "game.h"

/*
Basic knowledge of C++, pointers, and memory management.
Basic knowledge of Qt.

Tutorial 1:
QGraphicsScene
    -container for all of game objects. For example players, trees, etc.
    -kind of like a map or a world
    -can only contain QGraphicsItem - derived from that class
QGraphicsItem - any item in Scene has to be derived from QGraphics Item
    -we're going to use QGraphicsRectItem (item that inherits from it and reprsents rectangle)
    -is abstract class - derive from it, create custom item, and then it shows up in scene
QGraphicsView - widget used to visualize the scene
    -everything in scene is invisible - just contains info for bunch of items in it
    -if you want to print scene, you need this to view it
*/
/*
Tutorial 2:
GOAL: get rectange to move

-events (keypressed() and QKeyEvent)
    -anything important that happens in the lifetime of your application
    -when user presses key, you need to know at least one piece of information
    -QKeyEvent stores that info and tells you what happened
-event propogation system
    -tells you order things were passed around
    So when key is pressed, View will tell the Scene that something was pressed. Then Scene will go find associated item and
    tell it, hey something was pressed. Then myrect will call keyPressEvent() which then we checked what key was
    pressed and then it reacts.
-QDebug
    -useful header file that prints things out into console to help you debug
*/
/*
Tutorial 3:
QTimer

Signal and Slots (connect function)
QObject and Q_OBJECT macro
*/
/*
Tutorial 4:
QGraphicsScene's sceneRect
QGraphicsView's sceneRect
QGraphicsView coordinates vs QGraphicsScene coordinates vs GraphicItem coordinates
    3 coordinate scenes we need to be aware of:
    QGraphicsScene is HUGE AND INFINITE. Scene's SceneRect is not set and that's where you have a scrollbar.
    -> inside is
        QGraphicsView
        -> inside is
            MyRect
*/
/*
Tutorial 5:
collidingItems() <- new topic
QTimer and Coordinate systems <- old topics (review)
*/
/*
Tutorial 6:
Parents
QGraphicsTextItem (text you can put in scene), setPlainText(), setFont(), setDefaultTextColor()
*/
/*
Tutorial 7:
Resource files
QMediaPlayer, setMedia(), QURL, play()
*/

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game -> show();

    return a.exec();
}
