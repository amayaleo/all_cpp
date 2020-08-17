#pragma once
#include<vector>
#include<string>

namespace  RUN{
	struct Ls{
			explicit Ls();
		  	explicit Ls(std::string && );
			explicit Ls(Ls &&);
			~Ls()=default;
		   Ls& operator=(const Ls& other) = default;
		bool get_ls() const;
		void put_ls() const;
		void current_ls()const;
		void current_files();
		const std::string get_name() const;
	private:
		std::string name;
		uint32_t id { 0 };
		static inline std::vector < Ls > member_tmp {};
	};
    
}