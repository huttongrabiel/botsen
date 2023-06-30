#include <Collisions.h>

namespace Collision {

void simulate_elastic_collision(RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2) {
    double m1 = circle_1.mass();
    double m2 = circle_2.mass();
    double v1i = circle_1.velocity();
    double v2i = circle_2.velocity();

    // For the math on computing final velocities, see https://www.khanacademy.org/science/physics/linear-momentum/elastic-and-inelastic-collisions/a/what-are-elastic-and-inelastic-collisions
    double v1f = (((m1 - m2) / (m1 + m2)) * v1i) + (((2 * m2) / (m1 + m2)) * v2i);
    double v2f = (((2 * m1) / (m1 + m2)) * v1i) + (((m2 - m1) / (m1 + m2)) * v2i);

    circle_1.set_velocity(v1f);
    circle_2.set_velocity(v2f);
}

void simulate_inelastic_collision(RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2) {
    // We define the objects as being of mass m1 and m2, respectively. With inital velocities of v1i and v2i respectively.
    double m1 = circle_1.mass();
    double m2 = circle_2.mass();
    double v1i = circle_1.velocity();
    double v2i = circle_2.velocity();

    // m1v1i + m2v2i = (m1 + m2)vf
    // vf = (m1v1i + m2v2i) / (m1+m2)
    double numerator = ((m1 * v1i) + (m2 * v2i));
    double denominator = (m1 + m2);
    double final_velocity = numerator / denominator;

    circle_1.set_velocity(final_velocity);
    circle_2.set_velocity(final_velocity);
}

// Checks if a ball has hit either the left or right edge of the screen
bool has_collided_with_edge(const RaylibExt::raylibCircleExt& circle, int screen_width) {
    int center_x = circle.center().x;
    int radius = circle.radius();
    bool hit_left_edge = center_x - radius <= 0;
    bool hit_right_edge = center_x + radius >= screen_width;
    return hit_left_edge || hit_right_edge;
}

}
