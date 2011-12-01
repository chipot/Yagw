#ifndef MYGLDRAWER_F8CH2366

#define MYGLDRAWER_F8CH2366

#include <QGLWidget>
#include <QQueue>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QKeyEvent>
#include <QRect>

#include <QDebug>

class Entity;

class YagwGLDrawer : public QGLWidget
{
  Q_OBJECT
 public:
    YagwGLDrawer(QWidget *parent = 0) : QGLWidget(parent)
    {
      this->setMouseTracking(true);
    }

  virtual ~YagwGLDrawer()
    {
    }

  public slots:
  void update()
  {
    this->updateGL();
  }

  private:
  virtual void initializeGL();
  virtual void resizeGL(int w, int h);

  virtual void paintGL();
  void keyPressEvent(QKeyEvent *ev);

 private:
  QQueue<QKeyEvent>	_keyq;
  QList<Entity *>	_entities;
};


#endif /* end of include guard: MYGLDRAWER_F8CH2366 */
