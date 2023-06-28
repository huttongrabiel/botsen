#pragma once

#include <RaylibCircleExt.h>
#include <GameData.h>

namespace UI {

void update_and_draw_home(const GameData::Game& active_game);
void update_and_draw_circles(const GameData::Game& active_game, RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2);

}
