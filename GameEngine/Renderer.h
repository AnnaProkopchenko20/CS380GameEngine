#pragma once
#include "Context.h"
#include "RendererSettings.h"
class Renderer {
public:
    void draw_game(Context& context, sf::RenderWindow& window);
    void draw_pause(sf::RenderWindow& window);
};

