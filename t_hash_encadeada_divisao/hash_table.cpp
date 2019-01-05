#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

const int tam = 8; // Tamanho da tabela HASH

struct hash
{
     int chave;
     hash* prox;
};

void inserir(hash* tabela[], int pos, int n){
     hash* novo;
     novo = new hash();
     novo->chave = n;
     novo->prox = tabela[pos];
     tabela[pos] = novo;
}

int funcao_hashing(int num){
     return num % tam; // Resto da divisao
}

void mostrar_hash (hash* tabela[]){
     hash* aux;
     for (int i = 0; i < tam; i++) ; {
          aux = tabela[i];
          while (aux != NULL){
               cout << "\nEntrada " << i << ": " << aux->chave;
               aux = aux->prox;
          }
     }
}

int excluir_hash (hash* tabela[], int num){
     int pos = funcao_hashing(num);
     hash* aux;
     if (tabela[pos] != NULL){
          if (tabela[pos]->chave == num){
               aux = tabela[pos];
               tabela[pos] = tabela[pos]->prox;
               delete aux;
          } else {
               aux = tabela[pos]->prox;
               hash* ant = tabela[pos];
               while (aux != NULL && aux->chave != num){
                    ant = aux;
                    aux = aux->prox;
               }
               if (aux != NULL){
                    ant->prox = aux->prox;
                    delete aux;
               }
               else
                    cout << "\nNúmero não encontrado!";
          }
     }
     else
          cout << "\nNúmero não encontrado!";
}

int main() {
     hash* tabela[tam];
     hash* aux;
     int op, pos;
     int num, i;

     // Inicializando a tabela
     for (i = 0; i < tam; i++)
          tabela[i] = NULL;

     do {
          system("cls");
          cout << "\nMENU DE OPCOES\n";
          cout << "\n1 - Inserir na elemento";
          cout << "\n2 - Mostrar tabela hashing";
          cout << "\n3 - Excluir elemento";
          cout << "\n4 - Sair";
          cout << "\nDigite sua opção: ";
          cin >> op;

          if (op < 1 || op > 4)
               cout << "\nOpção inválida! ";
          else {
               switch (op) {
                    case 1:
                         cout << "\nDigite um número: ";
                         cin >> num;
                         pos = funcao_hashing(num);
                         inserir (tabela, pos, num);
                         break;
                    case 2:
                         mostrar_hash(tabela);
                         getchar();
                         break;
                    case 3:
                    cout << "\nDigite um número: ";
                    cin >> num;
                    excluir_hash(tabela, num);
                    break;
               }
          }

     } while (op != 4);

     // Desalocando memoria
     for (i = 0; i < tam; i++){
          while (tabela[i] ! NULL) {
               aux = tabela[i];
               tabela[i] = tabela[i]->prox;
               delete aux;
          }
          tabela[i] = NULL;
     }
     return 0;
}
