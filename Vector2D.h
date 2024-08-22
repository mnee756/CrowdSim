#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
public:
    double x, y;

    Vector2D(double x = 0, double y = 0);

    double& operator[](int index);
    const double& operator[](int index) const;
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(double scalar) const;
    Vector2D operator/(double scalar) const;
    bool operator!=(const Vector2D& other) const;
    double magnitude() const;
    double dot(const Vector2D& other) const;
    double angleBetween(const Vector2D& other) const;
    double distanceBetween(const Vector2D& other) const;
    Vector2D normalize() const;
};

#endif // VECTOR2D_H
