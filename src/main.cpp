#include <iostream>
#include <stdlib.h>
#include <vector>

#include <raylib.h>

#include "object.h"

constexpr int circle_radius = 80;

int main() {
    int screen_width = 800;
    int screen_height = 600;

    InitWindow(screen_width, screen_height, "Botsen");

    SetTargetFPS(60);

    std::vector<Object::Object> active_objects;

    // For starting test purposes we will not render custom objects but instead
    // use raylib's circles
    Object::ObjPos circle_1_pos = { 200, screen_height/2}; // Left circle
    Object::ObjPos circle_2_pos = { screen_width-200, screen_height/2}; // Right circle

    int towards = 1;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        // Move the balls away from one another
        if (circle_1_pos.x+circle_radius == screen_width && circle_2_pos.x-circle_radius == 0) {
            towards = -1;
        // Move the balls towards one another
        } else if (circle_1_pos.x-circle_radius == 0 && circle_2_pos.x+circle_radius == screen_width) {
            towards = 1;
        }

        circle_1_pos.x += towards*2;
        circle_2_pos.x -= towards*2;
        DrawCircle(circle_1_pos.x, circle_1_pos.y, 80, RED);
        DrawCircle(circle_2_pos.x, circle_2_pos.y, 80, BLUE);

        EndDrawing();
    }

    CloseWindow();
}
