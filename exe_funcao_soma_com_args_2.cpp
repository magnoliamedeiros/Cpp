#include<iostream>
using namespace std;

// Protótipo da função soma
int soma(int num1, int num2);

int main(){
     int v1 = 12;
     int v2 = 13;

     int result = soma(v1, v2);

     cout << "O resultado da soma é: " << result << "\n";
     cout << "Fim...";

     return 0;
}

int soma(int num1, int num2){
     int resultado = num1 + num2;
     return resultado;
}
