#include <iostream>
using namespace std;

int main(){

     // Definindo um vetor 'x' de 5 posições
     int x[5];

     // Declarando as variáveis necessárias
     int i, j, eleito;

     // Recebendo do usuário os números e preenchendo o x
     for(i=0; i<=4; i++){
          cout << "Digite o " << i+1 << "º número: ";
          cin >> x[i];
     }

     // Começa pelo índice 1 (segunda posição do x)
     for(i=1; i<=4; i++){
          eleito = x[i]; // A variável 'eleito' receberá o valor contido no índice
          j = i - 1; // A variável 'j' receberá o índice - 1

          while (j>=0 && x[j] > eleito){
               x[j+1] = x[j];
               j = j - 1;
          }
          x[j+1] = eleito;
     }

     // Exibindo valores do vetor ordenado
     for (i=0; i<=4; i++) {
          cout << "\n" << i+1 << "º número: " << x[i];
     }
     cout << "\nAcabou...";
     return 0;
}
