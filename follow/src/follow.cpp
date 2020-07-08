#include <iostream>
#include <fstream>
#include <unistd.h>
#include <errno.h>
#include "follow.h"

using namespace std;

follow::follow(){
  cout<<"constructor follow"<<endl;
};

follow::~follow(){cout<<"destructor follow"<<endl;};
//void menu::function(void){}
