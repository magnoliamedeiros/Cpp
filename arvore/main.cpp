#include <cstdlib>
#include <iostream>
#include <string.h>

#include "bst.h"

using namespace std;

int main(){

     bst<int> T;

     T.insert(new node<int>(5, 5));
     T.insert(new node<int>(2, 2));
     T.insert(new node<int>(1, 1));
     T.insert(new node<int>(3, 3));
     T.insert(new node<int>(4, 4));
     T.insert(new node<int>(7, 7));
     T.insert(new node<int>(6, 6));
     T.insert(new node<int>(9, 9));

     cout << T.root->key << endl; // Chave da raiz
     //
     // if (T.search(T.root, 5) != nullptr){
     //      cout << "Achou" << endl;
     // } else {
     //      cout << "Não achou" << endl;
     // }

     int cont = 0;
     T.search(T.root, 5, cont);
     cout << "cont = " << cont << endl;

     // Aula 13 nov 2018
     // T.inOrder(T.root);
     // cout << endl; // Quebrando a linha
     // T.remove(T.search(T.root, 4)); // Removendo o 4
     // T.inOrder(T.root);
     // cout << endl << T.root->key << endl;

     // 3º Caso - Removendo o 5
     // T.inOrder(T.root);
     // cout << endl; // Quebrando a linha
     // T.remove(T.search(T.root, 5)); // Removendo o 4
     // T.inOrder(T.root);
     // cout << endl << T.root->key << endl;

     // 1º Caso - Removendo o 1
     // T.inOrder(T.root);
     // cout << endl; // Quebrando a linha
     // T.remove(T.search(T.root, 1)); // Removendo o 4
     // T.inOrder(T.root);
     // cout << endl << T.root->key << endl;

     // 2º Caso - Removendo o 3
     // T.inOrder(T.root);
     // cout << endl; // Quebrando a linha
     // T.remove(T.search(T.root, 3)); // Removendo o 4
     // T.inOrder(T.root);
     // cout << endl << T.root->key << endl;

     return 0;
}
