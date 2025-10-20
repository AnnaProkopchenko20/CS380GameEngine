#pragma once
#include "Context.h"
#include "RendererSettings.h"

#include <unordered_map>
#include <string>

class Renderer {
private:
    std::unordered_map<std::string, sf::Texture*> textures;
public:
    void draw_game(Context& context, sf::RenderWindow& window);
    void draw_pause(sf::RenderWindow& window);
    Renderer();
    ~Renderer();
};

