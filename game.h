#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <player.h>
#include "score.h"
#include "health.h"

class Game : public QGraphicsView{
    Q_OBJECT

public:
    Game (QWidget* parent = 0);
    QGraphicsScene * scene;

    bool cont_game;
    Player * player;
    Score * score;
    Health * health;

    void display_menu();
    int enemy_number;

public slots:
    void start();

};

#endif // GAME_H
