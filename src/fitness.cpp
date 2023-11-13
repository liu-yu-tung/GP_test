#include "../include/fitness.hpp"
Fitness::Fitness(Data* d): dataPtr(d){};

Sorting::Sorting(Data *d): Fitness(d){};

//ascending
int Sorting::evaluation(){
    bool isSorted = true;
    if(Const::dimensionOfBuffer==1){
        int l = Const::shapeOfBuffer.getLength();
        for(int i=0; i<l-1; i++){
            if(Const::typeOfBuffer==Int)
                if(dataPtr->getIntValue(i)>dataPtr->getIntValue(i+1)) isSorted=false;
            else if(Const::typeOfBuffer==Float)
                if(dataPtr->getFloatValue(i)>dataPtr->getFloatValue(i+1)) isSorted=false;
        }
    }
    else if(Const::dimensionOfBuffer==2){
        int l = Const::shapeOfBuffer.getLength();
        int w = Const::shapeOfBuffer.getWidth();
        for(int i=0; i<l-1; i++){
            for(int j=0; j<w-1; j++){
                if(Const::typeOfBuffer==Int){
                    if(dataPtr->getIntValue(i, j)>dataPtr->getIntValue(i, j+1)) isSorted=false;
                    if(j+1==w-1 && dataPtr->getIntValue(i, w-1)>dataPtr->getIntValue(i+1, 0)) isSorted=false;
                }
                else if(Const::typeOfBuffer==Float){
                    if(dataPtr->getFloatValue(i, j)>dataPtr->getFloatValue(i, j+1)) isSorted=false;
                    if(j+1==w-1 && dataPtr->getIntValue(i, w-1)>dataPtr->getIntValue(i+1, 0)) isSorted=false;
                }
            }
        }        
    }

    if(isSorted) return 1;
    else return 0;
};