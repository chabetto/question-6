#include "node.h"

#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <list>
using namespace std;

#pragma once

class Graph {
public:
    // constructor - n number of CUSTOMERS, thus n + 1 nodes
    Graph(int n);
    // add edge between two nodes and its cost
    void add_edge(int node1, int node2, double cost);
    // check connectivity to store using BFS
    bool check_connectivity();
    // initialise random edges
    void initialise_edges();
    // print connections
    void print_con();
    // print orders
    void print_orders();
    // generate orders for each customer and put it in order_list
    void generate_orders();
private:
    // list of nodes
    vector<Node> node_list;
    // list of orders (node to deliver to, number of baskets)
    map<int,int> order_list;
    // number of customers
    int customer_number;
};