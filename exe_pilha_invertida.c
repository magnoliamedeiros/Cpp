#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct stack {
    int qnt;
    int dados[MAX];
}Stack;

Stack* criar() {
    Stack *p = malloc(sizeof(Stack));
    if (p != NULL) {
        p->qnt = 0;
    }
    return p;
}
void inserir(Stack *p, int valor) {
    p->dados[p->qnt] = valor;
    p->qnt++;
}
void exibir(Stack *p) {
    for (int i = 0; i < p->qnt; i++)
        printf("%3d", p->dados[i]);
}
Stack* inverter(Stack *p) {
    Stack *outra = criar();
    while (p->qnt > 0) {
        outra->dados[outra->qnt] = p->dados[p->qnt - 1];
        p->qnt--;
        outra->qnt++;
    }
    return outra;
}
int main() {
    Stack *p = criar();
    inserir(p, 30);
    inserir(p, 45);
    inserir(p, 75);
    exibir(p);
    p = inverter(p);
    printf("\n");
    exibir(p);

    return 0;
}
