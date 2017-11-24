#include <iostream>
#include <fstream>
#include <string.h>
#include <pqxx/pqxx>
#include "algoritmo.cpp"
#include <sstream>
#include <omp.h>
#include <time.h>
using namespace std;
using namespace pqxx;
//##########################################Definir variable#################################################
#define MAX_FILA_DATOS 800
#define MAX_COLUMNA_DATOS 800
#define MAX_SECCIONES_FILA 5 //128
#define MAX_SECCIONES_COLUMNA 126 //126
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
//###########################################cabesera##################################################################

void pasar_a_bd_laberinto(int seccion_fila, int seccion_columna,int fila, int columna,bool valor);
int buscar_comienzo(char *nombre);
int ver_cuanto_abierto(int vector_blancos_fila[MAX_FILA_DATOS],int vector_blancos_columna[MAX_COLUMNA_DATOS]);
void leer(char *nombre, int seccion_fila);
void cargar_datos(int datos[DATOS][DATOS], char *nombre,int seccion_fila, int seccion_columna);
void mostrar_datos(int datos[DATOS][DATOS]);
int buscar_abierto(int datos[DATOS][DATOS], int vector_blancos_fila[MAX_FILA_DATOS],int vector_blancos_columna[MAX_COLUMNA_DATOS], int seccion_fila, int seccion_columna);
void imprimir_pares(int vector_blancos_fila[MAX_FILA_DATOS],int vector_blancos_columna[MAX_COLUMNA_DATOS], int cuantos);
void pasar_a_bd_inicio_fin(int fila_inicio , int fila_fin ,int columna_inicio , int columna_fin ,int seccion_fila, int seccion_columna, char* camino);
void imprimir_generar_inicio_fin(int vector_blancos_fila[MAX_FILA_DATOS],int vector_blancos_columna[MAX_COLUMNA_DATOS], int cuantos);
void generar_camino(int inicio_fila,int inicio_columna,int fin_fila,int fin_columna, int datos[DATOS][DATOS],int seccion_fila,int seccion_columna);
void buscar_camino_pares(int vector_blancos_fila[MAX_FILA_DATOS],int vector_blancos_columna[MAX_COLUMNA_DATOS], int cuantos , int datos[DATOS][DATOS],int seccion_fila, int seccion_columna);
void copiar_carpeta();
void pintar_camino(int seccion_fila,int seccion_columna, string camino);
string buscar_camino_bd(int seccion_fila,int seccion_columna,int inicio_fila,int fin_fila,int inicio_columna,int fin_columna);
void imprimir_invertido(char* nombre_2,int datos[DATOS][DATOS]);

// para hacer solo diagonal
bool es_diagonal(int seccion_fila,int seccion_columna);
void buscar_camino_pares_diagonal( int datos[DATOS][DATOS],int seccion_fila, int seccion_columna);
//#########################################main##############################/

