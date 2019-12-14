#include "Edge.hpp"

Edge::Edge(std::string source , std::string destination , int c):
src(source) , dst(destination) , cost(c)
{}

Edge::~Edge()
{}

bool Edge::match(std::string src_name , std::string dst_name)
{
    if (src_name == src && dst_name == dst)
        return true;
    return false;
}

std::ostream& operator<< (std::ostream& os, Edge e)
{
    os << e.get_src() << ARROW << e.get_dst() << COLUMN << e.get_cost() << std::endl;
    return os;
}

std::ostream& operator<< (std::ostream& os, std::vector<Edge> edges)
{
    for (size_t i = 0; i < edges.size(); i++)
    {
        os << edges[i];
    }
    
    return os;
}