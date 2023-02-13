#include "../include/graph.h"
#include "../include/node.h"

#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

void generate_robot_path(Graph &graph) {
    // get longest path in order list
    int next_customer;
    int max_depth = 0;
    graph.print_orders();
    graph.print_paths();
    vector<vector<int>> paths = graph.get_shortest_paths();
    for (auto const& [key, val] : graph.get_order_list()) {
        if (max_depth < paths[key].size()) {
            max_depth = paths[key].size();
            next_customer = key;
        }
    }
    cout << "Next customer: " << next_customer << endl;
};

int main(int argc, char const *argv[]) {
    Graph graph(10);
    graph.initialise_edges();
    graph.check_connectivity();
    graph.generate_orders();
    graph.generate_shortest_paths();
    generate_robot_path(graph);
    cout << "donezo" << endl;
    return 0;
};