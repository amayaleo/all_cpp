

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class info{
    private: 
        int id;
        string name;
    public:
        info(int extId, string extName) {
            this->id = extId;
            this->name = extName;
        }
        void print(){
        
        };
};





class addressBook {
public:
	string name = "Joe";
	double phone = 5555;
};

class db {
    private:
    vector<info> infoVector;
    public:
    void pushData(info data) {            // note: not a pointer
        this->infoVector.push_back(data); // note: not address-of
    }
};

int main(){ 
    info testData(123, "nice"); // note: not a pointer
    std::vector<info>infoVector;
//auto & info_tmp =  
   infoVector.push_back(testData);
    
    
    
    
    
    
std::vector<addressBook> entry;
//	entry.push_back();
	


std::vector<addressBook> bar;

bar.push_back( addressBook() ); 

    
    
    
    
    //db database;
    //database.pushData(testData);
    return 0;
}


