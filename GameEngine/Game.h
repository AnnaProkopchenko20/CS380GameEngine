#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GameLogic.h"
#include "Renderer.h"
#include "GameSettings.h"

class Game {
private:
    sf::RenderWindow window;
    void create_window();
    GameLogic* game_logic;
    Renderer renderer;
    Context context;
    std::vector<Command> get_keyboard_inputs();
public:
    void start();
    Game();
    ~Game();
};

