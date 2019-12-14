#include <iostream>
#include <vector>

#include "Graph.hpp"

#define SHARP "#"

std::vector<std::string> read_edges(void);

std::vector<std::vector<std::string>> read_pathes(void);

void init_graph(Graph &graph , std::vector<std::string> edges_info , 
    std::vector<std::vector<std::string>> pathes_info);