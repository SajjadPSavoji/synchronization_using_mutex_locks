
#include "utils.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // read the information reguarding edges
    std::vector<std::string> edges_info = read_edges();

    // read the information reguarding pathes
    std::vector<std::vector<std::string>> pathes_info = read_pathes();

    // make a new graph
    Graph graph;
    
    // initialize the graph
    graph.init(edges_info,pathes_info);

    // simulate graph
    graph.simulate();

}
