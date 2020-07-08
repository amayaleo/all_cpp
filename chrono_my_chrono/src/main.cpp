#include <iostream>
#include <chrono>
#include <ctime>


struct TimeCalc{

explicit TimeCalc()
	: //member_start{0} , member_end{0} ,
	 elapsed_seconds{0}
	{

	};
		
	void init()
	{
		member_start = std::chrono::system_clock::now();
	}
 	
 	void end(){
 	
		member_end = std::chrono::system_clock::now();
 	}
 	
	void print_calculate_estimed(){
		elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(member_end-member_start).count();
		std::time_t end_time = std::chrono::system_clock::to_time_t(member_end);
		std::cout << "Cálculo terminado  " << std::ctime(&end_time)
		<< "tiempo transcurrido: " << elapsed_seconds << "s\n";
 	}
    
              
	private: 
		std::chrono::time_point<std::chrono::system_clock>member_start, member_end;
		uint32_t elapsed_seconds;
};
 
int fibonacci(int n)
{
    if (n < 3) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
 
int main()
{
	TimeCalc t;
	
	t.init();
	[[maybe_unused]]int result = fibonacci(42);
	t.end();
	t.print_calculate_estimed();
//	TimeCalc::init();
}
