#pragma once

namespace GameData {

enum class Scenes {
    HOME,
    COLLISION
};

enum class CollisionType {
    ELASTIC,
    INELASTIC,
};

struct Game {
    int screen_width;
    int screen_height;
    Scenes current_scene = GameData::Scenes::HOME;
    CollisionType current_collision_type = CollisionType::ELASTIC;
};

}
