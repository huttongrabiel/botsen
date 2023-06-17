#include <iostream>
#include <stdlib.h>
#include <vector>

#include <raylib.h>

#include "object.h"

int main() {
    int screen_width = GetScreenWidth()/4;
    int screen_height = GetScreenHeight()/4;

    std::vector<Object::Object> active_objects;

    SetTargetFPS(60);

    // For starting test purposes we will not render custom objects but instead
    // use raylib's circles
    Object::ObjPos circle_1_pos = { screen_width/4, screen_height/2};
    Object::ObjPos circle_2_pos = { screen_width*(3/4), screen_height/2};

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircle(circle_1_pos.x, circle_1_pos.y, 80, RED);
        DrawCircle(circle_2_pos.x, circle_2_pos.y, 80, BLUE);
        EndDrawing();
    }

    CloseWindow();
}
