#include <RaylibCircleExt.h>

namespace RaylibExt {

raylibCircleExt::raylibCircleExt(int direction_of_travel, int velocity,  int radius, Object::ObjPos center) :
    _direction_of_travel(direction_of_travel),
    _velocity(velocity),
    _radius(radius),
    _circle_center(center) {}

raylibCircleExt::~raylibCircleExt() {}

void raylibCircleExt::update_circle_center(Object::ObjPos new_center) {
    _circle_center = new_center;
}

void raylibCircleExt::set_velocity(int new_velocity) {
    _velocity = new_velocity;
}

void raylibCircleExt::set_direction_of_travel(int direction) {
    _direction_of_travel = direction;
}

}
