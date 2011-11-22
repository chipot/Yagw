#include <QApplication>
#include <QTimer>
#include <QGraphicsView>
#include "YagwScene.h"

int  main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTimer T;

    YagwScene scene;
    QGraphicsView view(&scene);

    T.connect(&T, SIGNAL(timeout()), &scene, SLOT(advance()));
    T.start(1000 / 60);
    view.fitInView(view.sceneRect());
    view.show();
    app.exec();
    return (0);
}
