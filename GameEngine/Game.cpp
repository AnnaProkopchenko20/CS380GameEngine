#include "Game.h"


void Game::create_window() {
    window.create(sf::VideoMode(GameSettings::screen_width_px, GameSettings::screen_height_px), GameSettings::window_name, GameSettings::window_style);
    window.setFramerateLimit(GameSettings::framerate_limit);
}

void Game::start() {

    sf::Clock clock;

    while (window.isOpen())
    {
        
        sf::Time elapsed = clock.restart();
        
        sf::Event event;
        while (window.pollEvent(event))
        { 
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (window.hasFocus()) {
            context.update(get_keyboard_inputs());
            context.update(std::min(elapsed.asMilliseconds(),top_limit_of_elapsed));
            game_logic.update(context);
            renderer.draw(context, window);
        }
      
    }

};


std::vector<Command> Game::get_keyboard_inputs() {

    std::vector<Command> pressed_keys = std::vector<Command>();
    for (auto kvp : GameSettings::sfml_keys_to_local_program_commands) {
        if (sf::Keyboard::isKeyPressed(kvp.first)) {
            pressed_keys.push_back(kvp.second);
        }
    }
    return pressed_keys;
}

Game::Game() {
    create_window();
    context = Context();
    game_logic = GameEngine();
    renderer = Renderer();
}

Game::~Game(){};