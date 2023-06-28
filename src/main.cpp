#include <iostream>
#include <stdlib.h>
#include <vector>

#include <raylib.h>

#include <object.h>
#include <raylibCircleExt.h>
#include <collisions.h>

constexpr int circle_radius = 40;
constexpr int ball_velocity = 5;
constexpr int screen_width = 800;
constexpr int screen_height = 600;

void update_and_draw_circles(RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2) {
    bool have_collided = CheckCollisionCircles(
                {static_cast<float>(circle_1.center().x), static_cast<float>(circle_1.center().y)},
                circle_radius,
                {static_cast<float>(circle_2.center().x), static_cast<float>(circle_2.center().y)},
                circle_radius);

    if (Collision::has_collided_with_edge(circle_1, screen_width)) {
        circle_1.change_direction_of_travel();
    }
    if (Collision::has_collided_with_edge(circle_2, screen_width)) {
        circle_2.change_direction_of_travel();
    }

    if (have_collided) {
        Collision::simulate_elastic_collision(circle_1, circle_2);
    }

    int circle_1_new_x_pos = circle_1.center().x + circle_1.direction() * circle_1.velocity();
    int circle_2_new_x_pos = circle_2.center().x + circle_2.direction() * circle_2.velocity();
    circle_1.update_circle_center({ circle_1_new_x_pos, circle_1.center().y});
    circle_2.update_circle_center({ circle_2_new_x_pos, circle_2.center().y});

    DrawCircle(circle_1.center().x, circle_1.center().y, circle_1.radius(), RED);
    DrawCircle(circle_2.center().x, circle_2.center().y, circle_1.radius(), BLUE);
}

int main() {
    InitWindow(screen_width, screen_height, "Botsen");

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

        update_and_draw_circles(circle_1, circle_2);

        EndDrawing();
    }

    CloseWindow();
}

