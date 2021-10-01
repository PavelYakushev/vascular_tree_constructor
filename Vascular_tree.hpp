//
// Created by theophrastus on 01.10.2021.
//

#ifndef VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP
#define VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP

#include "Vascular_tree_node.hpp"

class Vascular_tree {
public:
    Vascular_tree();
    void bifurcate();

private:
    Vascular_tree_node * root;
};


#endif //VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP
