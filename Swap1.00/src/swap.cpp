#include "swap.h"



Swap::Swap()
: priv_swap_str{"@"}  ,sw{nullptr} // , p{nullptr}
{
    std::cout<< "constructor single Swap\n";
}

Swap::Swap(const Swap& other)
{
    //std::swap(priv_swap_str,other.priv_swap_str);
}

    Swap::Swap(const Swap&& other){
    //std::swap(priv_swap_str,other.priv_swap_str);
}

Swap::~Swap(){
    std::cout<< "destructor single Swap \n ";
    //delete p;
    //delete sw;
}


Swap& Swap::operator=(Swap& other){
    std::swap (priv_swap_str , other.priv_swap_str);
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