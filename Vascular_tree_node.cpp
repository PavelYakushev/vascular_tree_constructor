//
// Created by theophrastus on 01.10.2021.
//

#include "Vascular_tree_node.hpp"
#include "constants.hpp"


Force Vascular_tree_node::pull_force(Vascular_tree_node &node) const {
    return -pow(node.radius, constants::beta) * (node.coords - coords).normalized();
}

Force Vascular_tree_node::gradient() const {
    Force res{0, 0, 0};
    res += pull_force(*parent);

    for (auto child: children) {
        res += pull_force(*child);
    }

    return res;
}

double Vascular_tree_node::cost() const{
    double res = pow(parent->radius, constants::beta) * distance(parent->coords, coords);

    for (auto child: children) {
        res += pow(child->radius, constants::beta) * distance(child->coords, coords);
    }

    return res;
}

Vascular_tree_node::Vascular_tree_node(const Point coords, Vascular_tree_node *parent, const bool is_terminal) :
    coords{coords},
    parent{parent},
    is_terminal{is_terminal},
    radius{0.0},
    order{1} {
}
