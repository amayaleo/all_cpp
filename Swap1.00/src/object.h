#pragma once
#include <iostream>
#include <cstdint>
#include <string>


class Object
{
private:
    //const Object priv_obj {nullptr};
    std::string priv_std_string;
public:
    Object();
    Object(std::string);
    ~Object();
};

