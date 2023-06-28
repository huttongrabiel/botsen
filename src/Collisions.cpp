#include <Collisions.h>

namespace Collision {

void simulate_elastic_collision(RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2) {
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

// TODO: Implement collision simulation
void simulate_inelastic_collision(RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2) {}

// TODO: Implement collision simulation
void simulate_totally_inelastic_collision(RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2) {}

// Checks if a ball has hit either the left or right edge of the screen
bool has_collided_with_edge(const RaylibExt::raylibCircleExt& circle, int screen_width) {
    int center_x = circle.center().x;
    int radius = circle.radius();
    bool hit_left_edge = center_x - radius <= 0;
    bool hit_right_edge = center_x + radius >= screen_width;
    return hit_left_edge || hit_right_edge;
}

}
