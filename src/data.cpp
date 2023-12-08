#include "../include/data.hpp"

Data::Data(){
    data.resize(Const::dataLength);
};

Data::Data(Data& D){
  this->data.assign(D.data.begin(), D.data.end());
};

int Data::get(int index){
    if(index<0 || index>=Const::dataLength) {
        printf("index: %d\n");
        std::cerr << "Data::get(int): Getting data out of index is not allowed.\n";
        exit(0);
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