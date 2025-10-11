#pragma once
#include "ObjectType.h"
#include <vec2.hpp>
 
class ObjectSnapshot {
public:
   glm::vec2 _coord;
    ObjectType _type;
    int _id;
    glm::vec2 _rotation;
    ObjectSnapshot(const glm::vec2& coord, ObjectType type, int id, const glm::vec2& rotation);
    ~ObjectSnapshot();
    ObjectSnapshot& operator=(const ObjectSnapshot& obj) {
        _coord = glm::vec2(obj._coord);
        _id = obj._id;
        _type = obj._type;
        _rotation = obj._rotation;
        return *this;
    };
};



