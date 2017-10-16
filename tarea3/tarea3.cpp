
#include <stdio.h>  //para el printf fopen
#include <string>
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <sstream>

using namespace std;

int separ_archivo(long areglo[2]){
  long m=0,n=0;
  FILE *archivo1=fopen("t1.csv", "w");
  FILE *archivo2=fopen("t2.csv", "w");
  FILE *archivo3=fopen("t3.csv", "w");
  FILE *archivo4=fopen("t4.csv", "w");
  FILE *archivo5=fopen("t5.csv", "w");
  FILE *archivo6=fopen("t6.csv", "w");
  FILE *archivo7=fopen("t7.csv", "w");
  FILE *archivo8=fopen("t8.csv", "w");
  FILE *archivo9=fopen("t9.csv", "w");
  FILE *archivo = fopen("../../datos.csv", "r");
  if (archivo==NULL){std::cout << "error en archivo"<< '\n';}
  if (archivo1==NULL){std::cout << "error en archivo t1"<< '\n';}
  if (archivo2==NULL){std::cout << "error en archivo t2"<< '\n';}
  if (archivo3==NULL){std::cout << "error en archivo t3"<< '\n';}
  if (archivo4==NULL){std::cout << "error en archivo t4"<< '\n';}
  if (archivo5==NULL){std::cout << "error en archivo t5"<< '\n';}
  if (archivo6==NULL){std::cout << "error en archivo t6"<< '\n';}
  if (archivo7==NULL){std::cout << "error en archivo t7"<< '\n';}
  if (archivo8==NULL){std::cout << "error en archivo t8"<< '\n';}
  if (archivo9==NULL){std::cout << "error en archivo t9"<< '\n';}
  long A1=0,A2=0,A3=0,A4=0,A5=0;
  long A6=0,A7=0,A8=0,A9=0,A10=0;
  char line[200];
  while (fgets(line, sizeof(line), archivo)){
    n++;
    m=atoi(line);
      if (m>=0 and m<=250000000){
      fprintf(archivo1, "%s",line );
      A1++;}
      else if (m>=250000000 and m<500000000){
      fprintf(archivo2, "%s",line );
      A2++;}
      else if (m>=500000000 and m<750000000){
      fprintf(archivo3, "%s",line );
      A3++;}
      else if (m>=750000000 and m<1000000000){
      fprintf(archivo4, "%s",line );
      A4++;}
      else if (m>=1000000000 and m<1250000000){
      fprintf(archivo5, "%s",line );
      A5++;}
      else if (m>=1250000000 and m<1500000000){
      fprintf(archivo6, "%s",line );
      A6++;}
      else if (m>=1500000000 and m<1750000000){
      fprintf(archivo7, "%s",line );
      A7++;}
      else if (m>=1750000000 and m<2000000000){
      fprintf(archivo8, "%s",line );
      A8++;}
      else if (m>=2000000000){
      fprintf(archivo9, "%s",line );
      A9++;}
      else {
        std::cout << line << '\n';
        A10++;
      }
    }
  fclose(archivo);
  fclose(archivo1);
  fclose(archivo2);
  fclose(archivo3);
  fclose(archivo4);
  fclose(archivo5);
  fclose(archivo6);
  fclose(archivo7);
  fclose(archivo8);
  fclose(archivo9);
  std::cout << "total "<< n << '\n';
  std::cout << "archivo 1 "<< A1 << '\n';
  std::cout << "archivo 2  "<< A2 << '\n';
  std::cout << "archivo 3  "<< A3 << '\n';
  std::cout << "archivo 4  "<< A4 << '\n';
  std::cout << "archivo 5  "<< A5 << '\n';
  std::cout << "archivo 6  "<< A6 << '\n';
  std::cout << "archivo 7 "<< A7 << '\n';
  std::cout << "archivo 8  "<< A8 << '\n';
  std::cout << "archivo 9  "<< A9 << '\n';
  std::cout << "archivo 10  "<< A10 << '\n';
  std::cout << "Suma" << A1+A2+A3+A4+A5+A6+A7+A8+A9+A10 <<'\n';
  m=n/2;

  if (m<A1) {
    areglo[0]=n;
    areglo[1]=A1;
    return 1;
  } else if (m<=A2) {
    areglo[0]=n;
    areglo[1]=A2;
    return 2;
  } else if (m<=A3) {
    areglo[0]=n;
    areglo[1]=A3;
    return 3;
  } else if (m<=A4) {
    areglo[0]=n;
    areglo[1]=A4;
    return 4;
  } else if (m<=A5) {
    areglo[0]=n;
    areglo[1]=A5;
    return 5;
  } else if (m<=A6) {
    areglo[0]=n;
    areglo[1]=A6;
    return 6;
  } else if (m<=A7) {
  areglo[0]=n;
  areglo[1]=A7;
  return 7;
  } else if (m<=A8) {
    areglo[0]=n;
    areglo[1]=A8;
    return 8;
  } else if (m<=A9) {
      areglo[0]=n;
      areglo[1]=A9;
      return 9;
  }

}

int main(int argumentos, char *datos[]) {
    int archivo;
    long arreglo[2]={0,0};
    archivo= separ_archivo(arreglo);
    std::cout << arreglo[0]<<" "<<arreglo[1] <<" "<< archivo<< '\n';

  	cout<<"calculo listo "<<endl;

  return 0;
}
