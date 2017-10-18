
#include <stdio.h>  //para el printf fopen
#include <string>
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <sstream>
#include "quicksort.cpp"
using namespace std;

int separ_archivo(long areglo[4], long datos_int, int archivo_tem){
  long m=0,n=0;
  FILE *archivo;
  if (archivo_tem == 0) {
    archivo= fopen("../../cloud_felipe/datos.csv", "r");
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
  FILE *archivo1=fopen("t1.csv", "w");
  FILE *archivo2=fopen("t2.csv", "w");
  FILE *archivo3=fopen("t3.csv", "w");
  FILE *archivo4=fopen("t4.csv", "w");
  FILE *archivo5=fopen("t5.csv", "w");
  FILE *archivo6=fopen("t6.csv", "w");
  FILE *archivo7=fopen("t7.csv", "w");
  FILE *archivo8=fopen("t8.csv", "w");
  FILE *archivo9=fopen("t9.csv", "w");
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
  long menorA1=areglo[3];
  long menorA2=areglo[3];
  long menorA3=areglo[3];
  long menorA4=areglo[3];
  long menorA5=areglo[3];
  long menorA6=areglo[3];
  long menorA7=areglo[3];
  long menorA8=areglo[3];
  long menorA9=areglo[3];
  long mayorA1=0,mayorA2=0,mayorA3=0,mayorA4=0,mayorA5=0;
  long mayorA6=0,mayorA7=0,mayorA8=0,mayorA9=0;
  char line[200];
  std::cout << "----------------" << '\n';
  std::cout << datos_int<< '\n';
  std::cout << areglo[2] << '\n';
  std::cout << datos_int+areglo[2] << '\n';
  std::cout << (datos_int*2)+areglo[2] << '\n';
  std::cout << (datos_int*3)+areglo[2] << '\n';
  std::cout << (datos_int*4)+areglo[2] << '\n';
  std::cout << (datos_int*5)+areglo[2] << '\n';
  std::cout << (datos_int*6)+areglo[2] << '\n';
  std::cout << (datos_int*7)+areglo[2] << '\n';
  std::cout << (datos_int*8)+areglo[2] << '\n';
  std::cout << areglo[3] << '\n';
  std::cout << "-----------------" << '\n';
  while (fgets(line, sizeof(line), archivo)){
    n++;
    m=atoi(line);
      if (m>=0+areglo[2] and m<=datos_int+areglo[2]){
        fprintf(archivo1, "%s",line );
        A1++;
        if (menorA1>m) {
          menorA1=m;
        }
        if (mayorA1<m) {
          mayorA1=m;
        }
      }
      else if (m>=datos_int+areglo[2] and m<((datos_int*2)+areglo[2])){
        fprintf(archivo2, "%s",line );
        A2++;
        if (menorA2>m) {
          menorA2=m;
        }
        if (mayorA2<m) {
          mayorA2=m;
        }
      }
      else if (m>=((datos_int*2)+areglo[2]) and m<((datos_int*3)+areglo[2])){
        fprintf(archivo3, "%s",line );
        A3++;
        if (menorA3>m) {
          menorA3=m;
        }
        if (mayorA3<m) {
          mayorA3=m;
        }
      }
      else if (m>=((datos_int*3)+areglo[2]) and m<((datos_int*4)+areglo[2])){
        fprintf(archivo4, "%s",line );
        A4++;
        if (menorA4>m) {
          menorA4=m;
        }
        if (mayorA4<m) {
          mayorA4=m;
        }
      }
      else if (m>=((datos_int*4)+areglo[2]) and m<((datos_int*5)+areglo[2])){
        fprintf(archivo5, "%s",line );
        A5++;
        if (menorA5>m) {
          menorA5=m;
        }
        if (mayorA5<m) {
          mayorA5=m;
        }
      }
      else if (m>=((datos_int*5)+areglo[2]) and m<((datos_int*6)+areglo[2])){
        fprintf(archivo6, "%s",line );
        A6++;
        if (menorA6>m) {
          menorA6=m;
        }
        if (mayorA6<m) {
          mayorA6=m;
        }
      }
      else if (m>=((datos_int*6)+areglo[2]) and m<((datos_int*7)+areglo[2])){
        fprintf(archivo7, "%s",line );
        A7++;
        if (menorA7>m) {
          menorA7=m;
        }
        if (mayorA7<m) {
          mayorA7=m;
        }
      }
      else if (m>=((datos_int*7)+areglo[2]) and m<((datos_int*8)+areglo[2])){
        fprintf(archivo8, "%s",line );
        A8++;
        if (menorA8>m) {
          menorA8=m;
        }
        if (mayorA8<m) {
          mayorA8=m;
        }
      }
      else if (m>=((datos_int*8)+areglo[2]) and m<=areglo[3]){
        fprintf(archivo9, "%s",line );
        A9++;
        if (menorA9>m) {
          menorA9=m;
        }
        if (mayorA9<m) {
          mayorA9=m;
        }
      }
      else {
         std::cout << line << '\n';
         A10++;
         return 99;
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
  std::cout << "total "<< n ;
  std::cout << ";"<< A1 ;
  std::cout << ";"<< A2 ;
  std::cout << ";"<< A3 ;
  std::cout << ";"<< A4 ;
  std::cout << ";"<< A5 ;
  std::cout << ";"<< A6 ;
  std::cout << ";"<< A7 ;
  std::cout << ";"<< A8 ;
  std::cout << ";"<< A9 ;
  std::cout << ";"<< A10 ;
  std::cout << ";" << A1+A2+A3+A4+A5+A6+A7+A8+A9+A10 <<'\n';
  if (archivo_tem==0) {
    m=n/2;
  } else {
    m=areglo[1];
  }
  if (m<A1) {
    areglo[0]=A1;
    areglo[1]=m;
    areglo[2]=menorA1;
    areglo[3]=mayorA1;
    return 1;
  } else if (m<=(A2+A1)) {
    areglo[0]=A2;
    areglo[1]=m-A1;
    areglo[2]=menorA2;
    areglo[3]=mayorA2;
    return 2;
  } else if (m<=(A3+A2+A1)) {
    areglo[0]=A3;
    areglo[1]=m-(A2+A1);
    areglo[2]=menorA3;
    areglo[3]=mayorA3;
    return 3;
  } else if (m<=(A4+A3+A2+A1)) {
    areglo[0]=A4;
    areglo[1]=m-(A3+A2+A1);
    areglo[2]=menorA4;
    areglo[3]=mayorA4;
    return 4;
  } else if (m<=(A5+A4+A3+A2+A1)) {
    areglo[0]=A5;
    areglo[1]=m-(A4+A3+A2+A1);
    areglo[2]=menorA5;
    areglo[3]=mayorA5;
    return 5;
  } else if (m<=(A6+A5+A4+A3+A2+A1)) {
    areglo[0]=A6;
    areglo[1]=m-(A5+A4+A3+A2+A1);
    areglo[2]=menorA6;
    areglo[3]=mayorA6;
    return 6;
  } else if (m<=(A7+A6+A5+A4+A3+A2+A1)) {
  areglo[0]=A7;
  areglo[1]=m-(A6+A5+A4+A3+A2+A1);
  areglo[2]=menorA7;
  areglo[3]=mayorA7;
  return 7;
} else if (m<=(A8+A7+A6+A5+A4+A3+A2+A1)) {
    areglo[0]=A8;
    areglo[1]=m-(A7+A6+A5+A4+A3+A2+A1);
    areglo[2]=menorA8;
    areglo[3]=mayorA8;
    return 8;
  } else if (m<=(A9+A8+A7+A6+A5+A4+A3+A2+A1)) {
      areglo[0]=A9;
      areglo[1]=m-(A8+A7+A6+A5+A4+A3+A2+A1);
      areglo[2]=menorA9;
      areglo[3]=mayorA9;
      return 9;
  }
}

int media(int archivo_tem,int datos){
  long arreglo[datos-1];
  int n=0;
  FILE *archivo;
  if (archivo_tem == 1) {
    archivo= fopen("t1.csv", "r");
  }else if (archivo_tem == 2) {
    archivo= fopen("t2.csv", "r");
  }else if (archivo_tem == 3) {
    archivo= fopen("t3.csv", "r");
  }else if (archivo_tem == 4) {
    archivo= fopen("t4.csv", "r");
  }else if (archivo_tem == 5) {
    archivo= fopen("t5.csv", "r");
  }else if (archivo_tem == 6) {
    archivo= fopen("t6.csv", "r");
  }else if (archivo_tem == 7) {
    archivo= fopen("t7.csv", "r");
  }else if (archivo_tem == 8) {
    archivo= fopen("t8.csv", "r");
  }else if (archivo_tem == 9) {
    archivo= fopen("t9.csv", "r");
  }
  else {
    std::cout << "Error" << '\n';
  }
  char line[200];
  while (fgets(line, sizeof(line), archivo)){
    arreglo[n]=atoi(line);
    n++;
  }
    fclose(archivo);
    quicksort(arreglo, 0, datos);
    std::cout << arreglo[(datos/2)-1] << '\n';
}
int main(int argumentos, char *datos[]) {
    int archivo=0;
    long  valor = 250000000;
    long arreglo[4]={9999999999,9999999999,0,(valor*9)};
    clock_t start_time;
    clock_t final_time;
    double total_time;
    while(arreglo[0]>100){
      start_time = clock();
      if (archivo==0 ){
        archivo= separ_archivo(arreglo,valor,0);
      }else if (archivo!=99 and archivo!=0){
        archivo= separ_archivo(arreglo,(arreglo[3]-arreglo[2])/9,archivo);
      }else{
        return 0;
      }
      final_time = clock();
      total_time = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;
      std::cout <<archivo<<"Tiempo de ejecución :"<<total_time<<" segundos \n" << '\n';
    }
    media(archivo,arreglo[0]);
  	cout<<"calculo listo "<<endl;

  return 0;
}