int main(int argc, char const *argv[]) {

    clock_t start, end;
    start = clock();
  int seccion_fila;
  int datos[DATOS][DATOS];
  int seccion_columna;
  char nombre_2[10];
  int vector_blancos_fila[MAX_FILA_DATOS];
  int vector_blancos_columna[MAX_COLUMNA_DATOS];
  //int contador=0;
    /*for (int i = 3; i < (MAX_SECCIONES_FILA+1); i++) {
      seccion_fila=i;
      for (int j = 1; j < (MAX_SECCIONES_COLUMNA+1); j++) {
        seccion_columna=j;
        sprintf(nombre_2, "datos/%d-%d", seccion_fila, seccion_columna);
        //cargar_datos(datos,nombre_2,seccion_fila,seccion_columna);
        //leer(nombre_2); //puede servir pa algo
        //cout<<buscar_comienzo(nombre_2)<<"\n";
        //mostrar_datos(datos);
        //int cuanto_datos= buscar_abierto(datos,vector_blancos_fila,vector_blancos_columna,seccion_fila,seccion_columna);
        //printf("abierto -> %d\n",ver_cuanto_abierto(vector_blancos_fila,vector_blancos_columna));
        //imprimir_pares(vector_blancos_fila,vector_blancos_columna,ver_cuanto_abierto(vector_blancos_fila,vector_blancos_columna));
        //imprimir_generar_inicio_fin(vector_blancos_fila,vector_blancos_columna,cuanto_datos);
        //generar_camino(199,113,199,146,datos);
        //printf("%d\n",cuanto_datos);
        //buscar_camino_pares(vector_blancos_fila,vector_blancos_columna,cuanto_datos,datos,seccion_fila, seccion_columna);
        //pasar_a_bd_inicio_fin(1,1,1,1,1,2,"dd");
        //string camino_s = buscar_camino_bd(MAX_SECCIONES_FILA,MAX_SECCIONES_COLUMNA,181,166,0,0);
        //pintar_camino(seccion_fila,seccion_columna,camino_s);

        //para diagonal
        if(es_diagonal(i,j)){
          cargar_datos(datos,nombre_2,i,j);
          //mostrar_datos(datos);
          buscar_camino_pares_diagonal(datos,i,j);
          printf("Es diagonal %d,%d\n",i,j);
        }

      }
    }*/
  seccion_fila=3;
  int x,y;
  #pragma omp parallel for private(y,nombre_2,datos)
  for(x=3; x < 129; x++)
  {
          for(y=1; y < 127; y++)
          {
            if(es_diagonal(x,y)){
              sprintf(nombre_2, "datos/%d-%d", x, y);
              cargar_datos(datos,nombre_2,x,y);
              //mostrar_datos(datos);
              buscar_camino_pares_diagonal(datos,x,y);
              printf("Es diagonal %d,%d\n",x,y);
            }
          }
  }

  end = clock();
  //cout<< (end - start)<<"\n";
  printf("termnio #_#\n");
	//copiar_carpeta();
  return 0;
}
//#####################################################funciones######################################

//select * from camino where seccion_fila = 3 and seccion_columna = 1 and inicio_fila= 134 and fin_fila = 131 and inicio_columna =199 and fin_columna = 199

