#include <QApplication>
#include "game.h"
#include <stdlib.h>
#include "time.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand((int)time(0));

    game = new Game();
    game -> show();

    return a.exec();
}
