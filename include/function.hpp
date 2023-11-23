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
    static const std::vector<Const::DataType> inType;
    static const Const::DataType outType;
};


class Swap: public Function{
public:
    Swap(Data *);
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    static const std::string functionName;
    static const std::vector<Const::DataType> inType;
    static const Const::DataType outType;

protected:
    static const int arity;
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
    static const std::vector<Const::DataType> inType;
    static const Const::DataType outType;
protected:
    std::unique_ptr<Function> f;
    std::unique_ptr<Function> g;
    static const int arity;
};



