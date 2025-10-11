#pragma once

#include <string>

namespace GameSettings
{

	const int screen_width_px = 1300;
	const int screen_height_px = 1300;
	const std::string window_name = "Basic game window";
	const auto window_style = sf::Style::Close;
	const int framerate_limit = 60;
	const int top_limit_of_elapsed_time_in_miliseconds = 20;

	const std::map<sf::Keyboard::Key, Command> sfml_keys_to_local_program_commands = {
	{sf::Keyboard::Left, Command::LEFT},
	{sf::Keyboard::Right, Command::RIGHT},
	{sf::Keyboard::Up, Command::UP},
	{sf::Keyboard::Down, Command::DOWN}
	};

};

