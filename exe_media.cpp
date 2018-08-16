#include <iostream>

using namespace std;
int main (){

     char nome;
     float nota1, nota2, nota3, mediaPonderada;

     cout << "## CALCULANDO MÉDIA PONDERADA DE UM ALUNO ##\n\n";

     cout << "Por favor, informe o nome do aluno: \n";
     cin >> nome;

     cout << "Informe a primeira nota do aluno: \n";
     cin >> nota1;

     cout << "Informe a segunda nota do aluno: \n";
     cin >> nota2;

     cout << "Informe a terceira nota do aluno: \n";
     cin >> nota3;

     mediaPonderada = (nota1 + nota2*2 + nota3*3) / 6;
     cout << "Resultado: " << mediaPonderada << "\n";

     return 0;
}
