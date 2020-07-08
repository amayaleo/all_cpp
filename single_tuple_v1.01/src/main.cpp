#include <iostream>
#include <cstdint>
#include <tuple>
#include "debug.h"

struct Class_t 
{    
    ~Class_t()
    {
        extern_dbg("~ destructor Class_t");
    };

    uint16_t id;
};

std::tuple<double, char, std::string> get_info(Class_t tmp)
{
    if (tmp.id == 0) return std::make_tuple(3.8, 'A', "Alicia Alderete");
    if (tmp.id == 1) return std::make_tuple(2.9, 'C', "Benito Barajas");
    if (tmp.id == 2) return std::make_tuple(1.7, 'D', "Carlos Cabello");
    throw std::invalid_argument("id");
}
 
int main ()
{
    Class_t tmp_id{2};
   
   auto [ prom2, calif2, nombre2 ] = get_info(tmp_id);

     
    std::cout << "ID: , "
               << "PROM: " << prom2 << ", "
              << "calif: " << calif2 << ", "
              << "nombre: " << nombre2 << '\n';

}
