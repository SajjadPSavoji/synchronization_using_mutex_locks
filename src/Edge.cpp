#include "Edge.hpp"

Edge::Edge(std::string source , std::string destination , int c):
src(source) , dst(destination) , cost(c)
{}

Edge::Edge(const Edge& e)
{
    cost = e.cost;
    src  = e.src;
    dst  = e.dst;
}

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

// simulatin functions
int Edge::emission(Car car)
{
    float sum = 0;
    for (size_t k = 0; k < MAX_ITER; k++)
    {
        sum += k/(SCALE * car.get_p() * cost );
    }
    
    return sum;
}


void Edge::simulate(Car &car , Polution* total_polution)
{
    // wait for lock to be freed
    std::lock_guard<std::mutex> guard(mutex);

    // critical section
        // make a record class and initialize if
        Record rec(src , dst);

        // compute emitted polution
        int emited = emission(car);

        // set emitted amount to record
        rec.set_emmission(emited);

        // add emitted polution to total polution 
        long long t_emited = total_polution->add(emited);

        // set total emitted to record
        rec.set_total_emission(t_emited);

        // set exit time
        rec.set_ext_time();

        // complete the new record and push it to cars records
        car.add_record(rec);
    // lock whould be atomaticly released
}