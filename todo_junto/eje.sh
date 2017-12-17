clear
rm resultado -f -r
g++ programa.cpp -o p -lpqxx -lpq -fopenmp
#g++ prueba.cpp -o p -fopenmp
./p
#
