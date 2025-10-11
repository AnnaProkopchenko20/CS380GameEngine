#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vec2.hpp> 
#include "ObjectSnapshot.h"

enum class Command {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Context{
public:
	void update(std::vector<Command> commands);
	std::vector<Command> get_commands();
	int get_frame_delta();
	void update(int frame_delta_in_miliseconds);
	void update(std::vector<ObjectSnapshot> object_snapshots);
	std::vector<ObjectSnapshot> get_object_snapshots();
private:
	int _frame_delta_in_miliseconds;
	std::vector<Command> _commands;
	std::vector<ObjectSnapshot> _object_snapshots;
};


