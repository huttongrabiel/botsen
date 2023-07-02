#pragma once

#include <RaylibCircleExt.h>
#include <GameData.h>

namespace UI {

void reset_simulation(GameData::Game& active_game, RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2);
void update_and_draw_home(GameData::Game& active_game);
void draw_collision_select_buttons(GameData::Game& active_game, int title_position_x, int title_position_y);
void update_and_draw_circles(GameData::Game& active_game, RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2);

static constexpr int circle_radius = 40;
static constexpr double ball_velocity = 5.0;
static constexpr int circle_mass = 5;
}
