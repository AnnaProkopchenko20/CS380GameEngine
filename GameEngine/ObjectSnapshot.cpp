#include "ObjectSnapshot.h"

ObjectSnapshot::ObjectSnapshot(const glm::vec2& coord, ObjectType type, int id, const glm::vec2& rotation) : 
	_coord(coord), 
	_type(type), 
	_id(id), 
	_rotation(rotation) {};

ObjectSnapshot::~ObjectSnapshot() {};
