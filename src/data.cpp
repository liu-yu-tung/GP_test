#include "../include/data.hpp"

Data::Data(){
    data.resize(Const::dataLength);
};

int Data::get(int index){
    if(index<0 || index>=Const::dataLength) {
        std::cerr << "Data::get(int): Getting data out of index is not allowed.\n";
        return -1;
    }
    else return data[index];
};

void Data::set(int index, int n){
    if(index<0 || index>=Const::dataLength) std::cerr << "Data::set(int, int): Setting data out of index is not allowed.\n";
    else data[index] = n;
};

void Data::show(){
    std::cout << "Showing Data: ";
    for(auto &x: data) std::cout << x << " ";
    std::cout << std::endl;
};