#pragma once
#include "data.hpp"

class Fitness{
public:
    Fitness(Data*);
    virtual int evaluation() = 0;
    bool finish; 
protected:
    Data* dataPtr;
};

class Sorting: public Fitness{
public: 
    Sorting(Data*);
    int evaluation() override;
};