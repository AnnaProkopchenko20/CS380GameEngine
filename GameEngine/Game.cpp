#include "Game.h"


void Game::create_window() {
    window.create(sf::VideoMode(GameSettings::screen_width_px, GameSettings::screen_height_px), GameSettings::window_name, GameSettings::window_style);
    window.setFramerateLimit(GameSettings::framerate_limit);
}

void Game::start() {

    sf::Clock clock;

    bool is_game_paused = false;

    while (window.isOpen())
    {
        
        sf::Time elapsed = clock.restart();
        
        sf::Event event;
        while (window.pollEvent(event))
        { 
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    is_game_paused = !is_game_paused;
                }
            }
        }

        if (!window.hasFocus()) {
            continue;
        }


        if (is_game_paused) {
            try{
                renderer.draw_pause(window);
            }
            catch (std::runtime_error) {
                printf("issue with renderer dependencies");
                exit(0);
            }
            
        }
        else {
            context.update(get_keyboard_inputs());
            context.update(std::min(elapsed.asMilliseconds(), GameSettings::top_limit_of_elapsed_time_in_miliseconds));
            game_logic->update(context);
            try {
                renderer.draw_game(context, window);
            }
            catch (std::runtime_error) {
                printf("issue with renderer dependencies");
                exit(0);
            }
            
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
    game_logic = new GameLogic();
    renderer = Renderer();
}

Game::~Game(){
    delete game_logic;
};