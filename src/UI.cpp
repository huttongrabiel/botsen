#include <raylib.h>
#include <string>

#include <Collisions.h>
#include <UI.h>
#include <GameData.h>
#include <Object.h>

namespace UI {

void update_and_draw_home(GameData::Game& active_game) {
    // Draw title and instructions
    const char* title = "Collision Simulator!";
    int title_font_size = 40;
    int title_length = MeasureText(title, title_font_size);
    int title_position_x = (active_game.screen_width / 2) - (title_length / 2);
    int title_position_y = (active_game.screen_height / 2) - 60;
    DrawText("Collision Simulator!", title_position_x, title_position_y, title_font_size, DARKPURPLE);

    std::string space_message = "Press SPACE to simulate ";
    switch (active_game.current_collision_type) {
    case GameData::CollisionType::ELASTIC:
        space_message.append("elastic");
        break;
    case GameData::CollisionType::INELASTIC:
        space_message.append("inelastic");
        break;
    }
    space_message.append(" collision");

    auto space_message_c_str = space_message.c_str();
    int space_message_font_size = 20;
    int space_message_length = MeasureText(space_message_c_str, space_message_font_size);
    int space_message_position_x = (active_game.screen_width / 2) - (space_message_length / 2);
    int space_message_position_y = (active_game.screen_height / 2) - 15;
    DrawText(space_message_c_str, space_message_position_x, space_message_position_y, space_message_font_size, DARKPURPLE);

    // Draw buttons to select either elastic or inelastic collision
    draw_collision_select_buttons(active_game, title_position_x, title_position_y);
}

void draw_collision_select_buttons(GameData::Game& active_game, int title_position_x, int title_position_y) {
    constexpr int button_width = 120;
    constexpr int button_height = 60;
    constexpr int distance_between_buttons = 225;
    constexpr int button_font_size = 20;

    Color elastic_button_color = active_game.current_collision_type == GameData::CollisionType::ELASTIC ? PURPLE : DARKPURPLE;
    Color inelastic_button_color = active_game.current_collision_type == GameData::CollisionType::INELASTIC ? PURPLE : DARKPURPLE;

    int elastic_button_x_pos = title_position_x;
    int inelastic_button_x_pos = title_position_x + distance_between_buttons;
    int button_y_pos = active_game.screen_height - 250;

    int elastic_text_x_pos = title_position_x + (button_width/2) - (MeasureText("Elastic", button_font_size)/2);
    int inelastic_text_x_pos = title_position_x + distance_between_buttons + (button_width/2) - (MeasureText("Inelastic", button_font_size)/2);
    int elastic_text_y_pos = button_y_pos + (button_height/2) - 10;

    Vector2 mouse_pos = GetMousePosition();
    bool mouse_in_elastic_button_x = mouse_pos.x >= elastic_button_x_pos && mouse_pos.x <= elastic_button_x_pos + button_width;
    bool mouse_in_inelastic_button_x = mouse_pos.x >= inelastic_button_x_pos && mouse_pos.x <= inelastic_button_x_pos + button_width;
    bool mouse_in_button_y = mouse_pos.y >= button_y_pos && mouse_pos.y <= button_y_pos + button_height;

    if (mouse_in_button_y) {
        if (mouse_in_elastic_button_x) {
            elastic_button_color = PURPLE;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                active_game.current_collision_type = GameData::CollisionType::ELASTIC;
            }
        } else if (mouse_in_inelastic_button_x) {
            inelastic_button_color = PURPLE;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                active_game.current_collision_type = GameData::CollisionType::INELASTIC;
            }
        }
    }

    DrawRectangle(elastic_button_x_pos, button_y_pos, button_width, button_height, elastic_button_color);
    DrawRectangle(inelastic_button_x_pos, button_y_pos, button_width, button_height, inelastic_button_color);
    DrawText("Elastic", elastic_text_x_pos, elastic_text_y_pos, button_font_size, WHITE);
    DrawText("Inelastic", inelastic_text_x_pos, elastic_text_y_pos, button_font_size, WHITE);
}

void update_and_draw_circles(const GameData::Game& active_game, RaylibExt::raylibCircleExt& circle_1, RaylibExt::raylibCircleExt& circle_2) {
    bool have_collided = CheckCollisionCircles(
                {static_cast<float>(circle_1.center().x), static_cast<float>(circle_1.center().y)},
                circle_1.radius(),
                {static_cast<float>(circle_2.center().x), static_cast<float>(circle_2.center().y)},
                circle_2.radius());

    if (Collision::has_collided_with_edge(circle_1, active_game.screen_width)) {
        circle_1.negate_velocity();
    }
    if (Collision::has_collided_with_edge(circle_2, active_game.screen_width)) {
        circle_2.negate_velocity();
    }

    if (have_collided) {
        switch (active_game.current_collision_type) {
        case GameData::CollisionType::ELASTIC:
            Collision::simulate_elastic_collision(circle_1, circle_2);
            break;
        case GameData::CollisionType::INELASTIC:
            Collision::simulate_inelastic_collision(circle_1, circle_2);
            break;
        }
    }

    int circle_1_new_x_pos = circle_1.center().x + circle_1.velocity();
    int circle_2_new_x_pos = circle_2.center().x + circle_2.velocity();
    circle_1.update_circle_center({ circle_1_new_x_pos, circle_1.center().y});
    circle_2.update_circle_center({ circle_2_new_x_pos, circle_2.center().y});

    DrawCircle(circle_1.center().x, circle_1.center().y, circle_1.radius(), RED);
    DrawCircle(circle_2.center().x, circle_2.center().y, circle_1.radius(), BLUE);
}

}
