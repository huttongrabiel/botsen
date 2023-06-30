#pragma once

#include <raylib.h>
#include <Object.h>

namespace RaylibExt {

class raylibCircleExt {
public:
    raylibCircleExt(int velocity, int radius, int mass, Object::ObjPos center);
    ~raylibCircleExt();
    void update_circle_center(Object::ObjPos new_center);
    void set_velocity(double new_velocity);
    void negate_velocity() { _velocity *= -1; }
    void set_mass(int mass);

    double velocity() const { return _velocity; }
    int radius() const { return _radius; }
    int mass() const { return _mass; }
    Object::ObjPos center() const { return _circle_center; }

private:
    // Negative velocity = negative x direction. Positive velocity = positive x direction
    double _velocity;
    int _radius;
    int _mass;
    Object::ObjPos _circle_center;
};

}
