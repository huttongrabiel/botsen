#include <raylibCircleExt.h>

namespace RaylibExt {

raylibCircleExt::raylibCircleExt(int direction_of_travel, int velocity,  int radius, Object::ObjPos center) :
    _direction_of_travel(direction_of_travel),
    _velocity(velocity),
    _radius(radius),
    _circle_center(center) {}

raylibCircleExt::~raylibCircleExt() {}

}
