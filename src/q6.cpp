#include "../include/graph.h"
#include "../include/node.h"

#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

int main(int argc, char const *argv[]) {
    Graph graph(10);
    graph.initialise_edges();
    graph.check_connectivity();
    graph.generate_orders();
    graph.generate_shortest_paths();
    graph.print_paths();
    cout << "donezo" << endl;
    return 0;
};