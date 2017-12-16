#include <omp.h>
#include <iostream>
#include <time.h>
using namespace std;
int main(int argc, char const *argv[]) {
  clock_t start, end;
  start = clock();
  cout<<omp_get_num_procs()<<"\n";
  int z=0;
  #pragma omp parallel for
  for(int i=0; i<4000; ++i){
    for(int j=0; j<4000; ++j){
      z=i+j;
      std::cout << i <<","<< j<<'\n';
      }
    }
    end = clock();
  //cout<< (end - start) / 1000<<"\n";
  return 0;
}


#include <iostream>
#include <string.h>
#include <pqxx/pqxx>
using namespace std;
using namespace pqxx;
//################################################### CONEXION ################################################
   string dbname= "fmedel";
   string user= "fmedel";
   string password= "latoo+12";
   string hostaddr= "127.0.0.1";
   string port= "5432";
   string conexion= "dbname ="+dbname+" user = "+user+" password = "+password+" hostaddr = "+hostaddr+" port = "+port;
//###########################################cabesera##################################################################

int main(int argc, char const *argv[]) {
printf("entro en buscar_camino_bd\n");
  connection conn(conexion);
  if (conn.is_open()) {
      cout << "bd abierta con exito: " << conn.dbname() << endl;
  }
  else{
      cout << "Error al abrir bd" << endl;
  }
  conn.disconnect ();
    return 0;
}

g++ prueba.cpp -o p -lpqxx -lpq -fopenmp
