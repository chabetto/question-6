#include "../include/graph.h"
#include "../include/node.h"

#include <map>
#include <vector>
#include <iostream>
#include <random>
using namespace std;

void generate_robot_path(Graph &graph) {
    //while order list is not empty
    while (!graph.get_order_list().empty()) {
        // get longest path in order list
        int next_customer;
        int max_depth = 0;
        vector<vector<int>> paths = graph.get_shortest_paths();
        for (auto const& [key, val] : graph.get_order_list()) {
            if (max_depth < paths[key].size()) {
                max_depth = paths[key].size();
                next_customer = key;
            }
        }
        // go to end node
        cout << "Next customer: " << next_customer << endl << "Node: ";
        for (int i = paths[next_customer].size() - 1; i > 0; i--) {
            cout << paths[next_customer][i] << "-> Node: ";
        }
        int baskets = 3; // each robot has 3 baskets
        // for each node in path check if there is an order
        for (int i = 0; i < paths[next_customer].size(); i++) {
            cout << paths[next_customer][i];
            for (auto const& [key, cus_basket] : graph.get_order_list()){
                // if we have some baskets then deliver it
                if (baskets == 0) {
                    break;
                } else if (paths[next_customer][i] == key) {
                    baskets = graph.remove_order(key,baskets);
                }
            }
            cout << " -> Node: ";
        }
        cout << "Done" << endl;
    }
};

int main(int argc, char const *argv[]) {
    Graph graph(10);
    graph.initialise_edges();
    graph.check_connectivity();
    graph.generate_orders();
    graph.generate_shortest_paths();
    generate_robot_path(graph);
    return 0;
};