#ifndef __GRAPH__HEAD__
#define __GRAPH__HEAD__

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <thread> 
#include <semaphore.h>

#include "Edge.hpp"
#include "Path.hpp"
#include "Polution.hpp"

#define DELIM "-"
#define SPACE " "
#define DEFAULT_PATH_COUNT 0

#define PATH_COUNT_EXPLAIN "path count : "
#define EDGES_EXPLAIN "graph edges : "
#define PATHES_EXPLAIN "pathes explain : "

class Graph
{
private:
    int path_count = DEFAULT_PATH_COUNT;
    std::vector<Edge> edges;
    std::vector<Path> pathes;
    Polution total_polution;
public:
    Graph();
    ~Graph();
    Edge* find_edge(std::string src_name , std::string dst_name);
    void add_edge(std::string edge_info);
    void add_path(std::string path_trace , std::string number_of_cars);
    void init(std::vector<std::string> edges_info, 
        std::vector<std::vector<std::string>> pathes_info);

    // graph getters
    int get_path_count(){return path_count;}
    std::vector<Edge> get_edges(){return edges;}
    std::vector<Path> get_pathes(){return pathes;}

    // simulation function
    void simulate();
    void simulate_path(Path p);
};

std::ostream& operator<< (std::ostream& os, Graph p);

std::vector<std::string> split_command(std::string command , std::string delim);
int str_to_int(std::string str);


#endif