#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
using namespace std;

int main( int argc, char* argv[] )
{
      ofstream myfile;
      myfile.open ("datos.csv");
      for (size_t i = 0; i < 2000000000; i++) {
          myfile <<rand()%100000<<"\n";
      }
      myfile.close();
      return 0;
}
