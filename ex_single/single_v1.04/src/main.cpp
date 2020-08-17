#include <iostream>
#include <algorithm>
#include <cstdint>
#include <memory>
#include <vector>

struct Class_t
{
 private:
   uint32_t priv_x;
   uint32_t priv_y;

public:
   explicit Class_t(const uint32_t x )
   : priv_x { x } 
   {
   }

  uint32_t dev(){
    return priv_x;
  };

  Class_t (const Class_t&){

  }

 Class_t (Class_t&&){

std::cout << "  Class_t (Class_t&&) \n";
  }

  Class_t& operator=(const Class_t& )  { 
    std::cout << " const Class_t & \n"; return *this;} ;
  
  Class_t& operator=(Class_t&& ) { 
    std::cout << "  Class_t && \n";
   return *this;} ;

  Class_t operator&(const Class_t& other) const = delete;
  Class_t operator&&(Class_t&& other) const = delete;

};

int main()
{
    Class_t t(1);
    std::vector<Class_t> myvector;
    myvector.reserve(10);
    //myvector.resize(19);
    //auto   cpy_vector = 
    myvector.push_back(Class_t(1));
    myvector.emplace_back(19);



  return 0;
}
