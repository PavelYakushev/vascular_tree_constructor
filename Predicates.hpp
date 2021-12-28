//
// Created by theophrastus on 19.11.2021.
//
// This file features predicate functor descriptions. These can be passed to the apply_to_all in order to manipulate the Vascular_tree.
//

#ifndef VASCULAR_TREE_FRACTALIZER_PREDICATES_HPP
#define VASCULAR_TREE_FRACTALIZER_PREDICATES_HPP

#include "space.hpp"
#include "Vascular_tree_node.hpp"

class Predicate {
public:
    virtual void operator()(Vascular_tree_node &node) = 0;
    virtual ~Predicate() = 0;
};


class Find_closest_node: public Predicate {
    Vascular_tree_node *current_closest_node_ptr;
    double current_min_distance = -1.0;
    const Point origin;

public:
    explicit Find_closest_node(const Vascular_tree_node &original_node);
    void operator()(Vascular_tree_node &node) final;
    inline Vascular_tree_node *get_node_ptr() const;
    inline double get_distance() const;
};


class Merge_adjacent_nodes: public Predicate {
    Vascular_tree_node *closest_node_ptr = nullptr;

public:
    void operator()(Vascular_tree_node &node) final;

private:
    static void merge(Vascular_tree_node &, Vascular_tree_node &);
};


class Delete_low_order_nodes: public Predicate {
    int order;

public:
    explicit Delete_low_order_nodes(int order);
    void operator()(Vascular_tree_node &node) final;
};


class Calculate_radii: public Predicate {
public:
    void operator()(Vascular_tree_node &node) final;
};


class Calculate_orders: public Predicate {
public:
    void operator()(Vascular_tree_node &node) final;
};


class Split: public Predicate {
public:
    void operator()(Vascular_tree_node &node) final;
};


class Relax: public Predicate {
public:
    void operator()(Vascular_tree_node &node) final;
};

class Hard_delete: public Predicate {
public:
    void operator()(Vascular_tree_node &node) final;
};

#endif //VASCULAR_TREE_FRACTALIZER_PREDICATES_HPP
