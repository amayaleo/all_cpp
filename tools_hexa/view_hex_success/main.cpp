#include <cctype>
#include <ciso646>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#ifdef _WIN32
  #include <io.h>
  #include <fcntl.h>
  #define isatty _isatty
  #define fileno _fileno
#else // POSIX
  #include <unistd.h>
#endif

/*
-------------------------------------------------------------------------------
1234567890  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16  1234567890123456
*/
void dump( std::istream& ins )
{
  std::cout << std::setfill( '0' ) << std::hex << std::uppercase;

  std::size_t offset = 0;
  while (ins)
  {
    char s[ 16 ];
    std::size_t n, i;

    std::cout << std::setw( 10 ) << (offset & 0xFFFFFFFFFF) << "  ";
    offset += sizeof(s);

    ins.read( s, sizeof(s) );
    n = ins.gcount();

    for (i = 0; i < n; i++)
      std::cout << std::setw( 2 ) << (int)s[ i ] << " ";

    while (i++ < sizeof(s))
      std::cout << "   ";
    std::cout << "  ";

    for (i = 0; i < n; i++)
      if (std::isprint( s[ i ] )) std::cout << s[i];
      else                        std::cout << ".";

    std::cout << "\n";
  }
}

//-----------------------------------------------------------------------------
int main( int argc, char** argv )
{
  if (argc < 2)
  {
    // Display usage if stdin is a human
    if (isatty( fileno(stdin) ))
    {
      std::string filename = argv[ 0 ];
      filename.erase( 0, filename.find_last_of( "/\\" ) + 1 );
      auto n = filename.rfind( '.' );
      if ((n > 0) and (n != filename.npos)) filename.erase( n );

      std::cerr << 
        "usage:\n"
        "  " << filename << " FILENAME ...\n"
        "  " << filename << " < FILENAME\n"
        "  SOMEPROG | " << filename << "\n\n"
        "Display the hexadecimal dump of each named file.\n\n";
      return 0;
    }

    // Dump stdin
    #ifdef _WIN32
    _setmode( fileno(stdin), _O_BINARY );
    #endif
    
    dump( std::cin );
  }
  else
  {
    // Dump all named files
    for (int n = 1; n < argc; n++)
    {
      std::ifstream f( argv[ n ], std::ios::binary );
      if (!f) 
      {
        std::cout << "Could not open " << argv[ n ] << "\n";
        continue;
      }
      std::cout << argv[ n ] << "\n";
      dump( f );
    }
  }
}
