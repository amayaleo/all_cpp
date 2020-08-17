/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//	autor : 
//						Amaya Leo
//	Compilardor:
//						g++
//
//	Tipo de aplicacion:
//
//	Caracteristicas:
//
//	Makefile:
//
//	Library :							
//	                    ls.h
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdint>
#include <string>
#include <filesystem>
#include <vector>
#include "ls.h"


namespace  RUN
{

namespace fs = std::filesystem;
    Ls::Ls()
    // : id{ 0 } , name { nullptr}
   : Ls{ {} } 
    {
            std::printf("Ls() \n ");
            member_tmp.reserve(10);
    }
    

    Ls::Ls(std::string && str )
    :  name(std::move(str))
    {
            std::printf("Ls( std::string && ) \n ");
    }

    Ls::Ls(Ls && other )
    :  name(std::move(other.name)) 
    {
                       std::printf("Ls( Ls && ) \n ");

    }


    bool Ls::get_ls() const
    {       
    std::printf("command ls -asl \n ");
    std::string path = "../bmp_files/"; //FILES_BMP
    std::vector <Ls> member_t;
    
    static uint32_t id_tmp{0};
    
    //const auto & it = fs::directory_iterator(path);

    //member_tmp.resize (it.capacity());

    for (const auto & entry : fs::directory_iterator(path))
        {
           auto & it =  member_tmp.emplace_back(static_cast<std::string>(entry.path()) );
            it.id=id_tmp++;
            std::cout << "\t\t files : " << it.get_name()<< std::endl;
        }
        
        return true;
    }

    void Ls::put_ls() const
    {
        if(get_ls()){}
        else std::printf("no hay ningun archivo\n");
    }


    const std::string Ls::get_name() const
    {
       return name;
    }


    void Ls::current_ls()const{

    fs::path p = fs::current_path();
 
    std::cout << "The current path " << p << " decomposes into:\n"
              << "root name " << p.root_name() << '\n'
              << "root directory " << p.root_directory() << '\n'
              << "relative path " << p.relative_path() << '\n';
    }

void Ls::current_files(){

        for(auto & it : member_tmp)
        {
            std::cout<<"link : " << it.name <<" - id : " << it.id <<std::endl;
        }
    }

}