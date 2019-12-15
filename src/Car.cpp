#include "Car.hpp"

Car::Car(int _id , int _path_id):id(_id) , path_id(_path_id)
{
    const int range_from  = 1;
    const int range_to    = 10;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);

    p = distr(generator);
}

Car::~Car()
{}

// member functions for resualts
std::string Car::file_name()
{
    std::string name = PATH_TO_RES;
    name += std::to_string(path_id);
    name += DASH;
    name += std::to_string(id);
    name += FILE_TYPE;

    return name;
}

void Car::save_records()
{
    std::ofstream os;
    os.open(file_name());
    os << records;
    os.close();
}