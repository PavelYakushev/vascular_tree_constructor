//
// Created by theophrastus on 01.10.2021.
//

#ifndef VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP
#define VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP

#include "space.hpp"
#include <memory>
#include <forward_list>

struct Vascular_tree_node {
    bool is_terminal;
    int order;
    double radius;
    Point coords;
    std::weak_ptr<Vascular_tree_node> parent;
    std::forward_list<std::shared_ptr<Vascular_tree_node>> children;
    double cost() const;
    Force pull_force(Vascular_tree_node &node) const;
    Force gradient() const;
    explicit Vascular_tree_node(const Point coords, Vascular_tree_node *parent = nullptr, const bool is_terminal = false);
};

#endif //VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_NODE_HPP
