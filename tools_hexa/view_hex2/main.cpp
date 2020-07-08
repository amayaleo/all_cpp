#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


string toBase( unsigned i, unsigned base )
{ 
   const string DIGITS = "0123456789ABCDEF";
   return i ? toBase( i / base, base ) + DIGITS[i%base] : "";
}


int main( int argc, char *argv[] )
{
  string filename = argv[1];
   unsigned base = atoi( argv[2] );

   const int LINELENGTH = 10;

   int width = toBase( 255, base ).size();
   char c;
   int counter = 0;

   ifstream in( filename, ios::binary );
   while ( in.get( c ) )
   {
      cout << setw( width + 1 ) << toBase( (unsigned)c, base );
      counter++;
      if ( counter%LINELENGTH == 0 ) cout << '\n';
   }
}

