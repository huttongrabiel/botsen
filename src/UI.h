#pragma once

#include <RaylibCircleExt.h>
#include <GameData.h>

namespace UI {

// 'Public' methods
void reset_simulation(GameData::Game& active_game, RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2);
void update_and_draw_home(GameData::Game& active_game);
void update_and_draw_simulation(GameData::Game& active_game, RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2);

// 'Private' methods
void _draw_simulation_text(GameData::Game& active_game);
void _draw_collision_select_buttons(GameData::Game& active_game, int title_position_x, int title_position_y);
void _update_and_draw_circles(GameData::Game& active_game, RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2);

static constexpr int circle_radius = 40;
static constexpr double ball_velocity = 5.0;
static constexpr int circle_mass = 5;
}
