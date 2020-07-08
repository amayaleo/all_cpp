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
  uint32_t c;
  // explicit Class_t( uint32_t x ) : c (x){std::cout << "Constructor me .\n";};

  // Class_t(Class_t&& other) :  c(std::move(other.c)){std::cout << "Class type president .\n"; }

  Class_t ( uint32_t x_arg) : c (x_arg) { std::cout << "Class_t (x_arg)\n"; };

  Class_t (const  Class_t & rhs   ) noexcept { priv_x = rhs.priv_x; std::cout << "Class_t (Class_t &)\n"; }

  Class_t (       Class_t && rhs  ) noexcept { priv_x = rhs.priv_x; std::cout << "Class_t (Class_t &&)\n"; }

  Class_t& operator=(const Class_t& other) = default;

  //Class_t& operator=(Class_t&& other) = default;
};

class A
{
public:
  A (uint32_t x_arg) : x (x_arg) { std::cout << "A (x_arg)\n"; }
  A () { x = 0; std::cout << "A ()\n"; }
  A (const  A & rhs   ) noexcept { x = rhs.x; std::cout << "A (A &)\n"; }
  A (       A && rhs  ) noexcept { x = rhs.x; std::cout << "A (A &&)\n"; }

private:
  uint32_t x;
};




int main()
{
    Class_t t(4);

    std::vector<Class_t> myvector ;

    
    myvector.reserve(10);

    myvector.push_back(5);
    myvector.push_back(9);
    auto & vector_tmp=  myvector.emplace_back(34);
    //auto & vector_tmp2=  myvector.push_back(3);
    //vector_tmp.resize(11,t);
  
    //auto   cpy_vector = 
// 
     myvector.emplace_back(19);
         //myvector.push_back(Class_t(1));
//     myvector.push_back(Class_t(15));
 //    myvector.push_back(Class_t(7));

      //myvector.push_back(5);
      //myvector.push_back(7);

    // myvector.push_back(std::move(Class_t(39)));       
    // vector_tmp.push_back(Class_t(4));
    // vector_tmp.push_back(Class_t(3));
  //  {
  //   std::vector<A> a;
  //   std::cout << "call emplace_back:\n";
  //   a.emplace_back (0);
  // }
  
     //vector_tmp.emplace_back(24);
    // vector_tmp.push_back(Class_t(7));
    std::cout<<"size vector : "<<myvector.size() <<std::endl;


for( const auto & m_vect : myvector)
{

  std::cout<<"value my vector : "<<    m_vect.c  <<std::endl;

}


  std::cout<<" **********************************\n";

for ( std::vector<Class_t>::iterator it = myvector.begin()  ; myvector.end() != it; it++)
  {
    //std::cout<<"value my vector : "<<    vector_tmp.c <<std::endl;

  }

  return 0;
}
















  // uint32_t dev(){
  //   return priv_x;
  // };

  // Class_t (const Class_t&){

  // }

//  Class_t (Class_t&&){

// std::cout << "  Class_t (Class_t&&) \n";
//   }



  //Class_t& operator=(const Class_t& )  { std::cout << " const Class_t & \n"; return *this;} ;
  
  //Class_t& operator=(Class_t&& ) { std::cout << "  Class_t && \n"; return *this;} ;

  //Class_t operator&(const Class_t& other) const = delete;
  //Class_t operator&&(Class_t&& other) const = delete;