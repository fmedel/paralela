#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <time.h>
using namespace std;
//##########################################Definir variable#################################################
#define MAX_FILA_DATOS 10240
#define MAX_COLUMNA_DATOS 10240
#define MAX_SECCIONES_FILA 1
#define MAX_SECCIONES_COLUMNA 1
#define MAX_CARRACTERES 128
#define BLANCO "255 255 255"
#define BLANCO_VALOR 0
#define NEGRO "0 0 0"
#define NEGRO_VALOR 1
#define DATOS 10240

void cargar_datos(int datos[DATOS][DATOS], char *nombre,int seccion_fila, int seccion_columna);

int main(int argc, char const *argv[]) {
  printf("1\n");
  clock_t start, end;
  printf("2\n");
  start = clock();
  printf("3\n");
  int seccion_fila;
  printf("4\n");
  int datos[DATOS][DATOS];
  printf("5\n");
  int seccion_columna;
  printf("6\n");
  char nombre_2[10];
  printf("7\n");
  int vector_blancos_fila[MAX_FILA_DATOS];
  printf("8\n");
  int vector_blancos_columna[MAX_COLUMNA_DATOS];
  printf("9\n");
  seccion_fila=3;
  printf("10\n");
  int x,y;
  printf("11\n");
  cargar_datos(datos,nombre_2,x,y);
  printf("12\n");
  end = clock();
  printf("termnio #_#\n");
  return 0;
}
//#####################################################funciones######################################
void cargar_datos(int datos[DATOS][DATOS], char *nombre,int seccion_fila, int seccion_columna){
  char cadena[MAX_CARRACTERES];
  long fila=0;
  long columna=0;
  long contador=0;
  ifstream fe(nombre);
  while(!fe.eof()) {
    contador++;
    fe.getline(cadena, MAX_CARRACTERES);
    if(columna==10239){
      columna=0;
      fila++;
    }
    if (strcmp(BLANCO,cadena)==0) {
        datos[fila][columna]=BLANCO_VALOR;
      }
      else{
         if (strcmp(NEGRO,cadena)==0) {
           datos[fila][columna]=NEGRO_VALOR;
         }
         else{
           if (contador==104857601) {
             break;
           }else{
             printf("Error %s (%ld,%ld)\n",cadena,fila,columna);
           }

         }
      }
    columna++;
  }
  fe.close();
}
