#pragma once

#include <RaylibCircleExt.h>

namespace Collision {

// Detects wheter a ball has collided with either the left or right edge of the screen
bool has_collided_with_edge(const RaylibExt::raylibCircleExt& circle, int screen_width);

// Update the position and velocity of the two circles to be in accord with an elastic collision
//
// Directions are switched and the two items switch velocities.
void simulate_elastic_collision(RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2);

void simulate_inelastic_collision(RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2);

void simulate_totally_inelastic_collision(RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2);

}
