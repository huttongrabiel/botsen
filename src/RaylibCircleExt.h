#pragma once

#include <raylib.h>
#include <Object.h>

namespace RaylibExt {

class raylibCircleExt {
public:
    raylibCircleExt(int direction_of_travel, int velocity, int radius, int mass, Object::ObjPos center);
    ~raylibCircleExt();
    void change_direction_of_travel() { _direction_of_travel *= -1; };
    void update_circle_center(Object::ObjPos new_center);
    void set_velocity(double new_velocity);
    void set_direction_of_travel(int direction);
    void set_mass(int mass);

    int direction() const { return _direction_of_travel; }
    double velocity() const { return _velocity; }
    int radius() const { return _radius; }
    int mass() const { return _mass; }
    Object::ObjPos center() const { return _circle_center; }

private:
    // Left is -1, right is 1
    int _direction_of_travel;
    double _velocity;
    int _radius;
    int _mass;
    Object::ObjPos _circle_center;
};

}
