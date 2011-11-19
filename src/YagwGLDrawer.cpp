#include "YagwGLDrawer.h"
#include "Entity.h"

void YagwGLDrawer::initializeGL()
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);				// The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
  glEnable(GL_LINE_SMOOTH);			// Enables Depth Testing
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				// Reset The Projection Matrix

  glMatrixMode(GL_MODELVIEW);
  glLineWidth(1.1);

  _entities << new Player();
}

void YagwGLDrawer::resizeGL(int w, int h)
{
  if (h == 0)				// Prevent A Divide By Zero If The Window Is Too Small
    h = 1;

  glViewport(0, 0, w, h);		// Reset The Current Viewport And Perspective Transformation

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}

void YagwGLDrawer::paintGL()
{
  //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer

  // put the eye in the right place.
  glLoadIdentity();

  glTranslatef(0, 0, 2.0f);
  //do nothing ! Fuck yeah !
  Entity *entity;
  foreach(entity, _entities)
  {
    Shape const &shape = entity->getShape();
    Vertex v;
    glBegin(GL_LINE_STRIP);
      glColor3b(0, 0, 255);
      foreach(v, shape._vlist)
      {
        qDebug() << v.x << v.y;
        glVertex2f(v.x, v.y);
      }
    glEnd();
  }
}

void YagwGLDrawer::keyPressEvent(QKeyEvent *ev)
{
  this->_keyq.enqueue(*ev);
}
