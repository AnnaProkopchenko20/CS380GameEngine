#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GameEngine.h"
#include "Renderer.h"

class Game {
private:
    sf::RenderWindow window;
    void create_window();
    GameEngine game_logic;
    Renderer renderer;
    Context context;
    std::vector<Command> get_keyboard_inputs();
public:
    void start();
    Game();
    ~Game();
};

