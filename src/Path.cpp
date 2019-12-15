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

// simulation functions

void Path::simulate_edges(int car_num , Polution* total_polution)
{
    // init car
    Car car(car_num , id);

    for (size_t i = 0; i < edges.size(); i++)
    {
        edges[i]->simulate(car , total_polution);
    }
    
    car.save_records();
}

void Path::simulate(Polution* total_polution)
{
    // make num_cars threads and let them call path.simulate_edges
    std::vector<std::thread> threads;

    for (size_t i = 0; i < num_cars; i++)
    {
        std::thread new_thread(&Path::simulate_edges , this , i , total_polution);
        threads.push_back(std::move(new_thread));
    }

    // join threads
    for (size_t i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }
}