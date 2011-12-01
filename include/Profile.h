#ifndef PROFILE_H
#define PROFILE_H

class MoveBehavior;
class ShootBehavior;
class RotationBehavior;
class TransformationBehavior;
class Entity;


class Profile {

    MoveBehavior            *moveBehavior;
    RotationBehavior        *rotationBehavior;
    ShootBehavior           *shootBehavior;
    TransformationBehavior  *transformationBehavior;
    Entity                  *entity; // ne pas delete;

public:
    Profile();
    Profile(MoveBehavior *move = 0, RotationBehavior *rotate = 0, ShootBehavior *shoot = 0, TransformationBehavior *transform = 0);
    virtual ~Profile();

    void setMoveBehavior(MoveBehavior*);
    void setRotationBehavior(RotationBehavior*);
    void setShootBehavior(ShootBehavior*);
    void setTransformationBehavior(TransformationBehavior*);
    void setEntity(Entity*);

    void move();
    void rotate();
    void shoot();
    void transform();
    void process();

    Profile *copy();
};


#endif // PROFILE_H
