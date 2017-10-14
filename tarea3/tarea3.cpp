
#include <stdio.h>  //para el printf fopen
#include <string>
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <sstream>

using namespace std;

void leer_archivo(){
  int m=0,n=0;
  FILE *archivo0_5000=fopen("t1.csv", "w");
  FILE *archivo5001_10000=fopen("t2.csv", "w");
  FILE *archivo10001_15000=fopen("t3.csv", "w");;
  FILE *archivo15001_20000=fopen("t4.csv", "w");;
  FILE *archivo = fopen("datos.csv", "r");
  if (archivo==NULL){std::cout << "error en archivo"<< '\n';}
  if (archivo0_5000==NULL){std::cout << "error en archivo t1"<< '\n';}
  if (archivo5001_10000==NULL){std::cout << "error en archivo t2"<< '\n';}
  if (archivo10001_15000==NULL){std::cout << "error en archivo t3"<< '\n';}
  if (archivo15001_20000==NULL){std::cout << "error en archivo t4"<< '\n';}
  int A1=0,A2=0,A3=0,A4=0;
  char line[200];

  while (fgets(line, sizeof(line), archivo)){
    n++;
    m=atoi(line);
      if (m>=0 and m<=500000){
      fprintf(archivo0_5000, "%s",line );
      A1++;}
      else if (m>=500000 and m<=1000000){
      fprintf(archivo5001_10000, "%s",line );
      A2++;}
      else if (m>=1000000 and m<=1500000){
      fprintf(archivo10001_15000, "%s",line );
      A3++;}
      else if (m>1500000){
      fprintf(archivo15001_20000, "%s",line );
      A4++;}
      else {
        std::cout << line << '\n';
      }
    }
  fclose(archivo);
  fclose(archivo0_5000);
  fclose(archivo5001_10000);
  fclose(archivo10001_15000);
  fclose(archivo15001_20000);
  std::cout << n <<"-"<<A1+A2+A3+A4<<'\n';
}

int main(int argumentos, char *datos[]) {
    leer_archivo();
  	cout<<"calculo listo "<<endl;

  return 0;
}
