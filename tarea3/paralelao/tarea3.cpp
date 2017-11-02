#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>
#include <sys/stat.h>
#include "quicksort.cpp"
#include "tarea3_funciones.cpp"

using namespace std;

int main(int argc, char** argv) {
    double t0=clock();
    int myid, numprocs;
    /*dato para enviar mediante mpi */
    long contadoraux[32]={0} , N=32; //<<<<<<<<<<<<< esto es lo que se envia
    /*inicia el mpi*/
    MPI_Init(&argc, &argv);
    /*devuelve el maximo procesos */
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    /*identica cada proceso */
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    /*Informacion  util del MPI */
    MPI_Status info;
    int origen, destino,tag;
    int archivo=0;
    long  valor = 250000000;
    long arreglo[4]={9999999999,9999999999,0,(valor*9)};
    long arregloA[10]={0};
    long arregloMenor[9] = {0};
    long arreglomayor[9] ={0};
    long temporal=0;
    int iteraciones=0;
    char str[20];
    sprintf(str, "%d", myid);
    const int dir_err = mkdir(str, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
      if (-1 == dir_err)
      {
          printf("Error creating directory!n");
          exit(1);
      }
      if (archivo==0 ){
        separ_archivo(arreglo,valor,0,arregloA,arregloMenor,arreglomayor,numprocs,myid);
      }else if (archivo!=99 and archivo!=0){
        separ_archivo(arreglo,(arreglo[3]-arreglo[2])/9,archivo,arregloA,arregloMenor,arreglomayor,numprocs,myid);
      }else{
        exit(0);// error
      }
      contadoraux[0]=arreglo[0];
      contadoraux[1]=arreglo[1];
      contadoraux[2]=arreglo[2];
      contadoraux[3]=arreglo[3];
      contadoraux[4]=arregloA[0];
      contadoraux[5]=arregloA[1];
      contadoraux[6]=arregloA[2];
      contadoraux[7]=arregloA[3];
      contadoraux[8]=arregloA[4];
      contadoraux[9]=arregloA[5];
      contadoraux[10]=arregloA[6];
      contadoraux[11]=arregloA[7];
      contadoraux[12]=arregloA[8];
      contadoraux[13]=arregloA[9];
      contadoraux[14]=arregloMenor[0];
      contadoraux[15]=arregloMenor[1];
      contadoraux[16]=arregloMenor[2];
      contadoraux[17]=arregloMenor[3];
      contadoraux[18]=arregloMenor[4];
      contadoraux[19]=arregloMenor[5];
      contadoraux[20]=arregloMenor[6];
      contadoraux[21]=arregloMenor[7];
      contadoraux[22]=arregloMenor[8];
      contadoraux[23]=arreglomayor[0];
      contadoraux[24]=arreglomayor[1];
      contadoraux[25]=arreglomayor[2];
      contadoraux[26]=arreglomayor[3];
      contadoraux[27]=arreglomayor[4];
      contadoraux[28]=arreglomayor[5];
      contadoraux[29]=arreglomayor[6];
      contadoraux[30]=arreglomayor[7];
      contadoraux[31]=arreglomayor[8];
      /*identificar el master*/
      if (myid==0) {
        /*for para recorre todos los procesos activos */
          /*mpi que recive  todo los datos de los mpi send */
          origen = 1; tag = 0;
          MPI_Recv(&contadoraux[0], N, MPI_LONG, origen, tag, MPI_COMM_WORLD, &info);
          contadoraux[4]+=arregloA[0];
          contadoraux[5]+=arregloA[1];
          contadoraux[6]+=arregloA[2];
          contadoraux[7]+=arregloA[3];
          contadoraux[8]+=arregloA[4];
          contadoraux[9]+=arregloA[5];
          contadoraux[10]+=arregloA[6];
          contadoraux[11]+=arregloA[7];
          contadoraux[12]+=arregloA[8];
          contadoraux[13]+=arregloA[9];

          contadoraux[14]=menor(contadoraux[14],arregloMenor[0]);
          contadoraux[15]=menor(contadoraux[15],arregloMenor[1]);
          contadoraux[16]=menor(contadoraux[16],arregloMenor[2]);
          contadoraux[17]=menor(contadoraux[17],arregloMenor[3]);
          contadoraux[18]=menor(contadoraux[18],arregloMenor[4]);
          contadoraux[19]=menor(contadoraux[19],arregloMenor[5]);
          contadoraux[20]=menor(contadoraux[20],arregloMenor[6]);
          contadoraux[21]=menor(contadoraux[21],arregloMenor[7]);
          contadoraux[22]=menor(contadoraux[22],arregloMenor[8]);

          contadoraux[23]=mayor(contadoraux[23],arreglomayor[0]);
          contadoraux[24]=mayor(contadoraux[24],arreglomayor[1]);
          contadoraux[25]=mayor(contadoraux[25],arreglomayor[2]);
          contadoraux[26]=mayor(contadoraux[26],arreglomayor[3]);
          contadoraux[27]=mayor(contadoraux[27],arreglomayor[4]);
          contadoraux[28]=mayor(contadoraux[28],arreglomayor[5]);
          contadoraux[29]=mayor(contadoraux[29],arreglomayor[6]);
          contadoraux[30]=mayor(contadoraux[30],arreglomayor[7]);
          contadoraux[31]=mayor(contadoraux[31],arreglomayor[8]);
        long tempro=0;
        for (int i = 4; i < 13; i++) {
          tempro+=contadoraux[i];
        }
        arreglo[0]=tempro;
        arreglo[1]=tempro/2;
        arreglo[2]=contadoraux[2];
        arreglo[3]=contadoraux[3];
        /*std::cout << "total " <<arreglo[0]<<'\n';
        std::cout << "media " <<arreglo[1]<<'\n';
        std::cout << "minima " <<arreglo[2]<<'\n';
        std::cout << "maxima " <<arreglo[3]<<'\n';*/

        arregloA[0]=contadoraux[4];
        arregloA[1]=contadoraux[5];
        arregloA[2]=contadoraux[6];
        arregloA[3]=contadoraux[7];
        arregloA[4]=contadoraux[8];
        arregloA[5]=contadoraux[9];
        arregloA[6]=contadoraux[10];
        arregloA[7]=contadoraux[11];
        arregloA[8]=contadoraux[12];
        arregloA[9]=contadoraux[13];

        /*for (int i = 0; i < 10; i++) {
          printf("arregloA %d %ld\n",i,arregloA[i] );
        }*/

        arregloMenor[0]=contadoraux[14];
        arregloMenor[1]=contadoraux[15];
        arregloMenor[2]=contadoraux[16];
        arregloMenor[3]=contadoraux[17];
        arregloMenor[4]=contadoraux[18];
        arregloMenor[5]=contadoraux[19];
        arregloMenor[6]=contadoraux[20];
        arregloMenor[7]=contadoraux[21];
        arregloMenor[8]=contadoraux[22];

        /*for (int i = 0; i < 9; i++) {
          printf("arreglomenor %d %ld\n",i,arregloMenor[i] );
        }*/

        arreglomayor[0]=contadoraux[23];
        arreglomayor[1]=contadoraux[24];
        arreglomayor[2]=contadoraux[25];
        arreglomayor[3]=contadoraux[26];
        arreglomayor[4]=contadoraux[27];
        arreglomayor[5]=contadoraux[28];
        arreglomayor[6]=contadoraux[29];
        arreglomayor[7]=contadoraux[30];
        arreglomayor[8]=contadoraux[31];

        /*for (int i = 0; i < 9; i++) {
          printf("arreglomayor %d %ld\n",i,arreglomayor[i] );
        }*/
        if (archivo==0 ){
          //separ_archivo(arreglo,valor,0,arregloA,arregloMenor,arreglomayor,numprocs,myid);
          archivo=elegir_archivo(arreglo,0,arregloA,arregloMenor,arreglomayor);
        }else if (archivo!=99 and archivo!=0){
          //separ_archivo(arreglo,(arreglo[3]-arreglo[2])/9,archivo,arregloA,arregloMenor,arreglomayor,numprocs,myid);
          archivo=elegir_archivo(arreglo,archivo,arregloA,arregloMenor,arreglomayor);
        }else{
          exit(0);// error
        }
      }
      /*lo que hacen los esclavos */
      else if(myid==1){
        /*aqui va lo que se quiere hacer los esclavos*/
         /*mpi enviar datos  hasta el master */
          destino = 0; tag = 0;
            MPI_Send(&contadoraux[0], N, MPI_LONG, destino, tag, MPI_COMM_WORLD);
      }
    if (myid==0) {
      unir_archivo(archivo,numprocs);
      media(archivo,arreglo[0],arreglo[1]-1);      //contador de tiempo de ejecución
      double t1 = clock();
      double time = (double(t1-t0)/CLOCKS_PER_SEC);
      cout <<" :Tiempo: " << time << endl;
    }
    /*cierra el mpi */
      MPI_Finalize();
    return 0;
}
