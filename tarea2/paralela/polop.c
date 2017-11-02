#include "pngpixel.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, const char **argv) {
  char *nombre="Monica.png";
  char fila[3];
  char columna[3];
  int seccion_fila;
  int seccion_columna;
  char nombre_2[10];
  long  rango_columna , rango_fila;
  for (int i = 1; i < 33; i++) {
    seccion_fila=i;
    rango_fila=(seccion_fila-1)*800;
    for (int j = 1; j < 33; j++) {
      seccion_columna=j;
      rango_columna=(seccion_columna-1)*800;
      sprintf(nombre_2, "datos/%d-%d", seccion_fila, seccion_columna);
      funcion_main(4,rango_fila,rango_columna,nombre, seccion_fila,seccion_columna,nombre_2);
    }
  }
  printf("termino\n");
  return 0;
}
