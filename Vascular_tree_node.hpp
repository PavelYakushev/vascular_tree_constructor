//
// Created by theophrastus on 01.10.2021.
//

#ifndef VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP
#define VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP

#include "Point.hpp"
#include <memory>
#include <vector>

struct Vascular_tree_node {
    Point coords;
    int order;
    Vascular_tree_node *parent;
    std::vector<Vascular_tree_node *> children;
    explicit Vascular_tree_node(const Point &);
};


#endif //VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP
