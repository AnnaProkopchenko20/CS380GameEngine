#pragma once
#include <vec2.hpp>
#include <string>

class RenderSnapshot {

public:
   glm::vec2 _coord;
   glm::vec2 _rotation;
   std::string _picture_name;
   std::string _base_shape;

   RenderSnapshot(const glm::vec2& coord, const glm::vec2& rotation, std::string picture_name, std::string base_shape);
   ~RenderSnapshot();

   RenderSnapshot& operator=(const RenderSnapshot& other) {
        _coord = glm::vec2(other._coord);
        _rotation = other._rotation;
        _picture_name = other._picture_name;
        _base_shape = other._base_shape;
        return *this;
    };
};



