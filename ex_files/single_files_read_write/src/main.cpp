#include <iostream>
#include <fstream>
#include <vector>
#include <string_view>
#include <cstring>
#include <cstdint>
#include <memory>
struct File_t{

	explicit File_t()=default;
	~File_t()
	{
//		file_close();
	}

	void read_file()
	{
		std::ifstream file(filename_w , std::ifstream::binary);

		if(!file.is_open())
			{
				throw std::runtime_error("no open file\n");
			}

		std::size_t length = [&]()
		{
 			file.seekg(0,std::ifstream::end);
 			auto l {file.tellg()};
 			file.seekg(0, std::ifstream::beg);
 			return l;
		}();

		 std::vector <char> filemem(length);
		 auto* pfilemem = filemem.data();
		 file.read(pfilemem,length);
		 uint32_t h{} , w {};
		 char p ; 
		 std::memcpy(&w , pfilemem + 0 , sizeof w);
		 std::memcpy(&h , pfilemem + 4 , sizeof h);

		for (int i= 0 ;i< 256 ; i++){
			std::memcpy(&p , pfilemem + i , sizeof h);
			std::cout << p ;
		}
	}
	
	
	

void write_file()
{

	filename_w = "../file/myfile.txt";
 	file_w.open(filename_w , std::ifstream::binary);

 	if(!file_w.is_open())
 	{
 		throw std::runtime_error("no open file\n");
 	}

	//std::unique_ptr<uint8_t> buffer;//(new char[256]);
	
 	std::unique_ptr<char[]> buffer(new char[1024]);
 
 	for (size_t i=0; i < 256; i += 16)
 	{
     	memcpy(&buffer[i], "012345678901234\n", 16);
   	}

 	  file_w.write(buffer.get(),255);

	  file_w.close();
}


void write_file_to_json()
{

	filename_w = "../file/myfile.txt";
 	file_w.open(filename_w , std::ifstream::binary);

 	if(!file_w.is_open())
 	{
 		throw std::runtime_error("no open file\n");
 	}

	
	
 	std::unique_ptr<char[]> buffer(new char[1024]);
 
 	for (size_t i=0; i < 256; i += 16)
 	{
     	memcpy(&buffer[i], "012345678901234\n", 16);
   	}

 	  file_w.write(buffer.get(),255);

	  file_w.close();
}


void file_close(std::ifstream& ifstr)
{
	//close(ifstr);

// std::size_t length = [&](){
// 		priv_read_file.seekg(0,std::ifstream::end);
// 		auto l {priv_read_file.tellg()};
// 		priv_read_file.seekg(0, std::ifstream::beg);
// 		return l;
// 	}

}

private:
	std::string filename_w;
	//std::ifstream file; 
	std::string_view filepath;
	std::ofstream file_w;
	//namespace pj = picojson;

};



int main(){
try
	{
		File_t meFile;
		meFile.write_file();		
		meFile.read_file();
	}
catch(...)
	{
		std::cout<<"Error de programa" <<std::endl;
	}


return 0;
}
