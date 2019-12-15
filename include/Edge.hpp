#ifndef __EDGE__HEAD__
#define __EDGE__HEAD__

#include <iostream>
#include <vector>
// #include <semaphore.h>

#include "Car.hpp"
#include "Polution.hpp"
#include <mutex>


#define DEFAULT_SRC_NAME "SRC"
#define DEFAULT_DST_NAME "DST"
#define DEFAULT_COST 0
#define ARROW " --> "
#define COLUMN " : "

#define MAX_ITER 10000000
#define SCALE 1000000

class Edge
{
private:
    int cost = DEFAULT_COST;
    std::string src = DEFAULT_SRC_NAME;
    std::string dst = DEFAULT_DST_NAME;
    // sem_t mutex;
    std::mutex mutex;

public:
    Edge(std::string source , std::string destination , int c);
    Edge(const Edge& e);
    ~Edge();
    bool match(std::string src_name , std::string dst_name);

    // geters for Edge class 
    int get_cost(){return cost;}
    std::string get_src(){return src;}
    std::string get_dst(){return dst;}

    // simulation functions
    void simulate(Car& car , Polution* total_polution);
    int emission(Car car);
};

std::ostream& operator<< (std::ostream& os, Edge e);
std::ostream& operator<< (std::ostream& os, std::vector<Edge> edges);

#endif