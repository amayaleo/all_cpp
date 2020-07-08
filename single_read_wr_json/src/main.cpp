#include <iostream>
#include <fstream>
#include <vector>
#include <string_view>
#include <cstring>
#include <cstdint>
#include <memory>
#include <iterator>
#include <exception>

#include "picoJSON/picojson.hpp"

struct File_t{

	explicit File_t()=default;
	~File_t()
	{
	}


void json_to_bin()
{
	namespace pj = picojson;

	const std::string_view file_r = "../file/j1.json";
	
    const std::string_view file_w = "../file/jsbin.bin";

    std::ifstream pfile_r( file_r.data() );
    
   	if(!pfile_r) throw std::runtime_error("no open file\n");

	std::ofstream pfile_w( file_w.data() , std::ofstream::binary | std::ofstream::trunc );

    if(!pfile_w) throw std::runtime_error("no open file\n");
  

	picojson::value json;

	pfile_r >> json;
	
	std::string err { pj::get_last_error() };
	
	if(!err.empty()) 
	{
		throw std::runtime_error(err);
	}

		const auto& root { json.get<pj::object>() };

		const auto& height {static_cast<uint32_t>(root.at("height").get<double>() )};
        
        const auto& width {static_cast<uint32_t>(root.at("width").get<double>())};

        const auto& map { root.at("map").get<pj::array>() };


        std::cout << " height : "<< height << std::endl;

        std::cout << " width : "<< width << std::endl;
        
	if(map.size() != width*height) throw std::runtime_error ("map error \n");
	
	pfile_w.write(reinterpret_cast<const char*>(&height), sizeof(height));
	
    pfile_w.write(reinterpret_cast<const char*>(&width), sizeof(width));

	for (auto& elem : map){
		const auto& tile { static_cast<uint8_t>( elem.get<double>() ) };		
        pfile_w.write(reinterpret_cast<const char*>(&tile) , sizeof tile);
	}
	
		pfile_w.close();
		pfile_r.close();
	}



struct JsonStruct{
	uint32_t height;
	uint32_t width;
	std::vector<bool>map_size_bool;
};


void read_json_bin()
{
	namespace pj = picojson;

	const std::string_view read_json_bin = "../file/jsbin.bin";

    std::ifstream pfile_json_bin( read_json_bin.data()  , std::ifstream::binary);
    
    	if(!pfile_json_bin) throw std::runtime_error("no open file\n"); 

	std::size_t str_length = [&](){
		 pfile_json_bin.seekg (0 , std::ifstream::end);//lleva el puntero de lectura al final de archivo
		 const auto size_tmp { pfile_json_bin.tellg()};
		 pfile_json_bin.seekg (0 , std::ifstream::beg);//lleva el puntero de lectura al inicio de archivo
		 return size_tmp;
 	}();// lo convierte en algo similar a una funcion . ex : lambda()

	 std::cout<< "str lenght : "<< str_length << "\n";

	 std::vector<char>memory_file(str_length);//necesario para guardar un vector de bytes del archivo completo

	 char * pfile_of_binary = memory_file.data();//para trabajat con un puntero la data comlpeta del vector

	pfile_json_bin.read( pfile_of_binary, str_length); // read ( *puntero  , tamaño_del_buffer ) lee el buffer y la apunta a  *puntero

	uint32_t height { 0 }, width { 0 }; 

	memcpy(&height , pfile_of_binary , sizeof height); // copia 4 bytes en una variable
	
	pfile_of_binary += 4; //recorre el puntero

	memcpy(&width, pfile_of_binary , sizeof width);

	pfile_of_binary += 4;

	 std::cout<< "width : "<< width << "\n";
	 
	 std::cout<< "height : "<< height << "\n";

	 for( int i =0;i<width*height;i++){
			if(!(i%16))std::cout<<"\n";
		 if(*pfile_of_binary++)
		 {
			 std::cout<<"\t1";
		 }
		 else {
			 std::cout<<"\t0";
		 }
		 
	 }
	
	std::cout<<"\n";

	pfile_json_bin.close();
	}

};



int main(){
try
	{
		File_t me_json;
		me_json.json_to_bin();
		me_json.read_json_bin();
	}
catch(std::exception& e)
	{
		std::cout << "msj : " <<e.what()<<std::endl;
	}
catch(...)
	{
		std::cout<<"Error de programa" <<std::endl;
	}


return 0;
}
