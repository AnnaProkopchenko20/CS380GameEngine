#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vec2.hpp>  
#include "Game.h"


int main()
{
    Game* game = new Game();
    game->start();
    delete game;
}
