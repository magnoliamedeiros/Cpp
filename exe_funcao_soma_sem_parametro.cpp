#include<iostream>
using namespace std;

// Protótipo da função
void soma();

int main(){
     
     // Chamando a função soma()
     soma();
     cout << "fim..." << endl;
     return 0;
}

// Funçao soma
void soma() {
     int num1 = 23;
     int num2 = 27;

     int resultado = num1 + num2;

     cout << "O resultado da soma é: " << resultado << "\n";
}
