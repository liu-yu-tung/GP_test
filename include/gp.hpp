#pragma once
#include "data.hpp"
#include "function.hpp"
#include "program.hpp"
#include "fitness.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <filesystem>
#include <sstream>


class GP{
    int totalFitness;
    float totalInverseFitness;
    int largestFitness;
    Program* finalProgram;
    bool finish;
    
    static std::unique_ptr<Data> data;
    static const int totalPopulation;
    static const int maximumGeneration;
    std::vector<Program*> population;
    std::vector<float> fitnessAverage;
    std::vector<int> fitnessAccumulation;
    std::vector<float> fitnessInverseAccumulation;
    std::vector<int> fitness;
public:
    GP();
    ~GP();
    std::vector<int> prefixReference;
    std::vector<int> infixReference;
    static const Const::Mission mission;

    void setData(int, int);
    void setData(int, int, int);
    void setData(int, float);
    void setData(int, int, float);
    void generatePopulation();
    void generatePrefix(int, int &);
    void evaluation();
    int weightedSelect();
    void reproduce(int, int);
    void crossover();
    void swap(int, int, int, int, int, int);
    void show();
    void showData();
    void deleteRandom();
    void run();
    void evolve();

};