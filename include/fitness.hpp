#pragma once
#include "data.hpp"

class Fitness{
public:
    Fitness(Data*);
    virtual int evaluation() = 0; 
protected:
    Data* dataPtr;
};

class Sorting: public Fitness{
    int a;
public: 
    Sorting(Data*);
    int evaluation() override;
};