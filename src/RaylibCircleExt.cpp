#include <RaylibCircleExt.h>

namespace RaylibExt {

raylibCircleExt::raylibCircleExt(int velocity,  int radius, int mass, Object::ObjPos center) :
    _velocity(velocity),
    _radius(radius),
    _mass(mass),
    _circle_center(center) {}

raylibCircleExt::~raylibCircleExt() {}

void raylibCircleExt::update_circle_center(Object::ObjPos new_center) {
    _circle_center = new_center;
}

void raylibCircleExt::set_velocity(double new_velocity) {
    _velocity = new_velocity;
}

void raylibCircleExt::set_mass(int mass) {
    _mass = mass;
}

}
