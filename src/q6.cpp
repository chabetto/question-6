#include "../include/graph.h"
#include "../include/node.h"

#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

int main(int argc, char const *argv[]) {
    Graph graph(5);
    graph.initialise_edges();
    graph.print();
    cout << "THE END" << endl;
    return 0;
};