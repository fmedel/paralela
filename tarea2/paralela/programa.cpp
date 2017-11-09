#include <iostream>
#include <fstream>
#include <string.h>
#include <pqxx/pqxx>
#include "algoritmo.cpp"
using namespace std;
using namespace pqxx;
//##########################################Definir variable#################################################
#define MAX_FILA_DATOS 800
#define MAX_COLUMNA_DATOS 800
#define MAX_SECCIONES_FILA 3 //128
#define MAX_SECCIONES_COLUMNA 1 //128
#define MAX_POSIBLE_COMBINATORIA 0
#define MAX_CARRACTERES 128
#define BLANCO "255 255 255"
#define BLANCO_VALOR 0
#define NEGRO "0 0 0"
#define NEGRO_VALOR 1
#define ARCHIVO_TEMPORAL "test.csv"
#define PRIMERA_LINEA_1_1 0
#define DATOS 200
//################################################### CONEXION ################################################
   string dbname= "felipe";
   string user= "felipe";
   string password= "polop12";
   string hostaddr= "127.0.0.1";
   string port= "5432";
   string conexion= "dbname ="+dbname+" user = "+user+" password = "+password+" hostaddr = "+hostaddr+" port = "+port;
//#############################################################################################################

int buscar_comienzo(char *nombre){
  printf("buscar_comienzo\n");
  char cadena[MAX_CARRACTERES];
  int valor = -5;
  ifstream fe(nombre);
  while(!fe.eof()) {
    valor++;
     fe.getline(cadena, MAX_CARRACTERES);
     if (strcmp(BLANCO,cadena)==0) {
       printf("salir buscar_comienzo\n");
       return valor/DATOS;
     }
  }
  fe.close();
  printf("salir buscar_comienzo\n");
}

int ver_cuanto_abierto(int vector_blancos_fila[MAX_FILA_DATOS],int vector_blancos_columna[MAX_COLUMNA_DATOS]){
  printf("entro en ver cuanto abierto\n");
  for (int i = 0; i < MAX_FILA_DATOS; i++) {
    if ((vector_blancos_fila[i]==NULL) or (vector_blancos_columna[i]==NULL)) {
      printf("salio en ver cuanto abierto\n");
      return i;
    }
  }
  printf("salio en ver cuanto abierto\n");
}

void leer(char *nombre, int seccion_fila){
  printf("entro leer\n");
   char cadena[MAX_CARRACTERES];
   ifstream fe(nombre);
   int valor=0;
   while(!fe.eof()) {
     valor++;
      fe.getline(cadena, MAX_CARRACTERES);
    }
   fe.close();
   printf("salir leer\n");
}

void cargar_datos(int datos[DATOS][DATOS], char *nombre){
  printf("enrtro en cargar datos\n");
  char cadena[MAX_CARRACTERES];
  int fila=0;
  int columna=0;
  long contador=0;
  ifstream fe(nombre);
  std::ofstream ofs (ARCHIVO_TEMPORAL, std::ofstream::out);
  while(!fe.eof()) {
    contador++;
    fe.getline(cadena, MAX_CARRACTERES);
    if(contador<5){continue;}
    if (strcmp(BLANCO,cadena)==0) {
        datos[fila][columna]=BLANCO_VALOR;
        ofs << BLANCO_VALOR;
      }
      else{
         if (strcmp(NEGRO,cadena)==0) {
           datos[fila][columna]=NEGRO_VALOR;
           ofs << NEGRO_VALOR;
         }
         else{
           if (contador==40005) {
             break;
           }else{
             printf("Error %s (%d,%d)\n",cadena,fila,columna);
           }

         }
      }
    columna++;
     if (columna==DATOS) {
       ofs <<'\n';
       columna=0;
       fila++;
       if (fila==DATOS+1) {break;}
     }
  }
  ofs.close();
  fe.close();
  printf("Salir cargar_datos\n");
}

void mostrar_datos(int datos[DATOS][DATOS]){
  printf("entro en mostrar_datos\n");
  int fila=0;
  int columna=0;
  while (fila<DATOS) {
    printf("%d",datos[fila][columna]);
    columna++;
    if (columna==DATOS) {
      printf("\n");
      columna=0;
      fila++;
    }
  }
  printf("salio de mostrar_datos\n");
}

int buscar_abierto(int datos[DATOS][DATOS], int vector_blancos_fila[MAX_FILA_DATOS],int vector_blancos_columna[MAX_COLUMNA_DATOS], int seccion_fila, int seccion_columna){
  printf("entro en buscar abierto\n");
  int contador=0;
  if (seccion_fila<3) {
    printf("Error en buscar_abierto\n");
  } else {
    if (seccion_columna==MAX_SECCIONES_COLUMNA) { //temporal revisar
      for (int c = 0; c < DATOS; c++) {
        if (datos[DATOS-1][c]==1) {
                vector_blancos_fila[contador]=DATOS-1;
                vector_blancos_columna[contador]=c;
                //printf("columna-> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
                contador++;
        }else{continue;}
      }
      for (int f = 0; f <DATOS; f++) {
        if (datos[f][DATOS-1]==1) {
                vector_blancos_fila[contador]=f;
                vector_blancos_columna[contador]=DATOS-1;
                //printf("fila-> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
                contador++;
        }else{continue;}
      }
    }
  }
  return contador;
  printf("salio en buscar abierto\n");
}

