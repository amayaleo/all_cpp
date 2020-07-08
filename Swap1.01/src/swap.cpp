#include "swap.h"



Swap::Swap()
: priv_swap_str{"@"}  ,sw{nullptr} // , p{nullptr}
{
    std::cout<< "constructor single Swap\n";
}

Swap::Swap(const Swap& other){
}

Swap::Swap(const Swap&& other){
}

Swap::~Swap(){
    std::cout<< "destructor single Swap \n ";
}


Swap& Swap::operator=(const Swap& other){
    Swap obj_tmp(other);
    std::swap (priv_swap_str , obj_tmp.priv_swap_str);
    return *this;
}

Swap& Swap::operator=(Swap&& other){
    std::swap (priv_swap_str , other.priv_swap_str);
    return *this;
}



void Swap::AddString(std::string str){
    //sw->
    priv_swap_str=str;

}

std::string Swap::getSwap(){        
    return priv_swap_str;
}