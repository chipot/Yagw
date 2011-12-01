#include <QApplication>
#include <QTimer>
#include <QTime>
#include <QGraphicsView>

#include "GameProcessor.h"
#include "SoundCenter.h"




int  main(int argc, char *argv[])
{
    QApplication::setGraphicsSystem("opengl");
    QApplication app(argc, argv);
    YagwScene scene;

    qsrand(0xDEADBEEF * QTime::currentTime().msec());
    app.setApplicationName("Yagw: Yet Another Graphic Woobling");
    SoundCenter::get_instance(); // init le son et lance la musique
    QGraphicsView view(&scene);
    GameProcessor game(scene);
    scene.connect(&scene, SIGNAL(quit()), &app, SLOT(quit()));
    view.showFullScreen();
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.show();
    view.setMouseTracking(false);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    app.setOverrideCursor( QCursor( Qt::BlankCursor ) );
    app.exec();
    return (0);
}
