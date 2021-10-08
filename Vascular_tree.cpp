//
// Created by theophrastus on 01.10.2021.
//

#include "Vascular_tree.hpp"

Vascular_tree::Vascular_tree(): root{nullptr}, leaves{} {}

Vascular_tree::~Vascular_tree() {
    delete root;
}

bool Vascular_tree::intersects(const Point &base, const Point branches[2]) {
    return false;
}
