#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

// Definindo o registro que representará cada elemento da árvore AVL
struct ARVORE {
          int num, alt_d, alt_e;
          ARVORE *dir, *esq;
};

ARVORE* rotacao_esquerda (ARVORE* aux)
{
     ARVORE *aux_1, *aux_2;
     aux_1 = aux->dir;
     aux_2 = aux->esq;
     aux->dir = aux_2;
     aux_1->esq = aux;
     if (aux->dir == NULL)
          aux->alt_d = 0;
     else if (aux->dir->alt_e > aux->dir->alt_d)
          aux->alt_d = aux->dir->alt_e + 1;
     else
          aux->alt_d = aux->dir->alt_d + 1;

     if (aux_1->esq->alt_e > aux_1->esq->alt_d)
          aux_1->alt_e = aux_1->esq->alt_e + 1;
     else
          aux_1->alt_e = aux_1->esq->alt_d + 1;
     return aux_1;
}

ARVORE* rotacao_direita (ARVORE* aux)
{
     ARVORE *aux_1, *aux_2;
     aux_1 = aux->esq;
     aux_2 = aux_1->dir;
     aux->esq = aux_2;
     aux_1->dir = aux;
     if (aux->esq == NULL)
          aux->alt_e = 0;
     else if (aux->esq->alt_e > aux->esq->alt_d)
          aux->alt_e = aux->esq->alt_e + 1;
     else
          aux->alt_e = aux->esq->alt_d + 1;
     if (aux_1->dir->alt_e > aux_1->dir->alt_d)
          aux_1->alt_d = aux_1->dir->alt_e + 1;
     else
          aux_1->alt_d = aux_1->dir->alt_d + 1;
     return aux_1;
}

ARVORE* balanceamento (ARVORE *aux)
{
     int d, df;
     d = aux->alt_d - aux->alt_e;
     if (d == 2)
     {
          df = aux->dir->alt_d - aux->dir->alt_e;
          if (df >= 0)
          {
               aux = rotacao_esquerda(aux);
          }
          else
          {
               aux->dir = rotacao_direita(aux->dir);
               aux = rotacao_esquerda(aux);
          }
     }
     else if (d == -2)
     {
          df = aux->esq->alt_d - aux->esq->alt_e;
          if (df <= 0)
          {
               aux = rotacao_direita(aux);
          }
          else
          {
               aux->esq = rotacao_esquerda(aux->esq);
               aux = rotacao_direita(aux);
          }
     }
     return aux;
}

// Inserir
ARVORE* inserir (ARVORE *aux, int num)
{
     // O objeto novo é um objeto auxiliar
     ARVORE *novo;
     if (aux == NULL)
     {
          novo = new ARVORE();
          novo->num = num;
          novo->alt_d = 0;
          novo->alt_e = 0;
          novo->esq = NULL;
          novo->dir = NULL;
          aux = novo;
     }
     else if (num < aux->num)
     {
          aux->esq = inserir(aux->esq, num);
          if (aux->esq->alt_d > aux->esq->alt_e)
               aux->alt_e = aux->esq->alt_d + 1;
          else
               aux->alt_e = aux->esq->alt_e + 1;
          aux = balanceamento(aux);
     }
     else
     {
          aux->dir = inserir(aux->dir, num);
          if (aux->dir->alt_d > aux->dir->alt_e)
               aux->alt_d = aux->dir->alt_d + 1;
          else
               aux->alt_d = aux->dir->alt_e + 1;
          aux = balanceamento(aux);
     }
     return aux;
}

// Consultar
int consultar (ARVORE* aux, int num, int achou)
{
     if (aux != NULL && achou == 0)
     {
          if (aux->num == num)
               achou = 1;
          else if (num < aux->num)
               achou = consultar(aux->esq, num, achou);
          else
               achou = consultar(aux->dir, num, achou);
          }
          return achou;
     }

// Mostrar em ordem
void mostrar_em_ordem (ARVORE* aux) {
     if (aux != NULL) {
          mostrar_em_ordem(aux->esq);
          cout << aux->num << " ";
          mostrar_em_ordem(aux->dir);
     }
}

// Mostrar pré-ordem
void mostrar_pre_ordem (ARVORE* aux) {
     if (aux != NULL) {
          cout << aux->num << " ";
          mostrar_pre_ordem(aux->esq);
          mostrar_pre_ordem(aux->dir);
     }
}

// Mostrar pós-ordem
void mostrar_pos_ordem (ARVORE* aux) {
     if (aux != NULL) {
          mostrar_pos_ordem(aux->esq);
          mostrar_pos_ordem(aux->dir);
          cout << aux->num << " ";
     }
}

// Remover
ARVORE* remover (ARVORE* aux, int num)
{
     ARVORE *p, *p2;
     if (aux->num == num)
     {
          if (aux->esq == aux->dir)
          {
               // o elemento a ser removido não tem filhos
               delete aux;
          return NULL;
     }
     else if (aux->esq == NULL)
     {
          // o elemento a ser removido não tem filhos para a esquerda
          p = aux->dir;
          delete aux;
          return p;
     }
     else if (aux->dir == NULL)
     {
          // o elemento a ser removido não tem filho para a direita
          p = aux->esq;
          delete aux;
          return p;
     }
     else
     {
          // o elemento a ser removido tem filhos para ambos os lados
          p2 = aux->dir;
          p = aux->dir;
          while (p->esq != NULL)
          {
               p = p->esq;
          }
          p->esq = aux->esq;
          delete aux;
          return p2;
          }
     }
     else if (aux->num < num)
          aux->dir = remover(aux->dir, num);
     else
          aux->esq = remover(aux->esq, num);
     return aux;
}

