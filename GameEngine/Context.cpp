#include "Context.h"

void Context::update(std::vector<Command> commands) {
	_commands = commands;
};

void Context::update(std::vector<ObjectSnapshot> object_snapshots) {
	_object_snapshots = object_snapshots;
}

std::vector<Command>& Context::get_commands() {
	return _commands;
};

int Context::get_frame_delta() {
	return _frame_delta_in_miliseconds;
}

std::vector<ObjectSnapshot> Context::get_object_snapshots() {
	return _object_snapshots;
};

void Context::update(int frame_delta_in_miliseconds) {
	_frame_delta_in_miliseconds = frame_delta_in_miliseconds;
}