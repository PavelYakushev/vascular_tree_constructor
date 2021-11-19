//
// Created by theophrastus on 01.10.2021.
//

#ifndef VASCULAR_TREE_FRACTALIZER_POINT_HPP
#define VASCULAR_TREE_FRACTALIZER_POINT_HPP

#include <cmath>

struct Point {
    double x, y, z;
};

double distance(const Point p_1, const Point p_2) {
    return sqrt(pow(p_1.x - p_2.x, 2) + pow(p_1.y - p_2.y, 2) +
                pow(p_1.z - p_2.z, 2));
}


#endif //VASCULAR_TREE_FRACTALIZER_POINT_HPP
