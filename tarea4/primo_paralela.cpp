#include <iostream>
#include <stdlib.h>     /* atoi */
#include <time.h>
#include <mpi.h>
bool funcion_primo(long valor);

int main(int argc, char **argv) {
  clock_t start, end;
  start = clock();
  double secs;
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
  long contadoraux[3];
  int contador=0;
  int N=3;
  if (argc==2) {
    long valor= atoi(argv[1]);
    contadoraux[0]=(valor/numprocs)*myid;
    contadoraux[1]=(valor/numprocs)*(myid+1);
    contadoraux[2]=0;
    /*identificar el master*/
    if (myid==0) {
      for (long  i = (contadoraux[0]+1); i <=contadoraux[1]; i++) {
        if(funcion_primo(i)){
          contador++;
        }
      }
      /*for para recorre todos los procesos activos */
      for (int i = 1; i < numprocs ; i++) {
        /*mpi que recive  todo los datos de los mpi send */
        MPI_Recv(&contadoraux[0], N, MPI_LONG, i, 0, MPI_COMM_WORLD, &info);
        /*aqui va lo que se quiere hacer el master*/
        contador=contador+contadoraux[2];
        //std::cout << contadoraux[1] << '\n';
      }
    }
    /*lo que hacen los esclavos */
    else{
          /*aqui va lo que se quiere hacer los esclavos*/
          if (myid+1==numprocs){contadoraux[1]=valor;}
          for (long  i = contadoraux[0]+1; i <=contadoraux[1]; i++) {
            if(funcion_primo(i)){
              contador++;
            }
          }
          contadoraux[2]=contador;
           /*mpi enviar datos  hasta el master */
           MPI_Send(&contadoraux[0], N, MPI_LONG, 0, 0, MPI_COMM_WORLD);
    }
    /*cierra el mpi */
    MPI_Finalize();
  }
  else {
    std::cout << "Error en los parametros" << '\n';
  }
  if (myid==0) {
    std::cout  << '\n';
    end = clock();
    secs = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "son un total de " <<contador<<" numeros primo"<< '\n';
    std::cout << "El tiempo del programa es " <<secs * 1000.0 <<" milisegundos"<< '\n';
  }
  return 0;
}

bool funcion_primo(long valor){
  bool primo = true;
  for (long  i = 2; (i < valor) && (primo == true); i++) {
    if (valor % i == 0) {
      primo = false;
    }
  }
  if (primo == true) {
    std::cout << valor <<"  ";
    return true;
  }
  return false;
}
