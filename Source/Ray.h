#pragma once
#include "Color.h"
#include <glm/glm.hpp>

struct ray_t {

    glm::vec3 origin{ 0.0f };
    glm::vec3 direction{ 0.0f };

    ray_t() = default;

    ray_t(const glm::vec3& origin, const glm::vec3& direction)
        : origin(origin), direction(glm::normalize(direction)) {
    }

    glm::vec3 at(float t) const {
        return origin + direction * t;
    }

    glm::vec3 operator*(float t) const {
        return at(t);
    }

    struct raycastHit_t {
        glm::vec3 point{ 0.0f };
        glm::vec3 normal{ 0.0f };
        float distance{ 0.0f };
        
    };
};
