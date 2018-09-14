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
    struct funcionario f1 = {"Márcio", 23, "Finanças"};
    struct funcionario f2 = {"José", 35, "Contabilidade"};

    // exibindo os valores
    cout << "Nome: " << f1.nome << "\n";
    cout << "Idade: " << f1.idade << "\n";
    cout << "Setor: " << f1.setor << "\n\n";

    cout << "Nome: " << f2.nome << "\n";
    cout << "Idade: " << f2.idade << "\n";
    cout << "Setor: " << f2.setor << "\n";
    return 0;
}
