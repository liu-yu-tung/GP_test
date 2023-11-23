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
    virtual std::string getFunctionName() = 0;
    virtual void execution() = 0;

    Data *dataPtr;
    static const int arity;
    static const int outputNumber;
    int height;

    virtual int getArity() = 0;
    virtual int getOutputNumber() = 0;
    std::vector<Function*> children;
    bool inRecursive;
    int listBegin;
    int height;
    DataType outType;
    std::vector<DataType> inType;
};

/**
class Function{
friend class Program;
public:
    Function(Data *);
    void addChild(Function *);
    void show();
    void setHeight(int);
    int& getInt(std::vector<int> &, int);
    float& getFloat(std::vector<int> &, int);

    virtual std::string getFunctionName() = 0;
    virtual void execution() = 0;

    virtual int getArity() = 0;
    virtual int getOutputNumber() = 0;

    /**
     * For 1-D data, store index once a time. e.g, argumentIndex[0] = index.
     * For 2-D data, store index twice a time. argumentIndex[0] & argume.ntIndex[1] = index.
     * 
    */
    std::vector<int> argumentIndex;
    std::vector<int> outputIndex;

protected:
    Data *dataPtr;
    static const int arity;
    static const int outputNumber;
    int height;
    std::vector<Function *> children;
public:
    void setArgument(std::vector<int> &, std::vector<int> &);

};

class Leaf: public Function{
public:
    Leaf(Data *);
    static const std::string functionName;
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    int getOutputNumber() override; 
protected:
    static const int arity;
    static const int outputNumber;

};

/**
 * \brief Define Max2 Fucntion class.
*/
/*
class Max2: public Function{
public:
    Max2(Data *);
    static const std::string functionName;
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    int getOutputNumber() override; 
protected:
    static const int arity;
    static const int outputNumber;

};

*/
class Swap: public Function{
public:
    Swap(Data *);
    static const std::string functionName;
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    int getOutputNumber() override;
protected:

    static const int arity;
    static const int outputNumber;
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
    int getOutputNumber() override;
protected:
    std::unique_ptr<Function> f;
    std::unique_ptr<Function> g;
    static const int arity;
    static const int outputNumber;

};