void imprimir_pares(int vector_blancos_fila[MAX_FILA_DATOS],int vector_blancos_columna[MAX_COLUMNA_DATOS], int cuantos){
  printf("entro en imprimir pares\n");
  for (int i = 0; i < cuantos; i++) {
    for (int z = 0; z < cuantos; z++) {
      printf("(%d,%d)\n",vector_blancos_fila[i],vector_blancos_columna[z]);
    }
  }
  printf("entro en imprimir pares\n");
}

void pasar_a_bd_inicio_fin(int fila_inicio , int fila_fin ,int columna_inicio , int columna_fin ,int seccion_fila, int seccion_columna, char* camino){
  printf("entro en pasar_a_bd_inicio_fin\n");
  string query;
  connection conn(conexion);
  if (conn.is_open()) {
      cout << "bd abierta con exito: " << conn.dbname() << endl;
  }
  else{
      cout << "Error al abrir bd" << endl;
  }
  query = "INSERT INTO camino (seccion_fila,seccion_columna,inicio_fila,fin_fila,inicio_columna,fin_columna,camino)  VALUES ("+ to_string(seccion_fila) + ","+to_string(seccion_columna)+","+to_string(fila_inicio)+","+to_string(fila_fin)+","+to_string(columna_inicio)+","+to_string(columna_fin)+",'"+camino+"')";
  std::cout << query << '\n';
  work W(conn);
  W.exec( query );
  W.commit();
  cout << "ingreso correcto de dato" << endl;
  conn.disconnect ();
  printf("salio de pasar_a_bd_inicio_fin\n");
}

void imprimir_generar_inicio_fin(int vector_blancos_fila[MAX_FILA_DATOS],int vector_blancos_columna[MAX_COLUMNA_DATOS], int cuantos){
  printf("entro en imprimir_generar_inicio_fin\n");
  for (int i = 0; i < cuantos; i++) {
    for (int z = 0; z < cuantos; z++) {
      if(i==z){continue;}
      else{
        printf("(%d,%d)<-->(%d,%d)\n",vector_blancos_fila[i],vector_blancos_columna[i],vector_blancos_fila[z],vector_blancos_columna[z]);
      }
    }
  }
  printf("salio en imprimir_generar_inicio_fin\n");
}

void generar_camino(int inicio_fila,int inicio_columna,int fin_fila,int fin_columna, int datos[DATOS][DATOS],int seccion_fila,int seccion_columna){
  //printf("entro en generar_camino\n");
  char resultado_camino[8000];
  int valor_ba;
  //valor_ba=funcion_main( datos, inicio_fila,inicio_columna,fin_fila,fin_columna);
  valor_ba=funcion_main( datos, inicio_fila,inicio_columna,fin_fila,fin_columna,resultado_camino);
  if(valor_ba==1){
    pasar_a_bd_inicio_fin(inicio_fila,fin_fila,inicio_columna,fin_columna,seccion_fila, seccion_columna, resultado_camino);
    //printf("%s\n",resultado_camino);
  }
  //printf("salio en generar_camino\n");

}

void buscar_camino_pares(int vector_blancos_fila[MAX_FILA_DATOS],int vector_blancos_columna[MAX_COLUMNA_DATOS], int cuantos , int datos[DATOS][DATOS],int seccion_fila, int seccion_columna){
  printf("entro en buscar_camino_pares\n");
  for (int i = 0; i < cuantos; i++) {
    for (int z = 0; z < cuantos; z++) {
      if(i==z){continue;}
      else{
        generar_camino(vector_blancos_fila[i],vector_blancos_columna[i],vector_blancos_fila[z],vector_blancos_columna[z], datos ,seccion_fila, seccion_columna);
      }
    }
  }
  printf("salio en buscar_camino_pares\n");
}

void copiar_carpeta(){
  printf("entro en copiar_carpeta\n" );
  system("mkdir resultado");
  system("cp -r datos/* resultado/");
  printf("salio de copiar_carpeta\n");
}

int main(int argc, char const *argv[]) {
  int seccion_fila;
  int datos[DATOS][DATOS];
  int seccion_columna;
  char nombre_2[10];
  int vector_blancos_fila[MAX_FILA_DATOS];
  int vector_blancos_columna[MAX_COLUMNA_DATOS];
  int contador=0;
  for (int i = MAX_SECCIONES_FILA; i < (MAX_SECCIONES_FILA+1); i++) {
    seccion_fila=i;
    for (int j = MAX_SECCIONES_COLUMNA; j < (MAX_SECCIONES_COLUMNA+1); j++) {
      seccion_columna=j;
      sprintf(nombre_2, "datos/%d-%d", seccion_fila, seccion_columna);
      //copiar_carpeta();
      cargar_datos(datos,nombre_2);
      leer(nombre_2,seccion_fila);
      //cout<<buscar_comienzo(nombre_2)<<"\n";
      //mostrar_datos(datos);
      int cuanto_datos= buscar_abierto(datos,vector_blancos_fila,vector_blancos_columna,seccion_fila,seccion_columna);
      //printf("abierto -> %d\n",ver_cuanto_abierto(vector_blancos_fila,vector_blancos_columna));
      //imprimir_pares(vector_blancos_fila,vector_blancos_columna,ver_cuanto_abierto(vector_blancos_fila,vector_blancos_columna));
      //imprimir_generar_inicio_fin(vector_blancos_fila,vector_blancos_columna,ver_cuanto_abierto(vector_blancos_fila,vector_blancos_columna));
      //generar_camino(199,113,199,146,datos);
      //printf("%d\n",cuanto_datos);
      buscar_camino_pares(vector_blancos_fila,vector_blancos_columna,cuanto_datos,datos,seccion_fila, seccion_columna);
    }
  }
  return 0;
}
