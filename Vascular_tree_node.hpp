//
// Created by theophrastus on 01.10.2021.
//

#ifndef VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP
#define VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP

#include "Point.hpp"

struct Vascular_tree_node {
    Point coords;
    int height;
    Vascular_tree_node * left;
    Vascular_tree_node * right;
    Vascular_tree_node(const Point &, const int &);
    Vascular_tree_node(const Vascular_tree_node &);
    ~Vascular_tree_node();
};


#endif //VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP
