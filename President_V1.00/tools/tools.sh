#!/bin/bash

#  https://cppinsights.io/

#sudo apt-get install valgrind kcachegrind -y 
rm app resumeValgrind.txt callgrind.out.* infoCallgrind.*

cp  ../build/app .

valgrind ./app > resumeValgrind.txt

#>> valgrind --tool=callgrind --dump-instr=yes --simulate-cache=yes --collect-jumps=yes --collect-atstart=no --instr-atstart=no <executable> [args...]
#./app

#valgrind --tool=callgrind --dump-instr=yes ./app

valgrind --tool=callgrind --dump-line=yes ./app

callgrind_annotate --auto=yes callgrind.out.* > infoCallgrind.txt


