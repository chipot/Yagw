#include <QApplication>
#include <QTimer>
#include <QGraphicsView>

#include "GameProcessor.h"
#include "SoundCenter.h"

int  main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTimer T;
    YagwScene scene;

    SoundCenter::get_instance(); // init le son et lance la musique

    QGraphicsView view(&scene);
    GameProcessor game(scene);
    T.connect(&T, SIGNAL(timeout()), &scene, SLOT(advance()));
    T.start(1000 / 60);
    view.fitInView(view.sceneRect());
    view.show();
    game.start();
    app.exec();
    return (0);
}
