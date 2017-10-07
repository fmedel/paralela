#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;
const int width =1024, height =768; //1024 768 ---> 4096 2160 --->4:2.8
void pasar_ancho(){
  ofstream tep("monica_t.txt");
  char line[200];
  FILE *archivo = fopen("monica_original.txt","r");
  while(fgets(line, sizeof(line), archivo)){
    tep<<line;
    tep<<line;
    tep<<line;
    tep<<line;
  }
  fclose(archivo);
  tep.close();
}
void pasar_alto(){
  ofstream img("monica.pmm");
  FILE * temporal_o;
  FILE * temporal;
  char line[200];
  char line2[200];
  int y=1,x=0;
  img<<"P3"<<endl;
  img<<width*4<<" "<<height*3<<endl;
  img<<"255"<<endl;
  FILE *archivo = fopen("monica_t.txt","r");
  temporal_o=fopen("temporal.txt","w");
  while(fgets(line, sizeof(line), archivo)){
    fputs(line,temporal_o);
  //leer archivo temporal y duplicarlo  3 veces  cada  4096 lineas
    if (y==(width*4)) {
      y=1;
      fclose(temporal_o);
      for (int i = 0; i<3 ; i++) {
        temporal = fopen("temporal.txt", "r");
        if (temporal==NULL){printf("Error al entrar");}
        while(fgets(line2, sizeof(line2), temporal)){
            img<<line2;
          }
        fclose(temporal);
      }
      temporal_o=fopen("temporal.txt","w");
    }else{
        y++;
    }
  }
  fclose(temporal_o);
  remove("temporal.txt");
  fclose(archivo);
  img.close();
  //remove("temporal.txt");
}
int main(int argc, char const *argv[]) {
  pasar_ancho(); //eata ok
  pasar_alto();
  remove("monica_t.txt");
  return 0;
}
