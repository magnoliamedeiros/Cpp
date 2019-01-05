#include <iostream>
using namespace std;

// Assinatura do método
int fatorial(int n);

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
