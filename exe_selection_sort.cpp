#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
//system("cls");
int main(){
     // Definindo um vetor 'x' de 5 posições
     int x[5];

     // Declarando as variáveis necessárias
     int i, j, eleito, menor, pos;

     system("cls");

     // Carregando os números no vetor
     for(i = 0; i <= 4; i++){
          cout << "Digite o " << i + 1 << "º número: ";
          cin >> x[i];
     }
}
