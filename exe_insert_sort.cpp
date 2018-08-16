#include <iostream>

using namespace std;

int main(){

     // Definindo um vetor de 5 posições
     int vetor[5];

     // Declarando as variáveis necessárias
     int i, j, aux;

     // Recebendo do usuário os números e carregando no vetor
     for(i=0; i<=4; i++){
          cout << "Digite o " << i+1 << "º número: ";
          cin >> vetor[i];
     }

     for(i=1; i<=4; i++){
          aux = vetor[i];
          j = i - 1;
          while (j>=0 && vetor[j] > aux){
               vetor[j+1] = vetor[j];
               j = j - 1;
          }
          vetor[j+1] = aux;
     }

     // Mostrando o vetor ordenado
     for (i=0; i<=4; i++) {
          cout << "\n" << i+1 << "º número: " << vetor[i];
     }
     cout << "\nAcabou";
     return 0;
}
