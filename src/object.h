namespace Object {

struct ObjPos {
    int x;
    int y;
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
    int _velocity;
    ObjPos _pos;
};

}
