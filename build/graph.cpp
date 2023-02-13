#include "../include/graph.h"

Graph::Graph(int n) {
    for (int i = 0; i <= n; i++) {
        this->node_list.push_back(Node(i));
    }
    customer_number = n;
}
void Graph::add_edge(int node1, int node2, double cost) {
    this->node_list[node1].add_connection(node2, cost);
    this->node_list[node2].add_connection(node1, cost);
}
void Graph::initialise_edges() {
    srand(time(0)); // set seed related to time
    for (int i = 1; i < node_list.size(); i++) {
        for (int j = 0; j < i; j++) {
            int con = rand() % 2; // generate 0,1
            if (con == 1) {
                double distance = rand() % 1000;
                distance = distance / 1000; // normalise
                this->add_edge(i,j,distance); // add nodes to each adjacency list
            }
        }
    }
}
void Graph::print_con() {
    for (int i = 0; i < node_list.size(); i++) {
        cout << "Node " << i << ":" << endl;
        node_list[i].print_connections();
    }
}
void Graph::print_orders() {
    for (auto const& [key, val] : order_list) { cout << key << ":" << val << endl; }
}
void Graph::print_paths() {
    for (int i = 0; i < shortest_paths.size(); i++) {
        cout << "Path " << i << ": ";
        for (int j = 0; j < shortest_paths[i].size(); j++) {
            cout << shortest_paths[i][j] << " ";
        }
        cout << endl;
    }
}
bool Graph::check_connectivity() {
    vector<bool> visited;
    visited.resize(node_list.size(), false); // set every node to not visited
    list<int> queue; // queue gives us next vertex to visit
    int s = 0; // store is 0
    // mark store as visited and add it to queue
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty()) {
        s = queue.front(); // get next node in queue
        queue.pop_front(); // remove from queue
        // for each neighbour
        for (auto const& [key, val] : node_list[s].get_adjacency_list()) {
            // if it hasn't been visited add to queue and mark as visited
            if (!visited[key]) {
                visited[key] = true;
                queue.push_back(key);
            }
        }
    }
    for (int i = 0; i < node_list.size(); i++) {
        if (!visited[i]) { 
            double distance = rand() % 1000;
            distance = distance / 1000;
            this->add_edge(0,i,distance); // add direct connection if not connected
        } 
    }
    return true;
}
void Graph::generate_orders() {
    // for each customer
    for (int i = 1; i <= customer_number; i++) {
        int n_order = rand() % 3; // get number in set {0,1,2}
        if (n_order > 0) { // if customer has basket add order to list
            this->order_list[i] = n_order;
        }
    }
}
void Graph::generate_shortest_paths() {
    vector<double> dist; // max distances
    vector<int> Q; // queue
    vector<int> prev; // previous node
    int max = 100000; // arbitrary large value

    for (int i = 0; i < node_list.size(); i++) {
        dist.push_back(max); // assume every dist is inf
        prev.push_back(-1); // set arbitrary prev node
        Q.push_back(i); // add all nodes to queue
    }
    dist[0] = 0; // set store distance to 0
    
    while (!Q.empty()) {
        // initialise u and index to the start of the queue
        int u = Q[0];
        int index = 0;
        double alt; // stores alternate distance value
        // find smallest distance currently in queue
        for (int i = 0; i < Q.size(); i++) {
            if (dist[Q[i]] < dist[u]) {
                u = Q[i];
                index = i;
            }
        }
        Q.erase(Q.begin() + index); // remove it from queue
        // get adjacency list
        map<int,double> adj_list = node_list[u].get_adjacency_list();
        for (auto const& [key, val] : adj_list) {
            for (int i = 0; i < Q.size(); i++) { // check if each neighbour is in queue
                int v = Q[i];
                if (key == v) {
                    // see if alt route is shorter than current route
                    alt = dist[u] + val;
                    if (alt < dist[v]) {
                        dist[v] = alt;
                        prev[v] = u;
                    }
                    break;
                }
            }
        }
    }
    // work through prev to get paths
    this->shortest_paths.push_back({0});
    for (int i = 1; i < node_list.size(); i++) {
        vector<int> path;
        int j = i;
        while (j != -1) {
            path.push_back(j);
            j = prev[j];
        }
        this->shortest_paths.push_back(path);
    }
}