// Atualizar
ARVORE* atualizar (ARVORE *aux) {
     if (aux != NULL) {
          aux->esq = atualizar(aux->esq);
          if (aux->esq == NULL)
               aux->alt_e = 0;
          else if (aux->esq->alt_e > aux->esq->alt_d)
               aux->alt_e = aux->esq->alt_e + 1;
          else
               aux->alt_e = aux->esq->alt_d + 1;
          aux->dir = atualizar(aux->dir);
          if (aux->dir == NULL)
               aux->alt_d = 0;
          else if (aux->dir->alt_e > aux->dir->alt_d)
               aux->alt_d = aux->dir->alt_e + 1;
          else
               aux->alt_d = aux->dir->alt_d + 1;
          aux = balanceamento(aux);
     }
     return aux;
}

// Desalocar
ARVORE* desalocar (ARVORE* aux) {
     if (aux != NULL) {
          aux->esq = desalocar(aux->esq);
          aux->dir = desalocar(aux->dir);
          delete aux;
     }
     return NULL;
}

int main() {
     // A árvore está vazia, logo, o ponteiro raiz tem valor NULL
     ARVORE *raiz = NULL;

     // O ponteiro aux é um ponteiro auxiliar
     ARVORE *aux;

     // O ponteiro aux_1 é um ponteiro auxiliar
     int op, achou, numero;

     do {
          // clrscr();
          system("cls");
          cout << "\nMENU DE OPCOES\n";
          cout << "\n1 - Inserir na arvore";
          cout << "\n2 - Consultar um no da arvore";
          cout << "\n3 - Consultar toda a arvore em ordem";
          cout << "\n4 - Consultar toda a arvore em pre-ordem";
          cout << "\n5 - Consultar toda a arvore em pos-ordem";
          cout << "\n6 - Excluir um no da arvore";
          cout << "\n7 - Esvaziar a arvore";
          cout << "\n8 - Sair";
          cout << "\nDigite sua opcao: ";
          cin >> op;
          if (op < 1 || op > 8)
               cout << "\nOpcao invalida!!";
          else if (op == 1)
          {
          cout << "\nDigite o numero a ser inserido na arvore: ";
          cin >> numero;
          raiz = inserir(raiz, numero);
          cout << "\nNumero inserido na arvore!!";
          }
          else if (op == 2)
          {
               if (raiz == NULL)
               {
                    // a arvore esta vazia
                    cout << "\nArvore vazia!!";
               }
               else
               {
                    // a arvore contem elementos
                    cout << "\nDigite o elemento a ser consultado: ";
                    cin >> numero;
                    achou = 0;
                    achou = consultar(raiz, numero, achou);
                    if (achou == 0)
                         cout << "\nNumero nao encontrado na arvore!!";
                    else
                         cout << "\nNumero encontrado na arvore!!";
                    }
               }
               else if (op == 3)
               {
                    if (raiz == NULL)
                    {
                         // a arvore esta vazia
                         cout << "\nArvore vazia!!";
                    }
                    else
                    {
                         // a arvore contem elementos e estes serao mostrados em ordem
                         cout << "\nListando todos os elementos da arvore em ordem: ";
                         mostrar_em_ordem(raiz);
                    }
               }
               else if (op == 4)
               {
                    if (raiz == NULL)
                    {
                         // a arvore esta vazia
                         cout << "\nArvore vazia!!";
                    }
                    else
                    {
                         // a arvore contem elementos e estes serao mostrados em pre-ordem
                         cout << "\nListando todos os elementos da arvore em pre-ordem: ";
                         mostrar_pre_ordem(raiz);
                    }
               }
               else if (op == 5)
               {
                    if (raiz == NULL)
                    {
                         // a arvore esta vazia
                         cout << "\nArvore vazia!!";
                    }
                    else
                    {
                         // a arvore contem elementos e estes serao mostrados em pos-ordem
                         cout << "\nListando todos os elementos da arvore em pos-ordem: ";
                         aux = raiz;
                         mostrar_pos_ordem(aux);
                    }
          }
          else if (op == 6)
          {
               if (raiz == NULL)
                    cout << "\nArvore vazia!!";
               else
               {
                    cout << "\nDigite o numero que deseja excluir: ";
                    cin >> numero;
                    achou = 0;
                    achou = consultar(raiz, numero, achou);
                    if (achou == 0)
                         cout << "\nNumero nao encontrado na arvore!!";
                    else
                         {
                              raiz = remover(raiz, numero);
                              raiz = atualizar(raiz);
                              cout << "\nNumero excluido da arvore!!";
                         }
                    }
               }
          else if (op == 7)
          {
               if (raiz == NULL)
                    cout << "\nArvore vazia!!";
               else
               {
                    raiz = desalocar(raiz);
                    cout << "\nArvore esvaziada!!";
               }
          }
          //getch();
          getchar();
     }
     while(op != 8);
          // desalocando a arvore
          raiz = desalocar(raiz);
}
