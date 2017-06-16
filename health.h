#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QObject>

class Health: public QGraphicsTextItem {
Q_OBJECT

public:
    Health (QGraphicsItem * parent = 0);
    void decrease();
    void increase();
    int getHealth();
    void displayHealth();

signals:
    void dead();

private:
    int health;
};

#endif // HEALTH_H
