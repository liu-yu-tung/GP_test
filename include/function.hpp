#pragma once
#include "data.hpp"
#include <memory>
#include <vector>
#include <iostream>

class Data;
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

protected:
    Data *dataPtr;
    static const int arity;
    static const int outputNumber;
    int height;

    virtual int getArity() = 0;
    virtual int getOutputNumber() = 0;
    /**
     * For 1-D data, store index once a time. e.g, argumentIndex[0] = index.
     * For 2-D data, store index twice a time. argumentIndex[0] & argume.ntIndex[1] = index.
     * 
    */
    std::vector<int> argumentIndex;
    std::vector<int> outputIndex;
    std::vector<Function *> children;
public:
    /**
     * \brief Setting and checking args.
     * 
     * To set the index of argument of function. e.g. Data[index1'][index2'] = max(index1, index2).
     * 
    */
    void setArgument(std::vector<int> &, std::vector<int> &);

};

/**
 * \brief Define Max2 Fucntion class.
*/
class Max2: public Function{
public:
    Max2(Data *);
    static const std::string functionName;
    std::string getFunctionName() override;
    void execution() override;

protected:
    
    static const int arity;
    static const int outputNumber;
    int getArity() override;
    int getOutputNumber() override;
    
};

/**
 * \brief Define Swap Fucntion class.
*/
class Swap: public Function{
public:
    Swap(Data *);
    static const std::string functionName;
    std::string getFunctionName() override;
    void execution() override;

protected:

    static const int arity;
    static const int outputNumber;
    int getArity() override;
    int getOutputNumber() override;
};



