#include <iostream>
#include <fstream>
//#include <string.h>
#include <string>
#include "file.h"
using namespace std;


File::File(){  cout<<"constructor File"<<endl;
  //write_file();
  read_file();
  //analize();
}

File::~File(){  cout<<"destructor File"<<endl;
}

void File::read_file(){

bool fd ;
int counter_follow=0;
string line;
std::ifstream msfile("follow.txt");
std::ofstream wsfile;

wsfile.open("follow.csv");

if (msfile.is_open())
  {
    while ( getline (msfile,line) )
    {

      //this->compare = line[0];

bool eval;
int value_tmp = line.size();
value_tmp=value_tmp-1;
cout << "value_tmp : "<<value_tmp<<endl;
eval=1;
for (int cmp=0; cmp < value_tmp ; cmp++ )
{
  if(   line[cmp] == 0x20 ){eval=0;break;}
  if( !( line[cmp]>=94 && line[cmp]<=122 )  )
  {
    eval=0;
  }
  if( (line[cmp]>=48 && line[cmp]<=57 )  )eval=1;


  //  if(   line[cmp] == 0x2e )eval=1;
  if( line[cmp]==46)eval=1;
  if( line[cmp]==0x40){eval=0;break;}
}


if(eval== 0 )cout <<" contiene espacios "<<endl;


//if(compare>94 && compare<122)
//if(eval==1 && (line[0]>94 && line[0]<122))
if(eval)
      {
        cout << "name user TRUE : " << endl;
        counter_follow++;
        wsfile<<line<<"\r\n";
      }
else
      {
        cout << "name user FALSE : "  ;
      }
      //cout << this->compare  <<endl;
      cout << '\t'<< '\t'<< '\t'<<line << '\r' <<'\n';
      //cout << line << endl;
    }

    msfile.close();
  }
  wsfile.close();
msfile.close();

cout <<" *************************************** "<<endl;
cout <<" FOLLOWS : "<< counter_follow <<endl;
cout <<" *************************************** "<<endl;
return ;
}



void File::write_file(){
bool fd ;
//string line;
std::ofstream fsfile;
  fsfile.open("follow2.txt");
  for( int n_follow=0;n_follow<50;n_follow++){
    fsfile<<"follow_"<<n_follow<<"\r\n";
  }

  fsfile.close();
  return ;
}




void File::analize(){

std::ifstream analize_file("file_analize.txt");
analize_file.is_open();
std::string analize_line;
if (analize_file.is_open())
  {
    while ( getline (analize_file,analize_line) )
    {

        cout<< "analize_line : " << analize_line<<endl;

        int tmp  =analize_line .size();
        cout<<"name : " << "tmp size : " << tmp << endl;
        for (int j=0 ;j<tmp;j++){
          int value =  analize_line[j];
          cout<< value <<",";
        }
        cout<< endl;

    }
  }
  analize_file.close();
}
