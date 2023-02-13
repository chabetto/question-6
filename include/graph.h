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
    // print shortest paths
    void print_paths();
    // generate orders for each customer and put it in order_list
    void generate_orders();
    // generate shortest paths for each node using Dijksta's (thanks wiki)
    void generate_shortest_paths();
    // get order list
    map<int,int> get_order_list();
    // get shortest_paths
    vector<vector<int>> get_shortest_paths();
private:
    // list of nodes
    vector<Node> node_list;
    // list of orders (node to deliver to, number of baskets)
    map<int,int> order_list;
    // number of customers
    int customer_number;
    // shortest paths to nodes
    vector<vector<int>> shortest_paths;
};