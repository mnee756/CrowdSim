#include "Vector2D.h"
#include <cmath>


Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(double scalar) const {
    return Vector2D(x / scalar, y / scalar);
}

double Vector2D::magnitude() const {
    return std::sqrt(x * x + y * y);
}

