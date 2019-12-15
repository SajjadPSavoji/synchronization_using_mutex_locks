#ifndef __CAR__HEAD__
#define __CAR__HEAD__

#include <random>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Record.hpp"

#define DEFAULT_CAR_ID 0
#define DEFAULT_CAR_PATH_ID 0
#define DEFAULT_CAR_P 1

#define DASH "-"
#define FILE_TYPE ".txt"
#define PATH_TO_RES "./res/"

class Car
{
private:
    int id = DEFAULT_CAR_ID;
    int path_id = DEFAULT_CAR_PATH_ID;
    int p = DEFAULT_CAR_P;
    std::vector<Record> records;
public:
    Car(int _id , int _path_id);
    ~Car();

    // getter functions of car
    int get_p(){return p;}
    void add_record(Record rec){records.push_back(rec);}

    // result functions
    void save_records();
    std::string file_name();
};

#endif