//
// Created by theophrastus on 25.12.2021.
//
#include "space.hpp"

Vector& Vector::operator+=(const Vector &v){
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;

    return *this;
}

Vector Vector::operator+(const Vector &v) const {
    return Vector(*this) += v;
}

Vector Vector::operator-(const Vector &v) const {
    return {this->x - x, this->y - y, this->z - z};
}

Vector Vector::operator-() const {
    return {-this->x, -this->y, -this->z};
}

Vector::Vector(double x, double y, double z) :
    x{x},
    y{y},
    z{z} {
}

double Vector::norm() const {
    return sqrt(x * x + y * y + z * z);
}

Vector Vector::normalized() const {
    double n = norm();
    return {x / n, y / n, z / n};
}

Vector operator*(const double a, const Vector &v) {
    Vector w{a * v.x, a * v.y, a * v.z};
    return w;
}

Vector operator*(const Vector &v, const double a) {
    return a * v;
}

double distance(const Point &p1, const Point &p2) {
    return (p1 - p2).norm();
}
