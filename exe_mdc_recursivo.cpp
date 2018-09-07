#include <iostream>

using namespace std;

// Assinatura do método
int mdc(int m, int n);

int main() {
     // Máximo Divisor Comum de dois números
     cout << "O resultado é: " << mdc(16,24);
}

// Função recursiva
int mdc(int m, int n){
     if(n == 0){
          return m;
     } else {
          return mdc(n, m % n);
     }
}
