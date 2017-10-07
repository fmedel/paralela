#include <stdio.h>  //para el printf fopen
#include <string>
#include <stdlib.h>     /* atoi */
#include<iostream>
#include <sstream>

using namespace std;
int Separar(char* direcion_del_archivo) {
  char line[20];
  int lineas=0;
  int archivo2=0;
  string inicio ("fichero");
  string final_s (".txt");
  string archivo_nombre;
  std::stringstream sstm;
  sstm << inicio << archivo2<<final_s;
  archivo_nombre = sstm.str();
  FILE *archivo = fopen(direcion_del_archivo, "r");
  FILE *fp;
  fp = fopen ( archivo_nombre.c_str(), "w" );
  if (fp==NULL) {fputs ("File error",stderr); exit (1);}
  while(fgets(line, sizeof(line), archivo)){
      fprintf(fp,(char*)line);
      if(lineas==100000){
        archivo2++;
        sstm.str("");
        sstm << inicio << archivo2<<final_s;
        archivo_nombre = sstm.str();
        fclose (fp);
        fp = fopen (archivo_nombre.c_str(), "w" );
        if (fp==NULL) {fputs ("File error",stderr); exit (1);}
        lineas=0;
        continue;
      }
      lineas++;
  }
  fclose (fp);
  fclose(archivo);
  return archivo2;
}

void leer_archivo(char* direcion_temporal, long &suma, long &filas){
  int m=0;
  FILE *archivo = fopen(direcion_temporal, "r");
  char line[200];
  while (fgets(line, sizeof(line), archivo)){m++;
    suma+=atoi(line);
  }
  fclose(archivo);
  filas+=m;
}

int main(int argumentos, char *datos[]) {
  long suma=0;
  long filas=0;
  int archivos=0;
  int contador=0;
  char* direcion_del_archivo = datos[1];
  if (argumentos !=2 ) {
    printf("faltan argumentos\n");
    printf("tarea1 <ruta del log>\n");
  } else {
    archivos=Separar(direcion_del_archivo);
    while (contador<=archivos) {
      string inicio ("fichero");
      string final_s (".txt");
      string archivo_nombre;
      std::stringstream sstm;
      sstm << inicio << contador<<final_s;
      archivo_nombre = sstm.str();
      /*std::cout << archivo_nombre << '\n';*/
      leer_archivo((char*)archivo_nombre.c_str(),suma,filas);
      remove(archivo_nombre.c_str());
      sstm.str("");
       contador++;
    }
    if (contador!=0) {
      std::cout <<(double)suma/filas << '\n';
    }
  	cout<<"calculo listo "<<endl;
    }
  return 0;
}
