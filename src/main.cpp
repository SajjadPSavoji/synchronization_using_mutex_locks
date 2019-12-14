
#include "utils.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // read the information reguarding edges
    std::vector<std::string> edges_info = read_edges();

    // read the information reguarding pathes
    std::vector<std::vector<std::string>> pathes_info = read_pathes();

    // make a new graph
    Graph graph;

    // ----------------- check if input is extracted right ---------------------
    // cout<<"edges info :"<<endl;
    // for (size_t i = 0; i < edges_info.size(); i++)
    // {
    //     cout<<edges_info[i]<<endl;
    // }

    // cout<< "pathes info :"<<endl;

    // for (size_t i = 0; i < pathes_info.size(); i++)
    // {
    //     for (size_t j = 0; j < pathes_info[i].size(); j++)
    //     {
    //         cout<<pathes_info[i][j]<<endl;
    //     }
        
    // }
    // cout<<"end"<<endl;
    // ------------------- end check -------------------------------------------
    
    // initialize the graph
    graph.init(edges_info,pathes_info);

    // check if graph is initialized correct
    cout<<graph;

    // simulate graph

}