bool es_diagonal(int seccion_fila,int seccion_columna){
  if (seccion_columna == 1) {
    if (seccion_fila == 128) {
      return true;
    }else{
      return true;
    }
  }
  else{
      if (seccion_fila == 128) {
        if (seccion_columna == 126) {
          return true;
        }else{
          return true;
        }
      }
      else {
        return false;
      }
    }
}
void buscar_camino_pares_diagonal( int datos[DATOS][DATOS],int seccion_fila, int seccion_columna){
  printf("entro en buscar_camino_pares\n");
  if (seccion_columna == 1) {
    if (seccion_fila == 128) {
      for (int i = 0; i < 100; i++) {
        for (int z = 0; z < 100; z++) {
          generar_camino(0,i,z,199, datos ,seccion_fila, seccion_columna);
        }
      }
    }else{
      if (seccion_fila==3) {
        for (int z = 0; z < 100; z++) {
          //generar_camino(0,i,199,z, datos ,seccion_fila, seccion_columna);
          generar_camino(0,1,z,199, datos ,seccion_fila, seccion_columna);
        }
      }
      else{
        for (int i = 0; i < 100; i++) {
          for (int z = 0; z < 100; z++) {
            generar_camino(0,i,199,z, datos ,seccion_fila, seccion_columna);
          }
        }
      }
    }
  }
  else{
      if (seccion_fila == 128) {
        if (seccion_columna==126) {
          for (int i = 0; i < 100; i++) {
            for (int z = 0; z < 100; z++) {
              generar_camino(i,0,199,199, datos ,seccion_fila, seccion_columna);
            }
          }
        } else {
          if (seccion_columna!=1) {
            for (int i = 0; i < 100; i++) {
              for (int z = 0; z < 100; z++) {
                generar_camino(i,0,z,199, datos ,seccion_fila, seccion_columna);
              }
            }
          }
        }
      }
    }
  printf("salio en buscar_camino_pares\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string buscar_camino_bd(int seccion_fila,int seccion_columna,int inicio_fila,int fin_fila,int inicio_columna,int fin_columna) {
  printf("entro en buscar_camino_bd\n");
  string query;
  connection conn(conexion);
  if (conn.is_open()) {
      cout << "bd abierta con exito: " << conn.dbname() << endl;
  }
  else{
      cout << "Error al abrir bd" << endl;
  }
  query = "select camino from camino where seccion_fila = "+to_string(seccion_fila)+ " and seccion_columna = "+ to_string(seccion_columna)+ " and inicio_fila = "+to_string(inicio_fila)+ " and fin_fila = "+ to_string(fin_fila)+ " and inicio_columna = "+to_string(inicio_columna)+ " and fin_columna = "+to_string(fin_columna)+" ;";
  std::cout << query << '\n';
  work W(conn);
  //W.exec( query );
  pqxx::result r = W.exec(query);
  W.commit();
  cout << "ingreso correcto de dato" << endl;
  conn.disconnect ();
  //std::cout <<"ee"<<cc << std::endl;
  printf("salio de buscar_camino_bd\n");
  if (r[0]["camino"].c_str()==NULL) {
    return "Error";
  }else{
    return r[0]["camino"].c_str();
  }

}

void imprimir_invertido(char* nombre_2,int datos[DATOS][DATOS]){
  FILE *fp;
  fp = fopen ( nombre_2, "a" );/* imprimir  los pixcel */
  fprintf(fp, "P3\n200\n200\n255\n");
  for (int i = 0; i < DATOS; i++) {
    for (int z = 0; z < DATOS; z++) {
      if (  datos[i][z] == 2) {
          fprintf(fp, "255 0 0\n");
      } else if ( datos[i][z] == 1) {
        fprintf(fp, "255 255 255\n");
      } else {
        fprintf(fp, "0 0 0\n");
      }
    }
  }
  fclose(fp);
 }

void pintar_camino(int seccion_fila,int seccion_columna, string camino){

  printf("entro en pintar_camino\n");
  if (strcmp(camino.c_str(),"Error")!=0) {
    int datos[DATOS][DATOS];
    char nombre_2[10];
    sprintf(nombre_2, "resultado/%d-%d", seccion_fila, seccion_columna);
    cargar_datos(datos,nombre_2,seccion_fila,seccion_columna);
    remove(nombre_2);
    string sentencia= camino;
    std::stringstream sstm;
    string temporal;
    int fila;
    int columna;
    int largo;
    char separador = '-'; //aqui vas a introducir el separador -en mi caso es un espacio-
    size_t tam= camino.length();
    camino.erase(tam-1); //con la funcion erase(), borramos los caracteres
    //desde la posicion que le damos como argumento hasta el final
    //ahora la palabra tendra 1 caracter menos
    //std::cout << camino << '\n';
    for(size_t p=0, q=0; p!=sentencia.npos; p=q){
      std::stringstream sstm;
      sstm << sentencia.substr(p+(p!=0),(q=sentencia.find(separador, p+1))-p-(p!=0))<<"\n";
        fila=atoi(sstm.str().substr(1,sstm.str().find(",")-1).c_str());
        largo= sstm.str().find(")") - sstm.str().find(",");
        columna=atoi(sstm.str().substr((sstm.str().find(",")+1),largo-1).c_str());
          datos[fila][columna]=2;
    }
    //mostrar_datos(datos);
    imprimir_invertido(nombre_2,datos);
    printf("salio en pintar_camino\n");
  }
  else{printf("Error pintar_camino \n");}
}

void pasar_a_bd_laberinto(int seccion_fila, int seccion_columna,int fila, int columna,bool valor){
  //printf("entro en pasar_a_bd_laberinto\n");
  string query;
  connection conn(conexion);
  if (conn.is_open()) {
    //cout << "bd abierta con exito: " << conn.dbname() << endl;
  }
  else{
      cout << "Error al abrir bd" << endl;
  }
  query = "INSERT INTO laberinto (seccion_fila,seccion_columna,fila,columna,valor)  VALUES ("+to_string(seccion_fila)+","+to_string(seccion_columna)+","+to_string(fila)+","+to_string(columna)+","+to_string(valor)+")";
  //std::cout << query << '\n';
  work W(conn);
  W.exec( query );
  W.commit();
  //cout << "ingreso correcto de dato" << endl;
  conn.disconnect ();
  //printf("salio de pasar_a_bd_laberinto\n");
}

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

void leer(char *nombre){
  printf("entro leer\n");
   char cadena[MAX_CARRACTERES];
   ifstream fe(nombre);
   int valor=0;
   while(!fe.eof()) {
     valor++;
      fe.getline(cadena, MAX_CARRACTERES);
      printf("%s\n",cadena);
    }
   fe.close();
   printf("salir leer\n");
}

void cargar_datos(int datos[DATOS][DATOS], char *nombre,int seccion_fila, int seccion_columna){
  //printf("enrtro en cargar datos\n");
  char cadena[MAX_CARRACTERES];
  int fila=0;
  int columna=0;
  long contador=0;
  ifstream fe(nombre);
  while(!fe.eof()) {
    contador++;
    fe.getline(cadena, MAX_CARRACTERES);
    if(contador<5){continue;}
    if (strcmp(BLANCO,cadena)==0) {
        datos[fila][columna]=BLANCO_VALOR;
        //pasar_a_bd_laberinto(seccion_fila,seccion_columna,fila,columna,true);
      }
      else{
         if (strcmp(NEGRO,cadena)==0) {
           datos[fila][columna]=NEGRO_VALOR;
          // pasar_a_bd_laberinto(seccion_fila,seccion_columna,fila,columna,false);
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
       columna=0;
       fila++;
       if (fila==DATOS+1) {break;}
     }
  }
  fe.close();
  //printf("Salir cargar_datos\n");
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
  if (seccion_fila<3 or seccion_columna>126) {
    printf("Error en buscar_abierto\n");
  } else {
    switch (seccion_columna) {
      case 1 :
        if (seccion_fila==3) {
          for (int c = 0; c < DATOS; c++) {
            if (datos[DATOS-1][c]==1) {
                    vector_blancos_fila[contador]=DATOS-1;
                    vector_blancos_columna[contador]=c;
                    //printf("variable(columna 1) -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
                    contador++;
            }else{continue;}
          }
          for (int f = 0; f <DATOS; f++) {
            if (datos[f][DATOS-1]==1) {
                    vector_blancos_fila[contador]=f;
                    vector_blancos_columna[contador]=DATOS-1;
                    //printf("ariable(fila) 1 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
                    contador++;
            }else{continue;}
          }
        } else if(seccion_fila>3 and seccion_fila<128){
          for (int c = 0; c < DATOS; c++) {
            if (datos[DATOS-1][c]==1) {
                    vector_blancos_fila[contador]=DATOS-1;
                    vector_blancos_columna[contador]=c;
                    //printf("variable(columna) 1,4 127 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
                    contador++;
            }else{continue;}
          }
          for (int c = 0; c < DATOS; c++) {
            if (datos[0][c]==1) {
                    vector_blancos_fila[contador]=0;
                    vector_blancos_columna[contador]=c;
                    //printf("variable(columna) 1,4 127 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
                    contador++;
            }else{continue;}
          }
          for (int f = 0; f <DATOS; f++) {
            if (datos[f][DATOS-1]==1) {
                    vector_blancos_fila[contador]=f;
                    vector_blancos_columna[contador]=DATOS-1;
                    //printf("ariable(fila) 1,4 127 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
                    contador++;
            }else{continue;}
          }
        }else if(seccion_fila==128){
          for (int c = 0; c < DATOS; c++) {
            if (datos[0][c]==1) {
                    vector_blancos_fila[contador]=0;
                    vector_blancos_columna[contador]=c;
                    //printf("variable(columna) 1,4 127 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
                    contador++;
            }else{continue;}
          }
          for (int f = 0; f <DATOS; f++) {
            if (datos[f][DATOS-1]==1) {
                    vector_blancos_fila[contador]=f;
                    vector_blancos_columna[contador]=DATOS-1;
                    //printf("ariable(fila) 1,4 127 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
                    contador++;
            }else{continue;}
          }
        }
        else{printf("Error\n");}
        break;
      case 126:
        if (seccion_fila==3) {
          for (int c = 0; c < DATOS; c++) {
            if (datos[DATOS-1][c]==1) {
              vector_blancos_fila[contador]=DATOS-1;
              vector_blancos_columna[contador]=c;
              //printf("variable(columna) 126 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }else{continue;}
          }
          for (int f = 0; f <DATOS; f++) {
            if (datos[f][0]==1) {
              vector_blancos_fila[contador]=f;
              vector_blancos_columna[contador]=0;
              //printf("variable(fila) 126 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }else{continue;}
          }
        } else if(seccion_fila>3 and seccion_fila<128){
          for (int c = 0; c < DATOS; c++) {
            if (datos[DATOS-1][c]==1) {
              vector_blancos_fila[contador]=DATOS-1;
              vector_blancos_columna[contador]=c;
              //printf("variable(columna) 126 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }
            else{continue;}
          }
          for (int c = 0; c < DATOS; c++) {
            if (datos[0][c]==1) {
              vector_blancos_fila[contador]=0;
              vector_blancos_columna[contador]=c;
              //printf("variable(columna) 126 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }else{continue;}
          }
          for (int f = 0; f <DATOS; f++) {
            if (datos[f][0]==1) {
              vector_blancos_fila[contador]=f;
              vector_blancos_columna[contador]=0;
              //printf("variable(fila) 126 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }else{continue;}
          }
        }else if (seccion_fila==128){
          for (int c = 0; c < DATOS; c++) {
            if (datos[0][c]==1) {
              vector_blancos_fila[contador]=0;
              vector_blancos_columna[contador]=c;
              //printf("variable(columna) 126 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }else{continue;}
          }
          for (int f = 0; f <DATOS; f++) {
            if (datos[f][0]==1) {
              vector_blancos_fila[contador]=f;
              vector_blancos_columna[contador]=0;
              //printf("variable(fila) 126 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }else{continue;}
          }
        }
        else{printf("Error en buscar camino\n");}
          break;
      case 127:
        printf("Error en buscar camino\n");
        break;
      case 128:
        printf("Error en buscar camino\n");
        break;
      default:
        if (seccion_fila==3) {
          for (int c = 0; c < DATOS; c++) {
            if (datos[DATOS-1][c]==1) {
              vector_blancos_fila[contador]=DATOS-1;
              vector_blancos_columna[contador]=c;
              //printf("variable(columna) 2-125 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }else{continue;}
          }
          for (int f = 0; f <DATOS; f++) {
            if (datos[f][0]==1) {
              vector_blancos_fila[contador]=f;
              vector_blancos_columna[contador]=0;
            //  printf("variable(fila) 2-125 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }else{continue;}
          }
          for (int f = 0; f <DATOS; f++) {
            if (datos[f][DATOS-1]==1) {
                    vector_blancos_fila[contador]=f;
                    vector_blancos_columna[contador]=DATOS-1;
                    //printf("variable(fila) 2-125 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
                    contador++;
            }else{continue;}
          }
        } else if(seccion_fila>3 and seccion_fila<128){
          for (int c = 0; c < DATOS; c++) {
            if (datos[DATOS-1][c]==1) {
              vector_blancos_fila[contador]=DATOS-1;
              vector_blancos_columna[contador]=c;
              //printf("variable(columna) 2-125 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }else{continue;}
          }
          for (int c = 0; c < DATOS; c++) {
            if (datos[0][c]==1) {
              vector_blancos_fila[contador]=0;
              vector_blancos_columna[contador]=c;
              //printf("variable(columna) 2-125 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }else{continue;}
          }
          for (int f = 0; f <DATOS; f++) {
            if (datos[f][0]==1) {
              vector_blancos_fila[contador]=f;
              vector_blancos_columna[contador]=0;
              //printf("variable(fila) 2-125 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
            }else{continue;}
          }
          for (int f = 0; f <DATOS; f++) {
            if (datos[f][DATOS-1]==1) {
                vector_blancos_fila[contador]=f;
                vector_blancos_columna[contador]=DATOS-1;
                    //printf("variable(fila) 2-125 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
                contador++;
            }else{continue;}
          }
        }
      else if (seccion_fila==128){
        for (int c = 0; c < DATOS; c++) {
          if (datos[0][c]==1) {
            vector_blancos_fila[contador]=0;
            vector_blancos_columna[contador]=c;
            //printf("variable(columna) 2-125 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
            contador++;
          }else{continue;}
        }
        for (int f = 0; f <DATOS; f++) {
          if (datos[f][0]==1) {
            vector_blancos_fila[contador]=f;
            vector_blancos_columna[contador]=0;
            //printf("variable(fila) 2-125 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
            contador++;
          }else{continue;}
        }
        for (int f = 0; f <DATOS; f++) {
          if (datos[f][DATOS-1]==1) {
              vector_blancos_fila[contador]=f;
              vector_blancos_columna[contador]=DATOS-1;
                  //printf("variable(fila) 2-125 -> %d-%d\n",vector_blancos_fila[contador],vector_blancos_columna[contador] );
              contador++;
          }else{continue;}
        }
      }
      else{printf("Error en buscar camino\n");}
        break;
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
  query = "INSERT INTO camino (seccion_fila,seccion_columna,inicio_fila,fin_fila,inicio_columna,fin_columna,camino)  VALUES ("+ to_string(seccion_fila) + ","+to_string(seccion_columna)+","+to_string(fila_inicio)+","+to_string(fila_fin)+","+to_string(columna_inicio)+","+to_string(columna_fin)+",'"+camino+"');";
  //std::cout << query << '\n';
  work W(conn);
  W.exec(query);
  W.commit();
  cout << "ingreso correcto de datoss" << endl;
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
  char resultado_camino[8000];
  int valor_ba;
  valor_ba=funcion_main( datos, inicio_fila,inicio_columna,fin_fila,fin_columna,resultado_camino);
  if(valor_ba==1){
    pasar_a_bd_inicio_fin(inicio_fila,fin_fila,inicio_columna,fin_columna,seccion_fila, seccion_columna, resultado_camino);
  }
}

void buscar_camino_pares(int vector_blancos_fila[MAX_FILA_DATOS],int vector_blancos_columna[MAX_COLUMNA_DATOS], int cuantos , int datos[DATOS][DATOS],int seccion_fila, int seccion_columna){
  printf("entro en buscar_camino_pares\n");
  if (seccion_fila==3 && seccion_columna==1) {
    for (int x = 0; x < cuantos; x++) {
        generar_camino(0,0,vector_blancos_fila[x],vector_blancos_columna[x], datos ,seccion_fila, seccion_columna);
    }
  }else{
  if (seccion_fila==128 && seccion_columna==126) {
      for (int x = 0; x < cuantos; x++) {
          generar_camino(199,199,vector_blancos_fila[x],vector_blancos_columna[x], datos ,seccion_fila, seccion_columna);
          generar_camino(vector_blancos_fila[x],vector_blancos_columna[x],199,199, datos ,seccion_fila, seccion_columna);
      }
    }
  }
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
