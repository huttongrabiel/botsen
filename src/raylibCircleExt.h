#include <raylib.h>

namespace RaylibExt {

class raylibCircleExt {
public:
    raylibCircleExt(int direction_of_travel, int velocity, int radius, Vector2 center);
    ~raylibCircleExt();
    void change_direction_of_travel() { _direction_of_travel *= -1; };

private:
    // Left is -1, right is 1
    int _direction_of_travel;
    int _velocity;
    int _radius;
    Vector2 _center;
};

}
