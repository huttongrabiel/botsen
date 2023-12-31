#include <iostream>
#include <stdlib.h>
#include <vector>

#include <raylib.h>

#include <Object.h>
#include <RaylibCircleExt.h>
#include <Collisions.h>
#include <UI.h>
#include <GameData.h>

constexpr int screen_width = 800;
constexpr int screen_height = 600;

int main() {
    InitWindow(screen_width, screen_height, "Botsen");

    GameData::Game active_game = { screen_width, screen_height, GameData::Scenes::HOME };

    SetTargetFPS(60);

    TraceLogLevel(LOG_ALL);

    Object::ObjPos circle_1_pos = { screen_width/2, screen_height/2 }; // Left circle
    Object::ObjPos circle_2_pos = { screen_width-200, screen_height/2 }; // Right circle

    // Circle 1 begins at rest and circle 2 will collide with it putting it in motion
    RaylibExt::raylibCircleExt circle_1(0, UI::circle_radius, UI::circle_mass, circle_1_pos);
    RaylibExt::raylibCircleExt circle_2(-1.0 * UI::ball_velocity, UI::circle_radius, UI::circle_mass, circle_2_pos);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        if (IsKeyPressed(KEY_SPACE)) {
            if (active_game.current_scene == GameData::Scenes::HOME)
                active_game.current_scene = GameData::Scenes::COLLISION;
            else
                active_game.current_scene = GameData::Scenes::HOME;
        }

        switch (active_game.current_scene) {
            case GameData::Scenes::HOME:
                UI::update_and_draw_home(active_game);
                break;
            case GameData::Scenes::COLLISION:
                UI::update_and_draw_simulation(active_game, circle_1, circle_2);
        }

        EndDrawing();
    }

    CloseWindow();
}
