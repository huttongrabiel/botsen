#pragma once

namespace GameData {

enum class Scenes {
    HOME,
    COLLISION
};

struct Game {
    int screen_width;
    int screen_height;
    GameData::Scenes current_scene = GameData::Scenes::HOME;
};

}
