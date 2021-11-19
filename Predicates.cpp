//
// Created by theophrastus on 19.11.2021.
//

#include <algorithm>
#include <cmath>
#include "Constants.hpp"
#include "Predicates.hpp"

//Find_closest_node predicate
//
Find_closest_node::Find_closest_node(
    const Vascular_tree_node &original_node,
    Vascular_tree_node &default_node
    ): current_closest_node{&default_node},
    current_min_distance{distance(original_node.coords, default_node.coords)},
    origin{original_node.coords} {}

void Find_closest_node::operator()(Vascular_tree_node &node) {
    double current_distance = distance(origin, node.coords);
    current_min_distance = fmin(current_min_distance, current_distance);
}

Vascular_tree_node *Find_closest_node::get_node_ptr() const {
    return current_closest_node;
}

double Find_closest_node::get_distance() const {
    return current_min_distance;
}


// Merge_adjacent_nodes predicate
//
void Merge_adjacent_nodes::merge(Vascular_tree_node *parent,
    Vascular_tree_node *child) {
    parent->children.erase(std::find(parent->children.begin(),
        parent->children.end(), child));

    for (auto child_ptr: child->children) {
        parent->children.push_back(child_ptr);
    }
    delete child;
}

void Merge_adjacent_nodes::operator()(Vascular_tree_node &node) {
    if (node.children.empty()) {
        return;
    }

    Find_closest_node closest(node, *node.children[0]);
    for (auto child_ptr: node.children) {
        closest(*child_ptr);
    }

    Vascular_tree_node &closest_node = *closest.get_node_ptr();
    const double min_distance = closest.get_distance();

    for (auto child_ptr: node.children) {
        if (min_distance > constants::min_difference_to_merge *
            distance(closest_node.coords, child_ptr->coords)) {
            return;
        }
    }

}
