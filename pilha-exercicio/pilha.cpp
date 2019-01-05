#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

struct PILHA{
    int num;
    PILHA *prox;
};

int main(){

     PILHA *topo = NULL; // Inicialmente a pilha se encontra vazia
     PILHA *aux; // O ponteiro 'aux' é um ponteiro auxiliar

     // Mostrando um pequeno menu:
     int op;

     do {
     // clrscr();
     system("cls");
     cout << "\n=== MENU DE OPÇÕES ===";
     cout << "\n1 - Inserir elemento na PILHA";
     cout << "\n2 - Consultar elementos da PILHA";
     cout << "\n3 - Sair";

     cout << "\nDigite"
     cout << "Digite um número a ser inserido na PILHA: ";
     PILHA *novo = new PILHA();
     cin >> novo->num;
     novo->prox = topo;
     topo = novo;
     cout << "Número inserido na PILHA!";
     return 0;
}
