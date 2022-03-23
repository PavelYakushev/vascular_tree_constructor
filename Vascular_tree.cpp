//
// Created by theophrastus on 01.10.2021.
//

#include "Strategies.hpp"
#include "Vascular_tree.hpp"

#include <utility>


void Vascular_tree::prune(int order) {
    apply_to_all(Delete_low_order_nodes(order));
}


void Vascular_tree::connect() {
    for (auto &leaf : leaves) {
        Find_closest_node p(leaf);

        apply_to_all(p);

        auto closest_node = *p.get_node_ptr();
        closest_node.children.push_front(&leaf);
    }

    apply_to_all(Calculate_orders());
    apply_to_all(Calculate_radii());
}


void Vascular_tree::relax() {
    apply_to_all(Relax());
}


void Vascular_tree::merge() {
    apply_to_all(Merge_adjacent_nodes());
}


void Vascular_tree::split() {
    apply_to_all(Split());
}


void Vascular_tree::branch() {
    connect();
    relax();
    merge();
    split();
}



void Vascular_tree::apply_to_all(Strategy &&strategy) {
    Strategy &s = strategy;
    apply_in_depth(root, s);
}

void Vascular_tree::apply_to_all(Strategy &strategy) {
    apply_in_depth(root, strategy);
}

void Vascular_tree::apply_in_depth(Vascular_tree_node &node, Strategy &strategy) {
    for (auto &child_ptr: node.children) {
        apply_in_depth(*child_ptr, strategy);
    }
    strategy(node);
}

Vascular_tree::~Vascular_tree() {
    apply_to_all(Hard_delete());
}
