#include "Graph.hpp"
Graph::Graph(/* args */)
{
}

Graph::~Graph()
{
}

std::vector<std::string> split_command(std::string command , std::string delim)
{
    std::string token;
    std::vector<std::string> splited;
    std::stringstream ss(command);
    std::stringstream dd(delim);
    char d;
    dd>>d;
    while (std::getline(ss, token, d))
        splited.push_back(token);
        
    return splited;
}

int str_to_int(std::string str)
{
    int i;
    std::stringstream my_stream(str);
    my_stream >> i;
    return i;
}

void Graph::add_edge(std::string edge_info)
{
    std::vector<std::string> splited;
    splited = split_command(edge_info , DELIM);

    Edge new_edge(splited[0] , splited[1] , str_to_int(splited[2]));
    edges.push_back(new_edge);
}

void Graph::add_path(std::string path_trace , std::string number_of_cars)
{
    int n_cars = str_to_int(number_of_cars);

    std::vector<std::string> splited;
    splited = split_command(path_trace , DELIM);

    Path new_path(path_count , n_cars);
    path_count++;
    //it is important to add path_count  inorder to make new path_ids


    for (size_t i = 0; i < splited.size()-1; i++)
    {
        Edge* a_edge = find_edge(splited[i] , splited[i+1]);
        new_path.add_edge(a_edge);
    }
    
    pathes.push_back(new_path);
}

Edge* Graph::find_edge(std::string src_name , std::string dst_name)
{
    for (size_t i = 0; i < edges.size(); i++)
    {
        if(edges[i].match(src_name , dst_name))
            return &edges[i];
    }
    
    return NULL;
}

void Graph::init(std::vector<std::string> edges_info , 
    std::vector<std::vector<std::string>> pathes_info)
{
    // add edges
    for (size_t i = 0; i < edges_info.size(); i++)
    {
        add_edge(edges_info[i]);
    }

    std::vector<std::string> traces_info = pathes_info[0];
    std::vector<std::string> car_num_info = pathes_info[1];

    // add pathes to graph
    for (size_t i = 0; i < traces_info.size(); i++)
    {
        add_path(traces_info[i] , car_num_info[i]);
    }   
}

std::ostream& operator<< (std::ostream& os, Graph p)
{
    os << EDGES_EXPLAIN << std::endl << p.get_edges() << std::endl;
    os << PATH_COUNT_EXPLAIN << p.get_path_count() << std::endl;
    os << PATHES_EXPLAIN << std::endl << p.get_pathes() << std::endl;

    return os;
}

// simulation functions
void Graph::simulate_path(Path p)
{
    p.simulate(&total_polution);
}

void Graph::simulate()
{
    // make path_count threads and let them call path.simulate
    std::vector<std::thread> threads;

    for (size_t i = 0; i < path_count; i++)
    {
        std::thread new_thread(&Graph::simulate_path , this , pathes[i]);
        threads.push_back(std::move(new_thread));
    }
    
    // join threads
    for (size_t i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }
    
}