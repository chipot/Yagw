#pragma once
#ifndef SHAPE_NFHTQOKU
#define SHAPE_NFHTQOKU

#include <algorithm>
#include <functional>
#include <QList>
#include <QDebug>

struct Vertex
{
  long x;
  long y;
};

class Shape
{
 public:
  QList<Vertex> _vlist;
 protected:
  Shape(std::initializer_list<Vertex> init)
  {
    std::for_each(init.begin(), init.end(), [&_vlist](Vertex const &v){
                    _vlist << v;
                  });
  }
 public:
  void dump() const
  {
    std::for_each(_vlist.constBegin(), _vlist.constEnd(), [](Vertex const &v) {
                   qDebug() << v.x << v.y;
                  });
  }
};

class PlayerShape : public Shape
{
 public:
  PlayerShape() : Shape({{1, 1},
                         {-1, 1},
                         {-1, -1},
                         {1, -1},
                        })
  {
  }
};

#endif /* end of include guard: SHAPE_NFHTQOKU */
