#ejemplo de mpi
run : compilar #un solo pc multiple nodo
	mpirun -n 4 ./programa 1100
compilar: primo_paralela.cpp
	mpicxx primo_paralela.cpp -o programa
