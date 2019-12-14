#ifndef __EDGE__HEAD__
#define __EDGE__HEAD__

#include <iostream>
#include <vector>


#define DEFAULT_SRC_NAME "SRC"
#define DEFAULT_DST_NAME "DST"
#define DEFAULT_COST 0
#define ARROW " --> "
#define COLUMN " : "

class Edge
{
private:
    int cost = DEFAULT_COST;
    std::string src = DEFAULT_SRC_NAME;
    std::string dst = DEFAULT_DST_NAME;
public:
    Edge(std::string source , std::string destination , int c);
    ~Edge();
    bool match(std::string src_name , std::string dst_name);

    // geters for Edge class 
    int get_cost(){return cost;}
    std::string get_src(){return src;}
    std::string get_dst(){return dst;}
};

std::ostream& operator<< (std::ostream& os, Edge e);
std::ostream& operator<< (std::ostream& os, std::vector<Edge> edges);

#endif