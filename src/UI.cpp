#include <raylib.h>

#include <Collisions.h>
#include <UI.h>

namespace UI {

void update_and_draw_circles(const GameData::Game& active_game, RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2) {
    bool have_collided = CheckCollisionCircles(
                {static_cast<float>(circle_1.center().x), static_cast<float>(circle_1.center().y)},
                circle_1.radius(),
                {static_cast<float>(circle_2.center().x), static_cast<float>(circle_2.center().y)},
                circle_2.radius());

    if (Collision::has_collided_with_edge(circle_1, active_game.screen_width)) {
        circle_1.change_direction_of_travel();
    }
    if (Collision::has_collided_with_edge(circle_2, active_game.screen_width)) {
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

}
