#ifndef __PATH_HEAD__
#define __PATH_HEAD__

#include <iostream>
#include <vector>
#include "Edge.hpp"

#define DEFAULT_PATH_ID 0
#define DEFAULT_NUM_CARS 0
#define PATH_ID_EXPLAIN "id : "
#define PATH_CAR_NUMBER_EXPLAIN " n_cars: "
#define PATH_EDGES_EXPLAIN "edges: "



class Path
{
private:

    int id = DEFAULT_PATH_ID;
    int num_cars = DEFAULT_NUM_CARS;
    std::vector<Edge*> edges;

public:
    Path(int path_id , int number_of_cars);
    void add_edge(Edge* new_edge);
    ~Path();

    // getters for Path
    int get_id(){return id;}
    int get_num_cars(){return num_cars;}
    std::vector<Edge*> get_edges(){return edges;}
};

std::ostream& operator<< (std::ostream& os, Path p);
std::ostream& operator<< (std::ostream& os, std::vector<Path> ps);



#endif