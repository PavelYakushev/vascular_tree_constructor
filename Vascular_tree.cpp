//
// Created by theophrastus on 01.10.2021.
//

#include "Predicates.hpp"
#include "Vascular_tree.hpp"


Vascular_tree::Vascular_tree(const Vascular_tree_node &root,
    const std::vector<Point> &leaf_coords):
    root(root) {
    for (auto coords: leaf_coords) {
        leaves.emplace_back(Vascular_tree_node(coords));
    }
}


void Vascular_tree::prune(int order) {

}


void Vascular_tree::connect() {
    for (auto &leaf : leaves) {
        Find_closest_node min_distance(leaf, root);

        depth_first_search(root, min_distance);

        auto closest_node = *min_distance.get_node_ptr();
        closest_node.children.push_back(&leaf);
    }
}


void Vascular_tree::relax() {

}


void Vascular_tree::merge() {

}


void Vascular_tree::split() {

}


void Vascular_tree::branch() {

}


void Vascular_tree::depth_first_search(Vascular_tree_node &node, Predicate &predicate) {
    for (auto &child_ptr: node.children) {
        depth_first_search(*child_ptr, predicate);
    }
    predicate(node);
}
