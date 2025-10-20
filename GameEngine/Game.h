#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GameLogic.h"
#include "Renderer.h"
#include "GameSettings.h"

#include <unordered_map>
#include <string>

class Game {
private:
    sf::RenderWindow window;
    void create_window();
    GameLogic* game_logic;
    Renderer renderer;
    Context context;


    std::vector<Command> get_command_inputs();
 
    void set_listened_keyboard_inputs();
    void reset_keyboard_inputs();
    std::unordered_map<sf::Keyboard::Key, bool> is_key_pressed;

public:
    void start();
    Game();
    ~Game();
};

