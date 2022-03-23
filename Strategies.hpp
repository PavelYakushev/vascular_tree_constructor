//
// Created by theophrastus on 19.11.2021.
//
// This file features Strategy function objects. These can be passed to the apply_to_all method of a Vascular_tree in order to manipulate its structure.
//

#ifndef VASCULAR_TREE_FRACTALIZER_STRATEGIES_HPP
#define VASCULAR_TREE_FRACTALIZER_STRATEGIES_HPP

#include "space.hpp"
#include "Vascular_tree_node.hpp"

class Strategy {
public:
    virtual void operator()(Vascular_tree_node &node) = 0;
    virtual ~Strategy() = 0;
};


class Find_closest_node: public Strategy {
    Vascular_tree_node *current_closest_node_ptr;
    double current_min_distance = -1.0;
    const Point origin;

public:
    explicit Find_closest_node(const Vascular_tree_node &original_node);
    void operator()(Vascular_tree_node &node) override;
    inline Vascular_tree_node *get_node_ptr() const;
    inline double get_distance() const;
};


class Merge_adjacent_nodes: public Strategy {
    Vascular_tree_node *closest_node_ptr = nullptr;

public:
    void operator()(Vascular_tree_node &node) override;

private:
    static void merge(Vascular_tree_node &, Vascular_tree_node &);
};


class Delete_low_order_nodes: public Strategy {
    int order;

public:
    explicit Delete_low_order_nodes(int order);
    void operator()(Vascular_tree_node &node) override;
};


class Calculate_radii: public Strategy {
public:
    void operator()(Vascular_tree_node &node) override;
};


class Calculate_orders: public Strategy {
public:
    void operator()(Vascular_tree_node &node) override;
};


class Split: public Strategy {
public:
    void operator()(Vascular_tree_node &node) override;
};


class Relax: public Strategy {
public:
    void operator()(Vascular_tree_node &node) override;
};


class Hard_delete: public Strategy {
public:
    void operator()(Vascular_tree_node &node) override;
};

#endif //VASCULAR_TREE_FRACTALIZER_STRATEGIES_HPP
