#pragma once

#include <RaylibCircleExt.h>
#include <GameData.h>

namespace UI {

void update_and_draw_home(GameData::Game& active_game);
void draw_collision_select_buttons(GameData::Game& active_game, int title_position_x, int title_position_y);
void update_and_draw_circles(const GameData::Game& active_game, RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2);

}
