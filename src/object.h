namespace Object {

struct ObjPos {
    int x;
    int y;
};

struct ObjVelocity {
    int x_velocity;
    int y_velocity;
};

class Object {
public:
    Object();
    Object(int mass, int velocity);
    ~Object();
private:
    int _sprite[3][3] { {0, 1, 0},
                        {1, 1, 1},
                        {0, 1, 0} };
    int _mass;
    ObjPos _pos;
    ObjVelocity _velocity;
};

}
