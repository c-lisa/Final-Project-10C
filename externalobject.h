#ifndef EXTERNALOBJECT_H
#define EXTERNALOBJECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Enemy(QGraphicsItem* parent = 0);

public slots:
    void move();
};

#endif // EXTERNALOBJECT_H
