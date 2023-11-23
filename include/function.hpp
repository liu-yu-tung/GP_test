#pragma once
#include "data.hpp"
#include <memory>
#include <vector>
#include <iostream>

class Data;
class Function {
friend class Program;
public:
    Function(Data* dataPtr);

    void addChild(Function *f);
    void show();
    void setHeight(int h);
    void setInRecursive(bool state);
    void setListBegin(int begin);

    virtual std::string getFunctionName() = 0;
    virtual void execution() = 0;
    virtual int getArity() = 0;

    Data *dataPtr;
    std::vector<Function*> children;

    bool inRecursive;
    int listBegin;
    int height;

    static const int arity;
    static const std::vector<DataType> inType;
    static const DataType outType;
};


class Swap: public Function{
public:
    Swap(Data *);
    static const std::string functionName;
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;

protected:
    static const int arity;
    static const std::vector<DataType> inType;
    static const DataType outType;
};

/**
 * \brief Define Loop Fucntion class
 * Loop(f, data)
 *      if(data.size==1) return g(data)
 *      else if return(f, data.cdr)
 * .
*/
class Loop: public Function{
public:
    Loop(Data *);
    static const std::string functionName;
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    //int getOutputNumber() override;
protected:
    std::unique_ptr<Function> f;
    std::unique_ptr<Function> g;
    static const int arity;
    //static const int outputNumber;
};



