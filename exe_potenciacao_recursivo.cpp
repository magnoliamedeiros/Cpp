#include <iostream>

using namespace std;

// A analise da complexidade é -> 0(n).

// Assinatura do método
int pot(int b, int e);

int main() {
     int b, e, result;
     cout << "Informe a base 'b': ";
     cin >> b;

     cout << "Informe o expoente 'e': ";
     cin >> e;

     result = pot(b,e);

     cout << "O resultado é: " << result << endl;

     cout << "Complexidade: O(n)." << endl;

     return 0;
}

// Função recursiva para o calculo
int pot(int b, int e){
     if(e == 0){
          return 1;
     } else if(e == 1) {
          return b;
     } else {
          return b * pot(b, e-1);
     }
}
