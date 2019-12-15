#ifndef __RECORD__HEAD__
#define __RECORD__HEAD__

#include <iostream>
#include <ctime>
#include <vector>

#define REC_DELIM " , "

class Record
{
private:
    std::string ent_node_name;
    std::string ext_node_name;
    time_t ent_time;
    time_t ext_time;
    int emission;
    long long total_emission;
public:
    Record(std::string ent_node , std::string ext_node);
    ~Record();

    // setter functions
    void set_ext_time();
    void set_emmission(int em){emission = em;}
    void set_total_emission(long long tem){total_emission = tem;}

    // getter functions
    std::string get_ent_node(){return ent_node_name;}
    std::string get_ext_node(){return ext_node_name;}
    time_t get_ent_time(){return ent_time;}
    time_t get_ext_time(){return ext_time;}
    int get_emission(){return emission;}
    long long get_total_emission(){return total_emission;}
};

std::ostream& operator<< (std::ostream& os, Record rec);
std::ostream& operator<< (std::ostream& os, std::vector<Record> records);


#endif