#include "RenderSnapshot.h"

RenderSnapshot::RenderSnapshot(const glm::vec2& coord, const glm::vec2& rotation, std::string picture_name, std::string base_shape) :
	_coord(coord),
	_rotation(rotation),
	_picture_name(picture_name),
	_base_shape(base_shape)
{};

RenderSnapshot::~RenderSnapshot() {};
