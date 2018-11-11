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

     // cout << T.root->key << endl; // Chave da raiz

     // if (T.search(T.root, 4) != nullptr){
     //      cout << "Achou" << endl;
     // } else {
     //      cout << "Não achou" << endl;
     // }

     int tempo = 0;
     T.search(T.root, 10, tempo);
     cout << tempo << endl;

     return 0;
}
