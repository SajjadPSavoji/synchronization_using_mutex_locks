#include "Polution.hpp"

Polution::~Polution()
{}

int Polution::add(int oprand)
{
    std::lock_guard<std::mutex> guard(mutex);
    
    amount += oprand;

    return amount;
}