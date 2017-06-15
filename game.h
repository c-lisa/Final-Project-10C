#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <player.h>
#include "score.h"
#include "health.h"

class Game : public QGraphicsView{
public:
    Game (QWidget* parent = 0);
    QGraphicsScene * scene;

    bool cont_game;
    Player * player;
    Score * score;
    Health * health;

    void start();
    int enemy_number;

};

#endif // GAME_H
