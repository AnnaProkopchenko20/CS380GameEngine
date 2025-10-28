#include "Context.h"

void Context::update(std::vector<Command> commands) {
	_commands = commands;
};

void Context::update(std::vector<RenderSnapshot> object_snapshots) {
	_object_snapshots = object_snapshots;
}

std::vector<Command>& Context::get_commands() {
	return _commands;
};

int Context::get_frame_delta() {
	return _frame_delta_in_miliseconds;
}

std::vector<RenderSnapshot> Context::get_object_snapshots() {
	return _object_snapshots;
};

void Context::update(int frame_delta_in_miliseconds) {
	_frame_delta_in_miliseconds = frame_delta_in_miliseconds;
};

void Context::flip_renderer_mode() {
	renderer_bounding_boxes = !renderer_bounding_boxes;
};

bool Context::get_render_mode() {
	return renderer_bounding_boxes;
};