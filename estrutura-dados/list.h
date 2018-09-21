#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

template <typename T> // Para trabalhar com tipo genérico

struct l {
     T key; // é o valor do elemento
     l<T>* next;
     l(T key){ // Função construtora
          this->key = key;
          next = nullptr;
     }
};

template <typename T>

struct list {
     l<T>* head;
     int size; // Manter o controle do tamanho

     list(){
          head = nullptr;
          size = 0;
     }
     l<T>* search(T k){
          l<T>* x = head;
          while (x != nullptr && x->key !=k){
               x = x->next;
          }
          return x;
     }
     void insert (l<T>* x){
          x->next = head;
          head = x;
          size++;
     }
     void remove (T k){ // Vai passar a chave
          if (size != 0){
               if(head->key == k){ // Caso especial
                    l<T>* temp = head;
                    head = head->next;
                    size--;
                    delete temp; // Destrói o ponteiro
               } else { // Caso geral
                    l<T>* x = head;
                    while (x != nullptr){
                         if (x->next->key == k){
                              l<T>* temp = x->next;
                              x->next = x->next->next;
                              delete temp;
                              size--;
                              return;
                         }
                         x = x->next;
                    }
               }
          }
     }
     void print() { // Operação bonus!
          l<T>* x = head;
          while (x != nullptr){
               cout << x->key << " ";
               x = x->next; // Passa para o próximo
          }
          cout << endl;
     }
};
#endif /* LIST_H */
