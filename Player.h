#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Player(QGraphicsItem* parent = 0);
    void keyPressEvent(QKeyEvent* event);

public slots:
    void spawn();

private:
    QMediaPlayer * bulletsound;
};

#endif // MYRECT_H
