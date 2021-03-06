#include <iostream>
#include <stdlib.h>     /* atoi */
#include <time.h>
bool funcion_primo(long valor);

int main(int argc, char const *argv[]) {
  clock_t start, end;
  start = clock();
  double secs;
  int contador=0;
  if (argc==2) {
    long valor= atoi(argv[1]);
    for (long  i = 1; i <= valor; i++) {
      if(funcion_primo(i)){
        contador++;
      }
    }
    std::cout  << '\n';
  } else {
    std::cout << "Error en los parametros" << '\n';
  }
  end = clock();
  secs = (double)(end - start) / CLOCKS_PER_SEC;
  std::cout << "son un total de " <<contador<<" numeros primo"<< '\n';
  std::cout << "El tiempo del programa es " <<secs * 1000.0 <<" milisegundos"<< '\n';
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
    std::cout << valor <<"\n";
    return true;
  }
  return false;
}
