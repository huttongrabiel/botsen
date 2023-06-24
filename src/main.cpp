#include <iostream>
#include <stdlib.h>
#include <vector>

#include <raylib.h>

#include <object.h>
#include <raylibCircleExt.h>

constexpr int circle_radius = 40;
constexpr int ball_velocity = 5;
constexpr int screen_width = 800;
constexpr int screen_height = 600;

// Checks if a ball has hit either the left or right edge of the screen
bool ball_hit_edge(const RaylibExt::raylibCircleExt& circle) {
    int center_x = circle.center().x;
    int radius = circle.radius();
    bool hit_left_edge = center_x - radius <= 0;
    bool hit_right_edge = center_x + radius >= screen_width;
    return hit_left_edge || hit_right_edge;
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

        bool have_collided = CheckCollisionCircles(
                {static_cast<float>(circle_1_pos.x), static_cast<float>(circle_1_pos.y)},
                circle_radius,
                {static_cast<float>(circle_2_pos.x), static_cast<float>(circle_2_pos.y)},
                circle_radius);

        if (ball_hit_edge(circle_1)) {
            circle_1.change_direction_of_travel();
        }
        if (ball_hit_edge(circle_2)) {
            circle_2.change_direction_of_travel();
        }

        // Continuous elastic collision along x axis of frame
        if (have_collided) {
            int circle_1_velocity = circle_1.velocity();
            int circle_2_velocity = circle_2.velocity();
            int circle_1_dir_travel = circle_1.direction();
            int circle_2_dir_travel = circle_2.direction();
            if (circle_2_velocity > 0) {
                circle_1.set_velocity(circle_2_velocity);
                circle_2.set_velocity(0);
                circle_1.set_direction_of_travel(circle_2_dir_travel);
            } else if (circle_1_velocity > 0) {
                circle_2.set_velocity(circle_1_velocity);
                circle_1.set_velocity(0);
                circle_2.set_direction_of_travel(circle_1_dir_travel);
            }
        }

        circle_1_pos.x += circle_1.direction() * circle_1.velocity();
        circle_2_pos.x += circle_2.direction() * circle_2.velocity();
        circle_1.update_circle_center(circle_1_pos);
        circle_2.update_circle_center(circle_2_pos);

        DrawCircle(circle_1.center().x, circle_1.center().y, circle_1.radius(), RED);
        DrawCircle(circle_2.center().x, circle_2.center().y, circle_1.radius(), BLUE);

        EndDrawing();
    }

    CloseWindow();
}
