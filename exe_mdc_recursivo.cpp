#include <iostream>

using namespace std;

// A analise da complexidade é -> 0(log b).

// Assinatura do método
int mdc(int m, int n);

int main() {
     int m, n, result;

     cout << "Informe 'm': ";
     cin >> m;

     cout << "Informe 'n': ";
     cin >> n;

     result = mdc(m, n);

     cout << "O resultado é: " << result << endl;

     cout << "O algoritmo tem complexidade: O(log b)" << endl;
}

// Função recursiva para calculo do MDC
int mdc(int m, int n){
     if(n == 0){
          return m;
     } else {
          return mdc(n, m % n);
     }
}
