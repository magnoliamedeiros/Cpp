#include <iostream>

using namespace std;

// 4) Crie uma função para calcular a potenciação de um número n dado sua base e expoente.
// Utilize recursividade para resolver o problema. Em seguida analise a complexidade do algoritmo criado.
// Resposta da analise da complexidade -> 0(n).

// Assinatura do método
int pow(int b, int e);

int main() {
     int b, e, result;
     cout << "Informe a base 'B': ";
     cin >> b;

     cout << "Informe o expoente 'E': ";
     cin >> e;

     result = pow(b,e);

     cout << "O resultado é: " << result << endl;

     // cout << pow(2,3);

     return 0;
}

// Função recursiva
int pow(int b, int e){
     if(e == 0){
          return 1;
     } else if(e == 1) {
          return b;
     } else {
          return b * pow(b, e-1);
     }
}
