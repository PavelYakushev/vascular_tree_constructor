//
// Created by theophrastus on 19.11.2021.
//
// This file features predicate functor descriptions. These can be passed to the depth_first_search in order to manipulate the Vascular_tree.
//

#ifndef VASCULAR_TREE_FRACTALIZER_PREDICATES_HPP
#define VASCULAR_TREE_FRACTALIZER_PREDICATES_HPP

#include "Point.hpp"
#include "Vascular_tree_node.hpp"

class Predicate {
public:
    virtual void operator()(Vascular_tree_node &) = 0;
    virtual ~Predicate() = 0;
};


class Find_closest_node: public Predicate {
public:
    Find_closest_node(const Vascular_tree_node &, Vascular_tree_node &);
    void operator()(Vascular_tree_node &) override;
    Vascular_tree_node *get_node_ptr() const;
    double get_distance() const;

private:
    Vascular_tree_node *current_closest_node;
    double current_min_distance;
    const Point origin;
};

class Merge_adjacent_nodes: public Predicate {
public:
    void operator()(Vascular_tree_node &) override;

private:
    Vascular_tree_node *closest_node_ptr = nullptr;
    static void merge(Vascular_tree_node *, Vascular_tree_node *);
};

#endif //VASCULAR_TREE_FRACTALIZER_PREDICATES_HPP
