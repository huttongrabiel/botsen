#pragma once

#include <raylib.h>
#include <object.h>

namespace RaylibExt {

class raylibCircleExt {
public:
    raylibCircleExt(int direction_of_travel, int velocity, int radius, Object::ObjPos center);
    ~raylibCircleExt();
    void change_direction_of_travel() { _direction_of_travel *= -1; };

private:
    // Left is -1, right is 1
    int _direction_of_travel;
    int _velocity;
    int _radius;
    Object::ObjPos _circle_center;
};

}
