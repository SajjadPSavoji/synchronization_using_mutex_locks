#include "utils.hpp"

std::vector<std::string> read_edges(void)
{
    std::string line;
    std::vector<std::string> edges_info;
    std::cin>>line;
    while(line != SHARP)
    {
        edges_info.push_back(line);
        std::cin>>line;
    }

    return edges_info;
}

std::vector<std::vector<std::string>> read_pathes(void)
{
    std::string trance;
    std::string n_car;
    std::vector<std::string> pathes_trace;
    std::vector<std::string> pathes_car_number;

    while(std::cin >> trance && std::cin>>n_car)
    {
        pathes_trace.push_back(trance);
        pathes_car_number.push_back(n_car);
    }

    std::vector<std::vector<std::string>> res;
    res.push_back(pathes_trace);
    res.push_back(pathes_car_number);

    return res;
}