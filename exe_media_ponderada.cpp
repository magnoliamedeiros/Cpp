#include <iostream>
using namespace std;

// Assinatura do método
void mediaPonderada(float nota1, float nota2, float nota3);

// Declarando um structs
struct aluno{
    char nome[100];
    float n1, n2, n3;

    // Função para calculo da media
    void mediaPonderada(){
         float media = (n1 + n2*2 + n3*3) / 6;
         if (media >= 9.0){
             cout << "A média de " << nome << " é: " << media << ", sendo assim conceito: 'A'.";
         } else if (media >= 7.5 && media < 9.0){
             cout << "A sua média é: " << media << ", sendo assim conceito: 'B'.";
         } else if (media >= 6.0 && media < 7.5){
             cout << "A sua média é: " << media << ", sendo assim conceito: 'C'.";
         } else if (media >= 4.0 && media < 6.0){
             cout << "A sua média é: " << media << ", sendo assim conceito: 'D'.";
         } else {
             cout << "A sua média é: " << media << ", sendo assim conceito: 'E'.";
         }
    }
};

int main (){
     int qtd;
     int i = 0;
     cout << "Deseja realizar a média ponderada de quantos alunos? ";
     cin >> qtd;
     
     aluno* al = new aluno[qtd];

     while (i < qtd) {
          cout << "Por favor, informe o " << i+1 << "° nome do aluno: ";
          cin >> al[i].nome;

          cout << "Informe a primeira nota (Formato 9.0): ";
          cin >> al[i].n1;

          cout << "Informe a segunda nota (Formato 9.0): ";
          cin >> al[i].n2;

          cout << "Informe a terceira nota (Formato 9.0): ";
          cin >> al[i].n3;

          al[i].mediaPonderada();
          i++;

          cout << "\n\n" << endl;
     }
     cout << "\nFim...";
     return 0;
}
