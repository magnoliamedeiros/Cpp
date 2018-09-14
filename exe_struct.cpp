#include<iostream>
using namespace std;
int main(){
     /* structs em C++ são usados para armazenar diversas variáveis
     correspondentes a um mesmo elemento.
     */
    struct funcionario{
         string nome;
         int idade;
         string profissao;
    };

    // declarando um registro e atribuindo valores a ele
    struct funcionario estagiario = {"Márcio", 23, "Pintor"};

    // acessando valor
    cout << "Nome: "<< estagiario.nome << "\n";
    cout << "Idade: " << estagiario.idade << "\n";
    cout << "Profissão: " << estagiario.profissao << "\n";
    return 0;
}
