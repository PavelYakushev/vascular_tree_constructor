//
// Created by theophrastus on 01.10.2021.
//

#ifndef VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP
#define VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP

#include "Point.hpp"

class Vascular_tree_node {
public:
    Point coords;
    Vascular_tree_node * left;
    Vascular_tree_node * right;
    explicit Vascular_tree_node(Point coords);
    void bifurcate();
};


#endif //VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP
