#include "node.h"

#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime> 
using namespace std;

#pragma once

class Graph {
public:
    // constructor - n number of CUSTOMERS, thus n + 1 nodes
    Graph(int n);
    // add edge between two nodes and its cost
    void add_edge(int node1, int node2, double cost);
    // check connectivity to store
    bool check_connectivity();
    // initialise random edges
    void initialise_edges();
    // print connections
    void print();
private:
    // list of nodes
    vector<Node> node_list;
};