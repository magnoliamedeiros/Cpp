#include <iostream>

// Assinatura do método
int fatorial(int n);

using namespace std;

int main() {
     cout << fatorial(5);
     return 0;
}

// Função recursiva
int fatorial(int n){
     if (n == 1){
          return 1;
     } else {
          return n * fatorial(n - 1);
     }
}
