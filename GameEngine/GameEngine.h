#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vec2.hpp> 
#include "Context.h"
#include "Player.h"

class GameEngine {
private:

    Player* player;
public:
    void update(Context& context);
    GameEngine();
    ~GameEngine();
};

