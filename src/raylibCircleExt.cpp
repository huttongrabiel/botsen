#include <raylibCircleExt.h>

namespace RaylibExt {

raylibCircleExt::raylibCircleExt(int direction_of_travel, int velocity,  int radius, Vector2 center) :
    _direction_of_travel(direction_of_travel),
    _velocity(velocity),
    _radius(radius),
    _center(center) {}

raylibCircleExt::~raylibCircleExt() {}

}
