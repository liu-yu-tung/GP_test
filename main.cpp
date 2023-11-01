#include<iostream>
#include "include/data.hpp"

using namespace std;

int main(int argc, char** argv) {
    freopen( "error.txt", "w", stderr );
    GETINFO();
    Data A;
    A.showBuffer();
    return 0;
}