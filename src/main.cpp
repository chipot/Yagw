#include <QApplication>
#include <QTimer>

#include "YagwGLDrawer.h"

int  main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  YagwGLDrawer gld;
  QTimer T;

  T.connect(&T, SIGNAL(timeout()), &gld, SLOT(update()));
  //T.start(1000 / 60);
  T.start(1000);
  gld.show();
  app.exec();
  return (0);
}
