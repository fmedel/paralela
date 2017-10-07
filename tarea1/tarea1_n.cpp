#include <stdio.h>
#include <string>
#include <stdlib.h>
#include<iostream>

using namespace std;

void LeerA(char* ArchivoTemporl, long &suma, long &cuantoNumerosSon){
  int m=0;
  FILE *archivo = fopen(ArchivoTemporl, "r");
  if (archivo!=NULL) {
  char Lineas[200];
  while (fgets(Lineas, sizeof(Lineas), archivo)){m++;
    suma+=atoi(Lineas);
  }
  fclose(archivo);
  cuantoNumerosSon+=m;
}
}
int archivo_separar(char* ArchivoDirecion) {
  char Lineas[20];
  int cantidad_linaes=0;
  int archivo_I=0;
  FILE *archivo = fopen(ArchivoDirecion, "r");
  FILE *fp;
  fp = fopen ("archivo0.txt", "w" );
  if (fp==NULL) {fputs ("File error",stderr); exit (1);}
  if (archivo==NULL) {fputs ("File error",stderr); exit (1);}

  while(fgets(Lineas, sizeof(Lineas), archivo)){

      fprintf(fp,(char*)Lineas);
      if(cantidad_linaes==2000000000){/**/

        archivo_I++;
        fclose (fp);
        switch (archivo_I) {
          case 1:
            fp = fopen ("archivo1.txt", "w" );
            if (fp==NULL) {fputs ("File error",stderr); exit (1);}
          break;
          case 2:
            fp = fopen ("archivo2.txt", "w" );
            if (fp==NULL) {fputs ("File error",stderr); exit (1);}
          break;
          case 3:
            fp = fopen ("archivo3.txt", "w" );
            if (fp==NULL) {fputs ("File error",stderr); exit (1);}
          break;
          case 4:
            fp = fopen ("archivo4.txt", "w" );
            if (fp==NULL) {fputs ("File error",stderr); exit (1);}
          break;
        }
        if (archivo_I!=4) {
          cantidad_linaes=0;
        }
        continue;
      }
      cantidad_linaes++;
  }
  fclose (fp);
  fclose(archivo);
  return archivo_I;
}



int main(int argumentos, char *datos[]) {
  long suma=0;
  long cuantoNumerosSon=0;
  int archivos=0;
  int contador=0;
  char* ArchivoDirecion = datos[1];
  if (argumentos !=2 ) {
    printf("Error\n");
    printf("tarea1 <ruta del log>\n");
  } else {
    archivos=archivo_separar(ArchivoDirecion);
    while (contador<=archivos) {
      switch (contador) {
        case 0:
        LeerA("archivo0.txt",suma,cuantoNumerosSon);
        remove("archivo0.txt");
        contador++;
        break;
        case 1:
          LeerA("archivo1.txt",suma,cuantoNumerosSon);
          remove("archivo1.txt");
          contador++;
        break;
        case 2:
          LeerA("archivo2.txt",suma,cuantoNumerosSon);
          remove("archivo2.txt");
          contador++;
        break;
        case 3:
        LeerA("archivo3.txt",suma,cuantoNumerosSon);
        remove("archivo3.txt");
        contador++;
        break;
        case 4:
          LeerA("archivo4.txt",suma,cuantoNumerosSon);
          remove("archivo4.txt");
          contador++;
        break;
    }
  }
    if (contador!=0) {
      cout <<(double)suma/cuantoNumerosSon << '\n';
    }
  	cout<<"fin del programa"<<endl;
    }
  return 0;
}
