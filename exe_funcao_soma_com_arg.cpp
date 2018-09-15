#include<iostream>
using namespace std;

// Protótipo da função soma
void soma(int num1, int num2);

int main(){
     int valor1 = 24;
     int valor2 = 36;

     soma(valor1, valor2);

     cout << "Fim...";
     return 0;
}

void soma(int num1, int num2){
     int resultado = num1 + num2;
     cout << "O resultado da soma é: " << resultado << endl;
}
