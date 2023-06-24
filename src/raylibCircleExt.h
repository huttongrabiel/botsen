#pragma once

#include <raylib.h>
#include <object.h>

namespace RaylibExt {

class raylibCircleExt {
public:
    raylibCircleExt(int direction_of_travel, int velocity, int radius, Object::ObjPos center);
    ~raylibCircleExt();
    void change_direction_of_travel() { _direction_of_travel *= -1; };
    void update_circle_center(Object::ObjPos new_center);
    void set_velocity(int new_velocity);
    void set_direction_of_travel(int direction);

    int direction() const { return _direction_of_travel; };
    int velocity() const { return _velocity; };
    int radius() const { return _radius; };
    Object::ObjPos center() const { return _circle_center; };

private:
    // Left is -1, right is 1
    int _direction_of_travel;
    int _velocity;
    int _radius;
    Object::ObjPos _circle_center;
};

}
