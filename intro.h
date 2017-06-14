#ifndef INTRO_H
#define INTRO_H

#include <QGraphicsTextItem>

class Intro: public QGraphicsTextItem {
public:
    Intro (QGraphicsItem * parent = 0);
    void give_directions();
    void keyPressEvent(QKeyEvent* event);

private:
    bool introgiven;
};

#endif // INTRO_H
