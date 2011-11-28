#include "Profile.h"
#include "Behaviors.h"

Profile::Profile() : moveBehavior(0), rotationBehavior(0),
    shootBehavior(0), transformationBehavior(0),
    entity(0)
{

}

Profile::Profile(MoveBehavior *move, RotationBehavior *rotate,
                 ShootBehavior *shoot, TransformationBehavior *transform)
    : moveBehavior(move), rotationBehavior(rotate),
      shootBehavior(shoot), transformationBehavior(transform)
{

}

void Profile::setMoveBehavior(MoveBehavior *move) {
        moveBehavior = move;
}

void Profile::setRotationBehavior(RotationBehavior *rotate) {
    rotationBehavior = rotate;
}

void Profile::setShootBehavior(ShootBehavior *shoot) {
    shootBehavior = shoot;
}

void Profile::setTransformationBehavior(TransformationBehavior *transform) {
    transformationBehavior = transform;
}

void Profile::setEntity(Entity *ent) {
    entity = ent;
    if (moveBehavior)
        moveBehavior->setEntity(ent);
    if (rotationBehavior)
        rotationBehavior->setEntity(ent);
    if (shootBehavior)
        shootBehavior->setEntity(ent);
    if (transformationBehavior)
        transformationBehavior->setEntity(ent);
}

void Profile::move() {
    if (moveBehavior)
        moveBehavior->move();
}

void Profile::rotate() {
    if (rotationBehavior)
        rotationBehavior->rotate();
}

void Profile::shoot() {
    if (shootBehavior)
        shootBehavior->shoot();
}

void Profile::transform() {
    if (transformationBehavior)
        transformationBehavior->transform();
}

void Profile::process() {
    move();
    rotate();
    shoot();
    transform();
}
