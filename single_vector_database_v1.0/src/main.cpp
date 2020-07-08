#include <iostream>
#include <algorithm>
#include <cstdint>
#include <memory>
#include <vector>


class Class_t
{
public:
  Class_t (int x_arg) : x (x_arg) { std::cout << " Class_t (x_arg)\n"; }
  Class_t () { x = 0; std::cout << "Class_t ()\n"; }
  Class_t (const Class_t &rhs) noexcept { x = rhs.x; std::cout << "Class_t (Class_t &)\n"; }
  Class_t (Class_t &&rhs) noexcept { x = rhs.x; std::cout << "Class_t (Class_t &&)\n"; }

private:
  int x;
};

int main ()
{
  {
    std::vector<Class_t> class_tmp;
    std::cout << "call emplace_back:\n";
    class_tmp.emplace_back (0);

  }
  {
    std::vector<Class_t> class_tmp;
    std::cout << "call push_back:\n";
    class_tmp.push_back (1);
  }

  
  return 0;
}
