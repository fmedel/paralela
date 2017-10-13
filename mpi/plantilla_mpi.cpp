#include <mpi.h>
#include <iostream>
int main(int argc, char** argv) {
    int myid, numprocs;
    /*inicia el mpi*/
    MPI_Init(&argc, &argv);
    /*devuelve el maximo procesos */
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    /*identica cada proceso */
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    /*Informacion  util del MPI */
    MPI_Status info;
    /*dato para enviar mediante mpi */
        int contadoraux[6]={0} , N=6; //<<<<<<<<<<<<< esto es lo que se envia
    /*identificar el master*/
    if (myid==0) {
      /*for para recorre todos los procesos activos */
      for (int i = 1; i < numprocs ; i++) {
        /*mpi que recive  todo los datos de los mpi send */
        MPI_Recv(&contadoraux[0], N, MPI_INT, i, 0, MPI_COMM_WORLD, &info);
        /*aqui va lo que se quiere hacer el master*/
          std::cout << contadoraux[1] << '\n';
      }
    }
    /*lo que hacen los esclavos */
    else{
          /*aqui va lo que se quiere hacer los esclavos*/
           contadoraux[1]=myid;
     /*mpi enviar datos  hasta el master */
      MPI_Send(&contadoraux[0], N, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    /*cierra el mpi */
    MPI_Finalize();
    return 0;
}
