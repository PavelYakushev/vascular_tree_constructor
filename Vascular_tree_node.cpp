//
// Created by theophrastus on 01.10.2021.
//

#include "Vascular_tree_node.hpp"
Vascular_tree_node::Vascular_tree_node(const Point &coords, const int &height):
    coords{coords},
    height{height},
    left{nullptr},
    right{nullptr} {}

Vascular_tree_node::Vascular_tree_node(const Vascular_tree_node &node) = default;

Vascular_tree_node::~Vascular_tree_node() {
    delete left;
    delete right;
}
