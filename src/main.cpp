#include <QApplication>
#include <QTimer>
#include <QGraphicsView>

#include "GameProcessor.h"
#include "SoundCenter.h"




int  main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    YagwScene scene;

    app.setApplicationName("Yagw: Yet Another Graphic Woobling");
    SoundCenter::get_instance(); // init le son et lance la musique
    QGraphicsView view(&scene);
    GameProcessor game(scene);

    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    view.show();
    game.start(1000/60);
    app.exec();
    return (0);
}
