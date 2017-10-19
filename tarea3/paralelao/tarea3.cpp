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
    int contadoraux[6]={0} , N=6; //<<<<<<<<<<<<< esto es lo que se envia
    /*inicia el mpi*/
    MPI_Init(&argc, &argv);
    /*devuelve el maximo procesos */
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    /*identica cada proceso */
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    /*Informacion  util del MPI */
    MPI_Status info;
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
    while(arreglo[0]>100){
      iteraciones++;
      if (archivo==0 ){
        separ_archivo(arreglo,valor,0,arregloA,arregloMenor,arreglomayor,numprocs,myid);
        archivo=elegir_archivo(arreglo,0,arregloA,arregloMenor,arreglomayor);
      }else if (archivo!=99 and archivo!=0){
        separ_archivo(arreglo,(arreglo[3]-arreglo[2])/9,archivo,arregloA,arregloMenor,arreglomayor,numprocs,myid);
        archivo=elegir_archivo(arreglo,archivo,arregloA,arregloMenor,arreglomayor);
      }else{
        exit(0);// error
      }
      /*identificar el master*/
      if (myid==0) {
        /*for para recorre todos los procesos activos */
        for (int i = 1; i < numprocs ; i++) {
          /*mpi que recive  todo los datos de los mpi send */
          MPI_Recv(&contadoraux[0], N, MPI_INT, i, 0, MPI_COMM_WORLD, &info);
          /*aqui va lo que se quiere hacer el master*/
        }
      }
      /*lo que hacen los esclavos */
      else{
        
      /*aqui va lo que se quiere hacer los esclavos*/
      contadoraux[1]=myid;
       /*mpi enviar datos  hasta el master */
        MPI_Send(&contadoraux[0], N, MPI_INT, 0, 0, MPI_COMM_WORLD);
      }
    }
    if (myid==0) {
      std::cout << "archivo" <<archivo<< '\n';
      std::cout << "media "<<arreglo[1] << '\n';
      media(archivo,arreglo[0],arreglo[1]-1);      //contador de tiempo de ejecución
      double t1 = clock();
      double time = (double(t1-t0)/CLOCKS_PER_SEC);
      cout << numprocs<<" :Tiempo: " << time << endl;
    }
    /*cierra el mpi */
    MPI_Finalize();
    return 0;
}
