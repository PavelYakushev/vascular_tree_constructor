//
// Created by theophrastus on 01.10.2021.
//

#ifndef VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP
#define VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP

#include "Vascular_tree_node.hpp"
#include "Point.hpp"
#include <list>

class Vascular_tree {
public:
    Vascular_tree();
    virtual void branch() = 0;
    virtual ~Vascular_tree();

protected:
    Vascular_tree_node * root;
    std::list<Vascular_tree_node *> leaves;
    static bool intersects(const Point&, const Point []);
};


#endif //VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP
