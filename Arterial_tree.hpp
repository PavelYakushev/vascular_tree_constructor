//
// Created by theophrastus on 08.10.2021.
//

#ifndef VASCULAR_TREE_FRACTALIZER_ARTERIAL_TREE_HPP
#define VASCULAR_TREE_FRACTALIZER_ARTERIAL_TREE_HPP

#include "Vascular_tree.hpp"
#include <string>

class Arterial_tree: public Vascular_tree {
public:
    void import(const std::string &);
    void branch() override;
    ~Arterial_tree() override;

private:
    void bifurcate(Vascular_tree_node *);
    void gen_branches(const Point base, Point branches[2]);
};


#endif //VASCULAR_TREE_FRACTALIZER_ARTERIAL_TREE_HPP
