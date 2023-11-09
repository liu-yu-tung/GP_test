#pragma once
#include "data.hpp"
#include <memory>
#include <vector>
#include <iostream>

class Data;
class Function{
friend void setArgument(Function &, std::vector<int> &, std::vector<int> &);
public:
    void addChild(Function *);
    void showIO();
    void setHeight(int);
    virtual std::string getFunctionName() = 0;
    virtual void execution(Data &) = 0;

protected:
    static const int arity;
    static const int outputNumber;
    int height;

    virtual int getArity() = 0;
    virtual int getOutputNumber() = 0;
    //for 1-D data, store index once a time. e.g, argumentIndex[0] = index
    //for 2-D data, store index twice a time. argumentIndex[0] & argumentIndex[1] = index
    std::vector<int> argumentIndex;
    std::vector<int> outputIndex;
    std::vector<Function *> children;

};

class Max2: public Function{
public:
    static const std::string functionName ;
    std::string getFunctionName() override;
    void execution(Data &) override;

protected:
    static const int arity;
    static const int outputNumber;
    int getArity() override;
    int getOutputNumber() override;
    
};

//to set the index of argument of function. e.g. Data[index1'][index2'] = max(index1, index2)
void setArgument(Function &, std::vector<int> &);

