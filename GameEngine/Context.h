#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vec2.hpp> 
#include "RenderSnapshot.h"

enum class Command {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Context{
public:
	void update(std::vector<Command> commands);
	std::vector<Command>& get_commands();
	int get_frame_delta();
	void update(int frame_delta_in_miliseconds);
	void update(std::vector<RenderSnapshot> object_snapshots);
	std::vector<RenderSnapshot> get_object_snapshots();
private:
	int _frame_delta_in_miliseconds{};
	std::vector<Command> _commands;
	std::vector<RenderSnapshot> _object_snapshots;
};


