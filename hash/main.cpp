#include <cstdlib>
#include <iostream>
#include <string.h>

#include "hashtable.h"

using namespace std;

struct pessoa{
     string nome;
     int idade;

     pessoa(){}

     pessoa(string nome, int idade){
          this->nome = nome;
          this->idade = idade;
     }
};

int main(){

     pessoa kallyne("Kallyne", 18);
     pessoa yuri("Yuri", 22);
     pessoa clizio("Clizio", 24);

     hashtable<pessoa> H(3);
     H.hash_insert(kallyne.idade, kallyne);
     H.hash_insert(yuri.idade, yuri);
     H.hash_insert(clizio.idade, clizio);

     for (int i=0; i < H.m; i++){
          cout << (i+1) << " = ";
          l<pessoa>* x =H.T[i].head;
          while (x != nullptr){
               cout << x->value.nome << " ";
               cout << x->valeu.idade << " | ";
               x = x->next;
          }
          cout << endl;
     }

     return 0;
}
