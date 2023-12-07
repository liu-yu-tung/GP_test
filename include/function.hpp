#pragma once
#include "data.hpp"
#include <memory>
#include <vector>
#include <iostream>

class Data;
class Function {
friend class Program;
public:
    Function(std::shared_ptr<Data> dataPtr);
    virtual ~Function() = 0;
    void addChild(const std::unique_ptr<Function> f);
    void show();
    void setHeight(int h);
    void setInRecursive(bool state);
    void setListBegin(int begin);

    virtual std::string getFunctionName() = 0;
    virtual void execution() = 0;
    virtual int getArity() = 0;
    virtual int getFunctionEnum() = 0;

    std::shared_ptr<Data> dataPtr;
    std::vector<std::unique_ptr<Function>> children;

    bool inRecursive;
    int listBegin;
    int height;

    static const int arity;
    static const int functionEnum;

    static const std::vector<int> inType;
    static const int outType;

    int intResult;
    bool boolResult;

};

class Recursive: public Function {
public:
    Recursive(std::shared_ptr<Data>);
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    int getFunctionEnum() override;

    static const std::string functionName;
    static const std::vector<int> inType;
    static const int outType;
    static const int functionEnum;


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
class IfElse: public Function{
public:
    IfElse(std::shared_ptr<Data>);
    static const std::string functionName;
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    int getFunctionEnum() override;

    static const std::vector<int> inType;
    static const int outType;
    static const int functionEnum;
protected:
    std::unique_ptr<Function> f;
    std::unique_ptr<Function> g;
    static const int arity;
};


class Swap: public Function{
public:
    Swap(std::shared_ptr<Data>);
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    int getFunctionEnum() override;

    static const std::string functionName;
    static const std::vector<int> inType;
    static const int outType;
    static const int functionEnum;
protected:
    static const int arity;
};

class Nxt: public Function{
public:
    Nxt(std::shared_ptr<Data>);
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    int getFunctionEnum() override;

    static const std::string functionName;
    static const std::vector<int> inType;
    static const int outType;
    static const int functionEnum;
protected:
    static const int arity;
};

class Head: public Function{
public:
    Head(std::shared_ptr<Data>);
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    int getFunctionEnum() override;

    static const std::string functionName;
    static const std::vector<int> inType;
    static const int outType;
    static const int functionEnum;
protected:
    static const int arity;
};

class GetDataByIndex: public Function {
public:
    GetDataByIndex(std::shared_ptr<Data>);
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    static const std::string functionName;
    static const std::vector<int> inType;
    static const int outType;

protected:
    static const int arity;
};

class Assign: public Function {
public:
    Assign(std::shared_ptr<Data>);
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    static const std::string functionName;
    static const std::vector<int> inType;
    static const int outType;

protected:
    static const int arity;
};

class BoolEqual: public Function {
public:
    BoolEqual(std::shared_ptr<Data>);
    std::string getFunctionName() override;
    void execution() override;
    int getArity() override;
    static const std::string functionName;
    static const std::vector<int> inType;
    static const int outType;

protected:
    static const int arity;
};