//
// Created by theophrastus on 19.11.2021.
//

#include <algorithm>
#include <cmath>
#include "constants.hpp"
#include "Strategies.hpp"

Find_closest_node::Find_closest_node(const Vascular_tree_node &original_node):
        current_closest_node_ptr{nullptr},
        origin{original_node.coords} {}

void Find_closest_node::operator()(Vascular_tree_node &node) {
    double current_distance = distance(origin, node.coords);

    if (current_min_distance < 0.0) {
        current_min_distance = current_distance;
    } else {
        current_min_distance = fmin(current_min_distance, current_distance);
    }
}

inline Vascular_tree_node *Find_closest_node::get_node_ptr() const {
    return current_closest_node_ptr;
}

inline double Find_closest_node::get_distance() const {
    return current_min_distance;
}


void Merge_adjacent_nodes::operator()(Vascular_tree_node &node) {
    if (node.children.empty()) {
        return;
    }

    Find_closest_node closest(node);
    for (auto child_ptr: node.children) {
        closest(*child_ptr);
    }

    Vascular_tree_node &closest_node = *closest.get_node_ptr();
    const double min_distance = closest.get_distance();

    for (auto child_ptr: node.children) {
        if (min_distance > constants::min_difference_to_merge *
            distance(closest_node.coords, child_ptr->coords)) {
            return;
        }
    }

    merge(node, closest_node);
}

void Merge_adjacent_nodes::merge(Vascular_tree_node &parent, Vascular_tree_node &child) {
    parent.children.splice_after(parent.children.before_begin(), child.children);

    parent.children.remove_if([&child](std::shared_ptr<Vascular_tree_node> node_ptr){return node_ptr.get() == &child;});

    delete &child;
}


void Delete_low_order_nodes::operator()(Vascular_tree_node &node) {
    if (node.is_terminal || node.order > order) {
        return;
    }

    auto parent = node.parent.lock();
    parent->children.remove_if([&node](std::shared_ptr<Vascular_tree_node> &node_ptr){return node_ptr.get() == &node;});
}

inline Delete_low_order_nodes::Delete_low_order_nodes(int order) : order{order} {}


void Calculate_radii::operator()(Vascular_tree_node &node) {
    double res = 0.0;
    for (const auto child: node.children) {
        res += pow(child->radius, constants::alpha);
    }
    node.radius = pow(res, 1.0 / constants::alpha);
}


void Calculate_orders::operator()(Vascular_tree_node &node) {
    node.order = 0;
    for (const auto &child: node.children) {
        if (child->order > node.order) {
            node.order = child->order;
        } else if (child->order == node.order) {
            ++node.order;
        }
    }
    if (node.order == 0)
        ++node.order;
}


void Split::operator()(Vascular_tree_node &node) {
    double max = 0.0;
    Vascular_tree_node *node_1_ptr = nullptr;
    Vascular_tree_node *node_2_ptr = nullptr;
    for (auto child_1: node.children) {
        for (auto child_2: node.children) {
            if (child_1 == child_2)
                continue;

            double rupture_strength = (node.pull_force(*child_1) +
                    node.pull_force(*child_2)).norm() -
                    pow(pow(pow(child_1->radius, constants::alpha) +
                    pow(child_2->radius, constants::alpha), 1.0 / constants::alpha) , constants::beta);

            if (rupture_strength > max) {
                max = rupture_strength;
                node_1_ptr = child_1.get();
                node_2_ptr = child_2.get();
            }
        }
    }
    node.children.remove_if([&node_1_ptr, &node_2_ptr](std::shared_ptr<Vascular_tree_node> &node_ptr){
        return node_ptr.get() == node_1_ptr || node_ptr.get() == node_2_ptr;
    });
    auto *offspring = new Vascular_tree_node(node.coords, &node);
    offspring->children.push_front(node_1_ptr);
    offspring->children.push_front(node_2_ptr);
    node.children.push_front(offspring);
    Calculate_radii c;
    c(*offspring);
    c(node);
}


void Relax::operator()(Vascular_tree_node &node) { // TODO BETTER
    double cost = node.cost();
    double old_cost;
    do {
        node.coords += node.gradient();
        old_cost = cost;
        cost = node.cost();
    } while (cost / old_cost < constants::epsilon);
}


void Hard_delete::operator()(Vascular_tree_node &node) {
    delete &node;
}
