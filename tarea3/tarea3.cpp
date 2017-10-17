
#include <stdio.h>  //para el printf fopen
#include <string>
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <sstream>

using namespace std;

int separ_archivo(long areglo[2], long datos_int, int archivo_tem){
  long m=0,n=0;
  FILE *archivo;
  FILE *archivo1=fopen("t1.csv", "w");
  FILE *archivo2=fopen("t2.csv", "w");
  FILE *archivo3=fopen("t3.csv", "w");
  FILE *archivo4=fopen("t4.csv", "w");
  FILE *archivo5=fopen("t5.csv", "w");
  FILE *archivo6=fopen("t6.csv", "w");
  FILE *archivo7=fopen("t7.csv", "w");
  FILE *archivo8=fopen("t8.csv", "w");
  FILE *archivo9=fopen("t9.csv", "w");
  if (archivo_tem == 0) {
    archivo= fopen("../../cloud/datos.csv", "r");
  } else if (archivo_tem == 1) {
    rename("t1.csv","1.csv");
    archivo= fopen("1.csv", "r");
  }else if (archivo_tem == 2) {
    rename("t2.csv","2.csv");
    archivo= fopen("2.csv", "r");
  }else if (archivo_tem == 3) {
    rename("t3.csv","3.csv");
    archivo= fopen("3.csv", "r");
  }else if (archivo_tem == 4) {
    rename("t4.csv","4.csv");
    archivo= fopen("4.csv", "r");
  }else if (archivo_tem == 5) {
    rename("t5.csv","5.csv");
    archivo= fopen("5.csv", "r");
  }else if (archivo_tem == 6) {
    rename("t6.csv","6.csv");
    archivo= fopen("6.csv", "r");
  }else if (archivo_tem == 7) {
    rename("t7.csv","7.csv");
    archivo= fopen("7.csv", "r");
  }else if (archivo_tem == 8) {
    rename("t8.csv","8.csv");
    archivo= fopen("8.csv", "r");
  }else if (archivo_tem == 9) {
    rename("t9.csv","9.csv");
    archivo= fopen("9.csv", "r");
  }
  else {
    std::cout << "Error" << '\n';
  }
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
      if (m>=0 and m<=datos_int){
      fprintf(archivo1, "%s",line );
      A1++;}
      else if (m>=datos_int and m<(datos_int*2)){
      fprintf(archivo2, "%s",line );
      A2++;}
      else if (m>=(datos_int*2) and m<(datos_int*3)){
      fprintf(archivo3, "%s",line );
      A3++;}
      else if (m>=(datos_int*3) and m<(datos_int*4)){
      fprintf(archivo4, "%s",line );
      A4++;}
      else if (m>=(datos_int*4) and m<(datos_int*5)){
      fprintf(archivo5, "%s",line );
      A5++;}
      else if (m>=(datos_int*5) and m<(datos_int*6)){
      fprintf(archivo6, "%s",line );
      A6++;}
      else if (m>=(datos_int*6) and m<(datos_int*7)){
      fprintf(archivo7, "%s",line );
      A7++;}
      else if (m>=(datos_int*7) and m<(datos_int*8)){
      fprintf(archivo8, "%s",line );
      A8++;}
      else if (m>=(datos_int*8) and m<(datos_int*9)){
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
    areglo[1]=m-A1;
    return 1;
  } else if (m<=(A2+A1)) {
    areglo[0]=n;
    areglo[1]=A2+A1;
    return 2;
  } else if (m<=(A3+A2+A1)) {
    areglo[0]=n;
    areglo[1]=m-(A3+A2+A1);
    return 3;
  } else if (m<=(A4+A3+A2+A1)) {
    areglo[0]=n;
    areglo[1]=m-(A4+A3+A2+A1)    ;
    return 4;
  } else if (m<=(A5+A4+A3+A2+A1)) {
    areglo[0]=n;
    areglo[1]=m-(A5+A4+A3+A2+A1);
    return 5;
  } else if (m<=(A6+A5+A4+A3+A2+A1)) {
    areglo[0]=n;
    areglo[1]=m-(A6+A5+A4+A3+A2+A1);
    return 6;
  } else if (m<=(A7+A6+A5+A4+A3+A2+A1)) {
  areglo[0]=n;
  areglo[1]=m-(A7+A6+A5+A4+A3+A2+A1);
  return 7;
} else if (m<=(A8+A7+A6+A5+A4+A3+A2+A1)) {
    areglo[0]=n;
    areglo[1]=m-(A8+A7+A6+A5+A4+A3+A2+A1);
    return 8;
  } else if (m<=(A9+A8+A7+A6+A5+A4+A3+A2+A1)) {
      areglo[0]=n;
      areglo[1]=m-(A9+A8+A7+A6+A5+A4+A3+A2+A1);
      return 9;
  }

}

int main(int argumentos, char *datos[]) {
    int archivo=0;
    long arreglo[2]={0,0};
    long  valor = 250000000;
    while(arreglo[0]<100){
      if (archivo==0 ){
        archivo= separ_archivo(arreglo,250000000,0);
      }else{
        archivo= separ_archivo(arreglo,arreglo[0]/9,archivo);
      }
        std::cout << arreglo[0]<<" "<<arreglo[1] <<" "<< archivo<< '\n';
    }
  	cout<<"calculo listo "<<endl;

  return 0;
}
