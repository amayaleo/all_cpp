#include "object.h"


Object::Object()
: Object("$")
{
        std::cout<< "constructor single Object\n";
}

Object::Object(std::string str)
{
    priv_std_string=str;
        std::cout<< "constructor single Object : "<<priv_std_string<<std::endl;
}


Object::~Object()
{
std::cout<< "destructor single Object"<< priv_std_string <<"\n";
}