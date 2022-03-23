//
// Created by theophrastus on 01.10.2021.
//

#ifndef VASCULAR_TREE_FRACTALIZER_SPACE_HPP
#define VASCULAR_TREE_FRACTALIZER_SPACE_HPP

#include <cmath>

struct Vector {
    double x, y, z;
    Vector &operator+=(const Vector &v);
    Vector operator+(const Vector &v) const;
    Vector operator-(const Vector &v) const;
    Vector operator-() const;
    Vector(double x, double y, double z);
    double norm() const;
    Vector normalized() const;
};

typedef Vector Point;

typedef Vector Force;

double distance(const Point &p1, const Point &p2);

Vector operator*(const double a, const Vector &v);

Vector operator*(const Vector &v, const double a);

#endif //VASCULAR_TREE_FRACTALIZER_SPACE_HPP
