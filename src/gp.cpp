#include "../include/gp.hpp"
const Const::Mission GP::mission = Const::Mission::Sorting;
const int GP::populationTotal = 5;


Data *GP::data;

GP::GP(){
    data = new Data();
    data->show();
};

GP::~GP(){
    delete data;
    for(Program* program:population) delete program;
};

void GP::setData(int x, int i){
    if(Const::dimensionOfBuffer!=1 || Const::typeOfBuffer!=Int) std::cerr << "Cannot set not one dimensional or not int data\n";
    else{
        std::vector<int> index;
        index.push_back(x);
        data->set(index, i);
    }
};

void GP::setData(int x, int y, int i){
    if(Const::dimensionOfBuffer!=2 || Const::typeOfBuffer!=Int) std::cerr << "Cannot set not two dimensional or not int data\n";
    else{
        std::vector<int> index;
        index.push_back(x);
        index.push_back(y);
        data->set(index, i);
    }
};

void GP::setData(int x, float f){
    if(Const::dimensionOfBuffer!=1 || Const::typeOfBuffer!=Float) std::cerr << "Cannot set not one dimensional or not float data\n";
    else{
        std::vector<int> index;
        index.push_back(x);
        data->set(index, f);
    }
};

void GP::setData(int x, int y, float f){
    if(Const::dimensionOfBuffer!=2 || Const::typeOfBuffer!=Float) std::cerr << "Cannot set not two dimensional or not float data\n";
    else{
        std::vector<int> index;
        index.push_back(x);
        index.push_back(y);
        data->set(index, f);
    }
};

void GP::generatePopulation(){
    if(Const::growMethodGlobal!=Const::growMethod::half_half){
        for(int i=0; i<populationTotal; i++){
            Program* programPtr = new Program(Const::growMethodGlobal, *data);
            population.push_back(programPtr);
        }
    }
    else if(Const::growMethodGlobal==Const::growMethod::half_half){}
};

void GP::evaluation(){
    for(Program* program:population) {
        program->execution();
        if(mission==Const::Mission::Sorting){
            Sorting sort(program->dataPtr);
            fitness.push_back(sort.evaluation());
        }
    }
};

void GP::show(){
    for(Program* program:population) program->showTree();
};