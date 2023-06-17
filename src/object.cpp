#include "object.h"

namespace Object {

Object::Object() {}

Object::Object(int mass, int velocity) :
    _mass(mass),
    _velocity(velocity) {}

Object::~Object() {}

}
