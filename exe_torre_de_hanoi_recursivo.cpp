#include <iostream>

using namespace std;

// Assinatura do método
void hanoi(int n, int o, int a, int d);

int main() {
     // hanoi(1,1,2,3);
     // hanoi(2,1,2,3);
     // hanoi(3,1,2,3);
     hanoi(4,1,2,3);
}

// Função recursiva
void hanoi(int n, int o, int a, int d){
     if (n > 0){ // Caso base
          hanoi(n-1, o, d, a);
          cout << "Disco transferido da torre " << o << " para a torre " << d << endl;
          hanoi(n-1, a, o, d);
     }
}
