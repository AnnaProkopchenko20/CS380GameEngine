#include "Game.h"


void Game::create_window() {
    window.create(sf::VideoMode(1300, 1300), "basic game window", sf::Style::Close);
    window.setFramerateLimit(60);
}

void Game::start() {

    sf::Clock clock;
    int top_limit_of_elapsed = 20;

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

std::map<sf::Keyboard::Key, Command> sfml_keys_to_local_program_commands = {
	{sf::Keyboard::Left, Command::LEFT},
	{sf::Keyboard::Right, Command::RIGHT},
	{sf::Keyboard::Up, Command::UP},
	{sf::Keyboard::Down, Command::DOWN}
};
std::vector<Command> Game::get_keyboard_inputs() {

    std::vector<Command> pressed_keys = std::vector<Command>();
    for (auto kvp : sfml_keys_to_local_program_commands) {
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