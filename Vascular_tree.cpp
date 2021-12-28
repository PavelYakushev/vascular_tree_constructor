//
// Created by theophrastus on 01.10.2021.
//

#include "Predicates.hpp"
#include "Vascular_tree.hpp"

#include <utility>


Vascular_tree::Vascular_tree(Vascular_tree_node root, const std::vector<Point> &leaf_coords)
    : root(std::move(root)) {
    for (auto coords: leaf_coords) {
        leaves.emplace_back(Vascular_tree_node(coords));
    }
}


void Vascular_tree::prune(int order) {
    Delete_low_order_nodes p(order);
    apply_to_all(root, p);
}


void Vascular_tree::connect() {
    for (auto &leaf : leaves) {
        Find_closest_node p(leaf);

        apply_to_all(root, p);

        auto closest_node = *p.get_node_ptr();
        closest_node.children.push_back(&leaf);
    }

    Calculate_orders o;
    apply_to_all(root, o);

    Calculate_radii r;
    apply_to_all(root, o);
}


void Vascular_tree::relax() {
    Relax p;
    apply_to_all(root, p);
}


void Vascular_tree::merge() {
    Merge_adjacent_nodes p;
    apply_to_all(root, p);
}


void Vascular_tree::split() {
    Split p;
    apply_to_all(root, p);
}


void Vascular_tree::branch() {
    connect();
    relax();
    merge();
    split();
}


void Vascular_tree::apply_to_all(Vascular_tree_node &node, Predicate &predicate) {
    for (auto &child_ptr: node.children) {
        apply_to_all(*child_ptr, predicate);
    }
    predicate(node);
}

Vascular_tree::~Vascular_tree() {
    Hard_delete p;
    apply_to_all(root, p);
}
