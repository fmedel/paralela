#ejemplo de mpi
run : compilar #un solo pc multiple nodo
	mpirun -n 4 ./tarea5_programa

multiple: compilar
	 mpirun -n 4 -hosts maestro cliente ./programa

compilar_c++: tarea.cpp
	mpicxx tarea.cpp -o programa
compilar_c: tarea.c
	mpicc tarea.c 	-o programa
clean:
	rm programa
