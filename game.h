#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <player.h>
#include "score.h"
#include "health.h"
#include "intro.h"

class Game : public QGraphicsView{
public:
    Game (QWidget* parent = 0);
    QGraphicsScene * scene;

    bool cont_game;
    Player * player;
    Score * score;
    Health * health;
    Intro * introduction;
};

#endif // GAME_H
