#include "Record.hpp"

Record::Record(std::string ent_node , std::string ext_node):
ent_node_name(ent_node) , ext_node_name(ext_node)
{
    std::chrono::time_point<std::chrono::system_clock> now = 
    std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    ent_time = millis;
    // ent_time = std::time(nullptr);
}

Record::~Record()
{}

void Record::set_ext_time()
{
    std::chrono::time_point<std::chrono::system_clock> now = 
    std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    ext_time = millis;
    // ext_time = std::time(nullptr);
}

std::ostream& operator<< (std::ostream& os, Record rec)
{
    os << rec.get_ent_node() << REC_DELIM;
    os << rec.get_ent_time() << REC_DELIM;
    os << rec.get_ext_node() << REC_DELIM;
    os << rec.get_ext_time() << REC_DELIM;
    os << rec.get_emission() << REC_DELIM;
    os << rec.get_total_emission();

    return os;
}

std::ostream& operator<< (std::ostream& os, std::vector<Record> records)
{
    for (size_t i = 0; i < records.size(); i++)
    {
        os << records[i] << std::endl;
    }
    
    return os;
}