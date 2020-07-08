#include <cctype>
#include <ciso646>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <dirent.h>

#ifdef _WIN32
  #include <io.h>
  #include <fcntl.h>
  #define isatty _isatty
  #define fileno _fileno
#else // POSIX
  #include <unistd.h>
#endif
using namespace std;

int main( int argc, char** argv )
{
DIR *directory;
struct dirent * elements;
string elem;
string dir;

cout<<"program list name directory"<<endl;

	if(directory=opendir(dir.c_str()))
//	if(directory=opendir("/home/optimus/Documents"))
	{
	while((elements=readdir(directory) )!=NULL)
		{
		elem=elements->d_name;
		cout << "name directory: "<<elem<<endl;
		}
	}

closedir(directory);

return 0;
}
