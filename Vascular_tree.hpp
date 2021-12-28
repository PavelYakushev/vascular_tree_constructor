//
// Created by theophrastus on 01.10.2021.
//

#ifndef VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP
#define VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP

#include "Vascular_tree_node.hpp"
#include "space.hpp"
#include <memory>
#include <vector>

class Vascular_tree {
public:
    Vascular_tree(Vascular_tree_node root, const std::vector<Point> &leaf_coords);
    virtual ~Vascular_tree();
    virtual void branch();

protected:
    Vascular_tree_node root;
    std::vector<Vascular_tree_node> leaves;
    // static bool intersects(const Point&, const Point []);
    void connect();
    void relax();
    void merge();
    void split();
    void prune(int order);
    void apply_to_all(Vascular_tree_node &node, Predicate &predicate);
};


#endif //VASCULAR_TREE_FRACTALIZER_VASCULAR_TREE_HPP
