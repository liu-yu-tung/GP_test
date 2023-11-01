#pragma once
#include<memory>
#include<vector>
#include<iostream>
#include "data.hpp"

class Function{
public:
    std::vector<Function *> child;
    
    virtual void Execution(Data &) = 0;
};
