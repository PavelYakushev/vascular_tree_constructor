//
// Created by theophrastus on 01.10.2021.
//

#ifndef VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP
#define VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP

#include "Vascular_tree_node.hpp"
#include "Point.hpp"

class Vascular_tree {
public:
    explicit Vascular_tree(Point root_coords);
    Vascular_tree();
    virtual ~Vascular_tree() = 0;

private:
    Vascular_tree_node * root;
};


#endif //VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP
