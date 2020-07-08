#include <iostream>
//#include <algorithm>
//#include <utility>
#include "swap.h"



void fswap(Swap& a, Swap &b){
    Swap tmp(static_cast<Swap&&>(b));
    a=static_cast <Swap&&>(b);
    b=static_cast <Swap&&>(tmp);
}

void fapp(){

    Swap *a;
    Swap *b;

    a = new Swap();
    b = new Swap();
    b->AddString("is B");    
    a->AddString("is A");   
    
    fswap(*a,*b);

    std::cout<< "mi config A : "<<a->getSwap()<<std::endl;
    std::cout<< "mi config B : "<<b->getSwap()<<std::endl;

    delete a;
    delete b;

}

int main(void){

try {
        fapp();
    }
catch(...){
       std::cout<< "**********exception**************"<<std::endl;
    }
    return 0;
}
