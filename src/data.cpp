#include "../include/data.hpp"

Data::Data(char type, int l): dataType(type){
    if (!(type=='i'||type=='f')) 
        std::cerr << "Wrong type" << std::endl;
    else
        type=='i'?bufferOfInt1D.resize(l):bufferOfFloat1D.resize(l);
};

Data::Data(char type, int l, int w){

};