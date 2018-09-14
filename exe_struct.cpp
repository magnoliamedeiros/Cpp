#include<iostream>
using namespace std;

/* structs em C++ são usados para armazenar diversas variáveis
correspondentes a um mesmo elemento.
*/
struct funcionario{
    string nome;
    int idade;
    string setor;
};

int main(){

    // declarando um registro e atribuindo valores ao mesmo
    struct funcionario estagiario = {"Márcio", 23, "Finanças"};

    // exibindo os valores
    cout << "Nome: "<< estagiario.nome << "\n";
    cout << "Idade: " << estagiario.idade << "\n";
    cout << "Setor: " << estagiario.setor << "\n";
    return 0;
}
