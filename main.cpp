#include <iostream>
#include "include/data.hpp"
//#include "include/function.hpp"

int main(int argc, char** argv) {
    freopen( "error.txt", "w", stderr );
    //GETINFO();
    Data A;
    A.show();
    std::vector<int> x = {2, 3};
    A.returnIntValue(x) = 3;
    std::vector<int> y = {3, 4};
    A.returnIntValue(y) = 5;
    A.show();
    //A.returnValue<int>(x) = 3;
    //std::cout << A.returnValue<int>(x);
    Max2 B;
    std::vector<int> index = {2, 3, 3, 4};
    std::vector<int> output = {2, 4};
    setArgument(B, index, output);
    B.execution(A);
    A.show();
    return 0;
}