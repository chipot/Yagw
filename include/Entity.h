#pragma once
#ifndef ENTITY_R9HRHD6H
#define ENTITY_R9HRHD6H

#include <QList>

#include "Shape.h"

class Entity
{
 protected:
  Shape const & shape;
  size_t        accl;
  size_t        speed;
  Entity(Shape const &s, size_t a, size_t sp) :
      shape(s), accl(a), speed(sp) {}
 public:
  Shape const &getShape() {return this->shape;};
};

class Player : public Entity
{
 public:
  Player() : Entity(*(new PlayerShape()), 0 ,0) {}
  ~Player(){};

  void lol() const
  {
    this->shape.dump();
  }
 private:
};

#endif /* end of include guard: ENTITY_R9HRHD6H */
