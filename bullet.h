#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Bullet(QGraphicsItem* parent=0);

public slots:
    void move();
};


#endif // SHOOT_H
