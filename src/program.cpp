#include "../include/program.hpp"
Program::Program(Const::growMethod method){

};

Program::~Program(){
    for(Function *f:tree) delete f;
};

Function *Program::randomChooseFunction(){
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distribution(1, Const::functionSetNumber);
    int functionNumber = distribution(gen);
    return getFunction(functionNumber);
};

void Program::growTree(Const::growMethod method){
    rootOfTree = randomChooseFunction(); 
    if(method==Const::full){
        
    }
};

//to make program get specific function
Function* getFunction(int functionNumber){
    if(functionNumber-1==Const::functionSet::Max2){
        Function* f = new Max2;
        return f;
    }
};