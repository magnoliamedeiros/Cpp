#include <iostream>

// Assinatura do método
int fibonacci(int n);

using namespace std;

int main() {
     cout << fibonacci(7);
     return 0;
}

// Função recursiva
int fibonacci(int n){
     if (n == 0){
          return 0;
     } else if (n == 1){
          return 1;
     } else {
          return fibonacci(n-1) + fibonacci(n-2);
     }
}
