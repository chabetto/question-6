// node for graph

#include <map>
#include <vector>
#include <iostream>
using namespace std;

#pragma once

class Node {
public:
    // constructor (is it a store and the node id)
    Node(int id);
    // add connection
    void add_connection(int _id, double cost);
    // print list of connections and cost
    void print_connections();
protected:
    // node id (id = 0 is the store)
    int id;
    // adjacency list - node id that current node connected to || cost as double
    map<int,double> adjacency_list;
};