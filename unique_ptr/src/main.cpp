
#include <cstdint>
#include <iostream>
#include <memory>

struct ClassTmp{
  private:
  uint16_t tmp;

  public:
  ClassTmp()=default;
  ~ClassTmp()=default;
  void function(){
    std::cout<<  "function()" <<std::endl;   
  }
};


int main(void){

//using screenTmp = std::unique_ptr<uint32_t[]> ;

std::unique_ptr <uint32_t[]> screen {};  
uint16_t memory_position=1024; // posicion de memoria


screen = std::make_unique<uint32_t[]>(memory_position);

auto view = std::make_unique<uint32_t[]>(memory_position*2);
view = std::move (screen);


ClassTmp* mclass= new ClassTmp();

mclass->function();

  try{

    uint32_t *value = screen.get();

    std::cout<<  "\t\t\tscreen : " << &value <<std::endl;    

    delete mclass;
  }
  catch(...){
    std::cout<<  "******************************* " <<std::endl; 
  }

  return 0;
}

