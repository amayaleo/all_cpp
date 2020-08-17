#include <iostream>
#include <cstdint>
#include <vector>
//#include <algorithm>
//#include <memory>

//#define DBG 

struct B{
   B()
   {   
      #ifdef DBG
        std::cout<<  "  B() "<< std::endl; 
      #endif  
     };

  ~B(){   
      #ifdef DBG
        std::cout<<  " ~B() "<< std::endl;  
      #endif
    };

void b(){  std::cout<<  "get()  "<< std::endl;}
};


struct A //: public B
{
   A():z{} , m_variable { 0 } 
    { 
        #ifdef DBG
          std::cout<<  "  A() "<< std::endl; 
        #endif
    };

  ~A(){      
      #ifdef DBG
       std::cout<<  " ~A()  "<< std::endl;
      #endif
       };

void a()
  { 
    std::cout<<  "function a()  "<< std::endl;
  }
  struct  C
  {
    C(){   
          #ifdef DBG
            std::cout<<  "  C() "<< std::endl;
          #endif
       
      };
    ~C(){   
          #ifdef DBG
           std::cout<<  " ~C() "<< std::endl;
          #endif
        
      };
    void c(){std::cout<<  "c()  "<< std::endl;}
  };

  C z;
  void set ()
  {
        m_variable++;
  }

    void print ()
  {
    std::cout<<  "variable : " <<m_variable <<std::endl;
  }

  private:
    uint32_t m_variable;
};


int main()
{


try
  {
std::vector<A> a;
a.reserve(128);

for (int i = 0 ;i<24 ;i++)
    a.emplace_back();
auto& v =  a.emplace_back();



  std::cout<<  " a.capacity() :  " << a.capacity() << std::endl;

  for( auto& i : a )
    {
      v.set();
    }

     v.print();
  std::cout<<  "out  program ... "  << std::endl;

  }
catch(...){
  std::cout<<  "error  program ... "  << std::endl;
}
  return 0;
}
