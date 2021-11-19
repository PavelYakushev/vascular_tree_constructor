//
// Created by theophrastus on 08.10.2021.
//

#include "Arterial_tree.hpp"

void Arterial_tree::import(const std::string &) {
    //TODO
}

void Arterial_tree::branch() {
    if(leaves.empty()) {
        root = new Vascular_tree_node(Point{0.0,0.0,0.0},1);
        leaves.emplace_front(root);
    } else {
        for(auto iterator = leaves.begin(); iterator != leaves.end(); iterator++) {
            bifurcate(*iterator);
            leaves.insert(iterator, (*iterator)->left);
            leaves.insert(iterator, (*iterator)->right);
            iterator = leaves.erase(iterator);
        }
    }
}

void Arterial_tree::bifurcate(Vascular_tree_node *node_ptr) {
    enum {left_branch, right_branch};
    Point branches[2];
    do {
        gen_branches(node_ptr->coords, branches);
    } while (intersects(node_ptr->coords, branches));
    node_ptr->left = new Vascular_tree_node(branches[left_branch], node_ptr->height + 1);
    node_ptr->right = new Vascular_tree_node(branches[right_branch], node_ptr->height + 1);
}

void Arterial_tree::gen_branches(const Point base, Point *branches) {
    //TODO
}

Arterial_tree::~Arterial_tree() = default;
