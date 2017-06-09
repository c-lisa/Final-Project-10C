#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "Player.h"
#include <QGraphicsView>
#include <QWidget>
#include "score.h"
#include "health.h"

class Game : public QGraphicsView{
public:
    Game (QWidget* parent = 0);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

};

#endif // GAME_H
