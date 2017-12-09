#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "blowfish.h"
#include <mpi.h>

using namespace std;

int sacar_respuesta(int total_nodos, int nodo)
{
    char clave[6];
    char *char_decifrado;
    bool alfabeto=false;
    char encriptado[]="08fd193b1771a99ac34474e745f4ad521a1ba438f3c63892a860d0e8bd55cbb93b45113aa4954da6019e440a928ad02b65c895eb94d91225ef5ec177c095de0d110ac76a67fe56aa45a7595da9514d23b454e109ec4a2dbbc40f32befe39214e2a304bb3f2477511e909a20e80bf02c07b01c833589031ec7dc22c8b1311bbfa";
    int inicio;
    int fin;
    inicio= ((75/total_nodos)*nodo)+48;
    if (nodo+1 == total_nodos) {
      fin=123;
    }else{fin=(75/total_nodos)*(nodo+1)+48;}
    std::cout << inicio<<"-"<<fin<< '\n';
    try{
      for (int x = inicio; x < fin; x++) {
        if (!((x>=65 && x<=90) || (x>=97 && x<=122) ||(x>=48 && x<=57) )) {continue;}

        for (int y = 48; y <= 165; y++) {
          if (!((y>=65 && y<=90) || (y>=97 && y<=122) ||(y>=48 && x<=57) )) {continue;}
          for (int z = 48; z <= 122; z++) {
            if (!((z>=65 && z<=90) || (z>=97 && z<=122) ||(z>=48 && z<=57) )) {continue;}
            for (int c = 48; c <= 122; c++) {
              if (!((c>=65 && c<=90) || (c>=97 && c<=122) ||(c>=48 && c<=57) )) {continue;}
              for (int q = 48; q <= 122; q++) {
                if (!((q>=65 && q<=90) || (q>=97 && q<=122) ||(q>=48 && q<=57) )) {continue;}
                for (int w = 48; w <= 122; w++) {
                  if (!((w>=65 && w<=90) || (w>=97 && w<=122) ||(w>=48 && w<=57))) {continue;}
                  clave[0]=(char)x;
                  clave[1]=(char)y;
                  clave[2]=(char)z;
                  clave[3]=(char)c;
                  clave[4]=(char)q;
                  clave[5]=(char)w;
                  std::cout << clave << '\n';
                  char_decifrado= descifrar(clave, encriptado );
                  for (int g=0; g<strlen(char_decifrado); g++){
                      if ((int(char_decifrado[g])>=65) && (int(char_decifrado[g])<=122)){
                           alfabeto=true;
                      }
                      else{
                          alfabeto=false;
                          break;
                      }
                  }
                  if (alfabeto==true){
                      if(strlen(char_decifrado)>5){
                          printf("%s------(clave)>%s\n",char_decifrado, clave );
                      }
                  }
                  }
                }
              }
            }
          }
        }
    }
    catch(int err_code){
        printf("ERROR s %d", err_code);
    }
}
int main(int argc, char** argv)
{
    int total_equipos;
    int nodo;
    MPI_Status estatus;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &total_equipos);
    MPI_Comm_rank(MPI_COMM_WORLD, &nodo);
    MPI_Barrier(MPI_COMM_WORLD);
    sacar_respuesta(total_equipos,nodo);
    MPI_Finalize();
    return 0;
}
