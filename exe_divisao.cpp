#include <iostream>

using namespace std;

int main (){
  int valor1 = 3;
  int valor2 = 2;

  // Neste caso é necessário realizar uma mudança de tipo
  float divisao = (float)valor1 / valor2;

  cout << "O resultado da divisão é: " << divisao;
}
