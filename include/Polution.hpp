#ifndef __POLUTION__HEAD__
#define __POLUTION__HEAD__

#include <iostream>
// #include <semaphore.h>
#include <mutex>
#include <thread>

#define DEFAULT_POL_AMOUNT 0
#define P_SHARED 0
#define ONE 1

class Polution
{
private:
    long long amount = DEFAULT_POL_AMOUNT;
    // sem_t mutex;
    std::mutex mutex;

    
public:
    Polution(){}
    ~Polution();

    // function to add amount . this fnction is guarded via semaphore :))
    int add(int oprand);

    

    
};

#endif