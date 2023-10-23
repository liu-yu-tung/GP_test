#pragma once
#include <vector>
#include <memory>
#include <iostream>

class Data{
    std::vector<int> bufferOfInt1D;
    std::vector<std::vector<int>> bufferOfInt2D;
    std::vector<float> bufferOfFloat1D;
    std::vector<std::vector<float>> bufferOfFloat2D;
    char dataType;
    const std::vector<int> shape;
public:
    Data(char, int);
    Data(char, int, int);
    //void GetBufferType();
};
