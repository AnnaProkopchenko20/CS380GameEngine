#include "Game.h"

void Game::create_window() {
    window.create(sf::VideoMode(GameSettings::screen_width_px, GameSettings::screen_height_px), GameSettings::window_name, GameSettings::window_style);
    window.setFramerateLimit(GameSettings::framerate_limit);
}

void Game::start() {

    sf::Clock clock;
     
    bool is_focused = true;
    bool is_paused_by_user = false;
    bool is_pause_held = false;
    is_key_pressed[sf::Keyboard::Space] = false;

    while (window.isOpen())
    {
        
        sf::Time elapsed = clock.restart();
        
        sf::Event event;
        while (window.pollEvent(event))
        { 
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                is_key_pressed[event.key.code] = true;
                break;
            case sf::Event::KeyReleased:
                is_key_pressed[event.key.code] = false;
                break;
            case sf::Event::LostFocus:
                reset_keyboard_inputs();
                is_focused = false;
                break;
            case sf::Event::GainedFocus:
                is_focused = true;
                set_listened_keyboard_inputs();               
            }
            
        }

        if (!is_pause_held && is_key_pressed[sf::Keyboard::Space]) {
            is_pause_held = true;
            is_paused_by_user = !is_paused_by_user;
        }

        if (!is_key_pressed[sf::Keyboard::Space]) {
            is_pause_held = false;
        }

        bool is_game_paused = is_paused_by_user || !is_focused;

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
            context.update(get_command_inputs());
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

// feedback
// more refrences less copying
// use events keypresed rather then  always reading


// create hashmap with sprites
//enums are not ideal because require recompilation but hashmaps are better
//object contains photo hash

// factory that randomly assigns the sprite
// SETFactory
// assign the sprite at object creation

//  different object snapshots for different purposes like renderer with sprites and object colision

void Game::set_listened_keyboard_inputs() {
    for (auto kvp : GameSettings::sfml_keys_to_local_program_commands) {
        if (sf::Keyboard::isKeyPressed(kvp.first)) {
            is_key_pressed[kvp.first] = true;
        }
    }
}

void Game::reset_keyboard_inputs() {
    for (auto& kvp : is_key_pressed) {
        is_key_pressed[kvp.first] = false;
    }
}

std::vector<Command> Game::get_command_inputs() {

    std::vector<Command> pressed_keys = std::vector<Command>();
    for (auto kvp : GameSettings::sfml_keys_to_local_program_commands) {
        if (is_key_pressed[kvp.first]) {
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