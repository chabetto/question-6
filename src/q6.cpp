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
    graph.print();
    bool connected = graph.check_connectivity();
    cout << connected << endl;
    return 0;
};