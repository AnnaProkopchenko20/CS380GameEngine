#pragma once
#include "BoundingShape.h"
#include "Circle.h"
#include "AABBShape.h"
#include <vec2.hpp> 
#include <common.hpp>
#include <geometric.hpp>

class CollisionAlgorithms {
public:
    static bool circle_and_circle_collision(const BoundingShape* circle_1, const BoundingShape* circle_2) {
        const Circle* c1 = dynamic_cast<const Circle*>(circle_1);
        const Circle* c2 = dynamic_cast<const Circle*>(circle_2);
        return glm::length(c1->_center - c2->_center) < c1->_radius + c2->_radius;

    };
    static bool circle_and_aabb_collision(const BoundingShape* circle, const BoundingShape* rect) {
        const Circle* c = dynamic_cast<const Circle*>(circle);
        const AABBShape* r = dynamic_cast<const AABBShape*>(rect);

        glm::vec2 aabb_half_extents(r->_size.x / 2, r->_size.y / 2);
        glm::vec2 aabb_center(r->_pos.x + aabb_half_extents.x, r->_pos.y + aabb_half_extents.y);
        glm::vec2 difference = c->_center - aabb_center;
        glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);
        glm::vec2 closest = aabb_center + clamped;
        difference = closest - c->_center;

        return glm::length(difference) < c->_radius;
    };
    static bool aabb_and_aabb_collision(const  BoundingShape* rect_1, const BoundingShape* rect_2) {
        const AABBShape* r1 = dynamic_cast<const AABBShape*>(rect_1);
        const AABBShape* r2 = dynamic_cast<const AABBShape*>(rect_2);

        bool collision_x_axis = r1->_pos.x + r1->_size.x >= r2->_pos.x && r2->_pos.x + r2->_size.x >= r1->_pos.x;
        bool collision_y_axis = r1->_pos.y + r1->_size.y >= r2->_pos.y && r2->_pos.y + r2->_size.y >= r1->_pos.y;

        return collision_x_axis && collision_y_axis;

    };

    static glm::vec2 resolve_aabb_and_aabb_wall(const BoundingShape* dynamic_rect, const BoundingShape* static_rect) {
        const AABBShape* r1 = dynamic_cast<const AABBShape*>(dynamic_rect);
        const AABBShape* r2 = dynamic_cast<const AABBShape*>(static_rect);

        glm::vec2 aabb_half_extents_1(r1->_size.x / 2, r1->_size.y / 2);
        glm::vec2 aabb_center_1(r1->_pos.x + aabb_half_extents_1.x, r1->_pos.y + aabb_half_extents_1.y);

        glm::vec2 aabb_half_extents_2(r2->_size.x / 2, r2->_size.y / 2);
        glm::vec2 aabb_center_2(r2->_pos.x + aabb_half_extents_2.x, r2->_pos.y + aabb_half_extents_2.y);

        glm::vec2 difference = aabb_center_1 - aabb_center_2;

        glm::vec2 intersect = (aabb_half_extents_1 + aabb_half_extents_2) - glm::abs(difference);

        if (intersect.x <= 0 || intersect.y <= 0) {
            return glm::vec2(0, 0);
        }

        if (intersect.x < intersect.y) {

            if (difference.x > 0) {
                return  glm::vec2(1, 0) ;  
            } 
            else {
                return glm::vec2(-1, 0) ; 
            }
        } else {

            if (difference.y > 0) {
                return glm::vec2(0, 1) ; 
            } 
            else {
                return glm::vec2(0, -1); 
            }
        }
    };
};
