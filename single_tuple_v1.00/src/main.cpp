#include <iostream>
#include <algorithm>
#include <cstdint>
#include <memory>
#include <vector>
#include <tuple>


std::tuple<double, char, std::string> captar_estudiante(int id)
{
    if (id == 0) return std::make_tuple(3.8, 'A', "Alicia Alderete");
    if (id == 1) return std::make_tuple(2.9, 'C', "Benito Barajas");
    if (id == 2) return std::make_tuple(1.7, 'D', "Carlos Cabello");
    throw std::invalid_argument("id");
}
 
int main ()
{
    auto estudiante0 = captar_estudiante(0);
    std::cout << "ID: 0, "
              << "PROM: " << std::get<0>(estudiante0) << ", "
              << "calif: " << std::get<1>(estudiante0) << ", "
              << "nombre: " << std::get<2>(estudiante0) << '\n';
 
    double prom1;
    char calif1;
    std::string name1;
    

    std::tie(prom1, calif1, name1) = captar_estudiante(1);
    std::cout << "ID: 1, "
              << "PROM: " << prom1 << ", "
              << "calif: " << calif1 << ", "
              << "name: " << name1 << '\n';
 

    // // C++17: vínculo estructurado
     auto [ prom2, calif2, nombre2 ] = captar_estudiante(2);
     std::cout << "ID: 2, "
               << "PROM: " << prom2 << ", "
              << "calif: " << calif2 << ", "
              << "nombre: " << nombre2 << '\n';
  return 0;
}
