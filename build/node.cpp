#include "..\include\node.h"

Node::Node(int _id) : id(_id) {};
void Node::add_connection(int _id, double cost) {
    this->adjacency_list[_id] = cost;
};
void Node::print_connections() {
    for (auto const& [key, val] : adjacency_list) { cout << key << ":" << val << endl; }
}
map<int,double> Node::get_adjacency_list() {
    return adjacency_list;
}