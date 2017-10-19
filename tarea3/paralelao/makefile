#ejemplo de mpi
run : compilar #un solo pc multiple nodo
	mpirun -n 2 ./programa
compilar: tarea3.cpp
	mpicxx tarea3.cpp -o programa
clean:
	rm programa rm *.csv
