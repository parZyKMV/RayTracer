#include "Sphere.h"
#include <glm/glm.hpp>
#include "Color.h"

bool Sphere::Hit(const ray_t& ray, float minDistance, float maxDistance, ray_t::raycastHit_t& raycastHit)
{
    // vector desde el centro de la esfera hacia el rayo
    glm::vec3 oc = ray.origin - position;

    // coeficientes de la ecuación cuadrática
    float a = glm::dot(ray.direction, ray.direction);
    float b = 2.0f * glm::dot(ray.direction, oc);
    float c = glm::dot(oc, oc) - (radius * radius);

    // discriminante = b^2 - 4ac
    float discriminant = (b * b) - 4.0f * a * c;

    // si no hay soluciones reales, el rayo no toca la esfera
    if (discriminant < 0) return false;

    float sqrtD = sqrt(discriminant);

    // primera raíz (la más cercana)
    float t = (-b - sqrtD) / (2.0f * a);

    if (t > minDistance && t < maxDistance) {
        raycastHit.distance = t;
        raycastHit.point = ray.at(t); // o ray.origin + ray.direction * t
        raycastHit.normal = (raycastHit.point - position) / radius;
        raycastHit.color = color;
        return true;
    }

    // segunda raíz (más lejos)
    t = (-b + sqrtD) / (2.0f * a);

    if (t > minDistance && t < maxDistance) {
        raycastHit.distance = t;
        raycastHit.point = ray.at(t);
        raycastHit.normal = (raycastHit.point - position) / radius;
        raycastHit.color = color;
        return true;
    }

    return false;
}


