#pragma once
#include <cstdint>
#define DBG true

struct Debug{
       explicit Debug(){};

        ~Debug()=default;

        const void dbg(std::string)const;

    private:
        inline static uint32_t c{0};
};


void extern_dbg (std::string);