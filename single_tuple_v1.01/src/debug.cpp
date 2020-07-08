#include <iostream>
#include <string>
#include "debug.h"



    const void Debug::dbg(std::string str) const{
    #ifdef DBG
        std::cout<< str <<" - step : " << this->c <<std::endl;
    #endif // !DBG
        this->c++;
    }

    void extern_dbg (std::string tmp) {
       Debug dbg ;
        dbg.dbg(tmp);
    }
