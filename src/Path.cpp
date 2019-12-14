#include "Path.hpp"

Path::Path(int path_id , int number_of_cars):id(path_id) , num_cars(number_of_cars)
{}

Path::~Path()
{}

void Path::add_edge(Edge* new_edge)
{
    // while adding adges to the path add them in an order
    // such which  the sequence of edges form a path
    edges.push_back(new_edge);
}

std::ostream& operator<< (std::ostream& os, Path p)
{
    os << PATH_ID_EXPLAIN << p.get_id() << PATH_CAR_NUMBER_EXPLAIN << p.get_num_cars() << std::endl;
    os << PATH_EDGES_EXPLAIN<<std::endl;

    std::vector<Edge*> edges_ref = p.get_edges();

    for (size_t i = 0; i < edges_ref.size(); i++)
    {
        os << *edges_ref[i];
    }
    
    return os;
}

std::ostream& operator<< (std::ostream& os, std::vector<Path> ps)
{
    for (size_t i = 0; i < ps.size(); i++)
    {
        os << ps[i];
    }
    
    return os;
}