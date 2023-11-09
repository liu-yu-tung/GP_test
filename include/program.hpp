#pragma once
#include "data.hpp"
#include "function.hpp"
#include <vector>
#include <random>

class Program{
    Function *rootOfTree;
    std::vector<Function*> tree;
    void growTree(Const::growMethod);
    
public:
    Program(Const::growMethod);
    ~Program();
    Function *randomChooseFunction();
};

//to make program get specific function
Function* getFunction(int);