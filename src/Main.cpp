#include <iostream>
#include <stdlib.h>
#include <vector>

#include <raylib.h>

#include <Object.h>
#include <RaylibCircleExt.h>
#include <Collisions.h>
#include <Scenes.h>
#include <GameData.h>

constexpr int circle_radius = 40;
constexpr int ball_velocity = 5;
constexpr int screen_width = 800;
constexpr int screen_height = 600;

int main() {
    InitWindow(screen_width, screen_height, "Botsen");

    GameData::Game active_game = { screen_width, screen_height, GameData::Scenes::COLLISION };

    SetTargetFPS(60);

    TraceLogLevel(LOG_ALL);

    std::vector<Object::Object> active_objects;

    // For starting test purposes we will not render custom objects but instead
    // use raylib's circles
    Object::ObjPos circle_1_pos = { screen_width/2, screen_height/2 }; // Left circle
    Object::ObjPos circle_2_pos = { screen_width-200, screen_height/2 }; // Right circle

    // Circle 1 begins at rest and circle 2 will collide with it putting it in motion
    RaylibExt::raylibCircleExt circle_1(1, 0, circle_radius, circle_1_pos);
    RaylibExt::raylibCircleExt circle_2(-1, ball_velocity, circle_radius, circle_2_pos);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        switch (active_game.current_scene) {
            case GameData::Scenes::HOME:
                break;
            case GameData::Scenes::COLLISION:
                Scenes::update_and_draw_circles(active_game, circle_1, circle_2);
        }

        EndDrawing();
    }

    CloseWindow();
}

