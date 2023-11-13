#pragma once
#include "data.hpp"
#include "function.hpp"
#include "program.hpp"
#include "fitness.hpp"
#include <vector>

class GP{
    static const int populationTotal;
    static Data *data;
    std::vector<Program*> population;
    std::vector<int> fitness;

public:
    GP();
    ~GP();
    static const Const::Mission mission;
    void setData(int, int);
    void setData(int, int, int);
    void setData(int, float);
    void setData(int, int, float);
    void generatePopulation();
    void evaluation();
    void swap(int, int, int, int, int, int);
    void show();
};