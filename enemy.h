#ifndef ENEMY_H
#define ENEMY_H

#include "externalobject.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Enemy : public QObject, public externalobject, public QGraphicsPixmapItem  {
    Q_OBJECT

public:
    Enemy (QGraphicsItem* parent = 0);

public slots:
    void move();
};

#endif // ENEMY_H
