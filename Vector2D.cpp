#include "Vector2D.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

double& Vector2D::operator[](int index) {
    if (index == 0) return x;
    if (index == 1) return y;
    throw std::out_of_range("Index out of range");  // Handle out of range errors
}

// Overload the [] operator for const access
const double& Vector2D::operator[](int index) const {
    if (index == 0) return x;
    if (index == 1) return y;
    throw std::out_of_range("Index out of range");  // Handle out of range errors
}

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

bool Vector2D::operator!=(const Vector2D& other) const {
    return x != other.x || y != other.y;
}

double Vector2D::magnitude() const {
    return std::sqrt(x * x + y * y);
}

double Vector2D::dot(const Vector2D& other) const {
    return this->x * other.x + this->y * other.y;
}

double Vector2D::angleBetween(const Vector2D& other) const {
    double dotProduct = this->dot(other);
    double magnitudeU = this->magnitude();
    double magnitudeV = other.magnitude();

    // Compute the cosine of the angle
    double cosTheta = dotProduct / (magnitudeU * magnitudeV);

    // Clamp the value to the range [-1, 1] to avoid domain errors in acos
    cosTheta = std::max(-1.0, std::min(1.0, cosTheta));

    // Compute the angle in radians
    return acos(cosTheta);
}

double Vector2D::distanceBetween(const Vector2D& other) const {
    double dx = other.x - this->x;
    double dy = other.y - this->y;
    return std::sqrt(dx * dx + dy * dy);
}

Vector2D Vector2D::normalize() const {
    double mag = magnitude();
    if (mag == 0) {
        return Vector2D(0, 0);
    }
    return *this / mag;
}