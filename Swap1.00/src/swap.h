#pragma once
#include <iostream>
#include <cstdint>
#include <string>
#include "object.h"

class Swap : public Object
{

public:
    Swap();
    //Swap(std::string);
    Swap(const Swap&);
    Swap(const Swap&&);
    ~Swap();
    Swap& operator=(Swap& other);
    Swap& operator=(Swap&& other);
    void AddString(std::string);
    std::string getSwap();

private:
    uint16_t  priv_sawp_value_int;
    std::string priv_swap_str;
    Object *p;
    Swap *sw;
};

