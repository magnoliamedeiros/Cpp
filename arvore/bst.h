#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

template <typename T>
struct node {
     int cont;
     int key;
     T value; // Dado satélite
     node<T>* parent;  // ponteiro para o pai
     node<T>* left; // ponteiro para o filho esquerdo
     node<T>* right; // ponteiro para o filho direito

     // Construtor
     node(int key, T value){
          this->key = key;
          this->value = value;
          this->left = nullptr;
          this->right = nullptr;
          this->parent = nullptr;
     }
};

template <typename T>
struct bst {
     node<T>* root = nullptr;
     int h = 0; // Inicialmente quando a árvore e criada a altura é zero

     // INSERÇÃO
     void insert(node<T>* x, &cont) {
          node<T>* y = nullptr;
          node<T>* z = root;
          while (z != nullptr) {
               cont++;
               y = z;
               if (x->key <= z->key)
                    z = z->left;
               else
                    z = z->right;
          }
          x->parent = y;
          if (y == nullptr)
               root = x;
          else
               if (x->key <= y->key)
                    y->left = x;
               else
                    y->right = x;
    }

     // BUSCA
     node<T>* search(node<T>* x, int k, int &cont){
          if(x == nullptr || x->key == k){
               return x;
          } else {
               if (k < x->key){
                    search(x->left, k, cont);
                    cont ++;
               } else {
                    search(x->right, k, cont);
                    cont ++;
               }
          }
     }

     // AULA: 09 nov 2018
    node<T>* minimum(node<T>* x){
    	while (x->left != nullptr){
    		x = x->left;
    	}
    	return x;
    }

    node<T>* maximum(node<T>* x){
    	while (x->right != nullptr){
    		x = x->right;
    	}
    	return x;
    }

    // SUCESSOR
    node<T>* sucessor(node<T>* x){
    	if (x->right != nullptr){
    		return minimum(x->right);
    	}
    	node<T>* y = x->parent;
    	while (y != nullptr && x == y->right){
    		x = y;
    		y = x->parent;
    	}
    	return y;
    }

    // PREDECESSOR
    node<T>* predecessor(node<T>* x){
    	if (x->left != nullptr){
    		return maximum(x->left);
    	}
    	node<T>* y = x->parent;
    	while (y != nullptr && x == y->left){
    		x = y;
    		y = x->parent;
    	}
    	return y;
    }

    // Aula 13 nov 2018
    // REMOVE
    node<T>* remove(node<T>* x){
         node<T>* y = nullptr;
         node<T>* z = nullptr;

         if(x->right == nullptr || x->left == nullptr){
              y = x; // 1º ou 2º caso
         } else {
              y = sucessor(x); // 3º caso
         }

         if(y->left != nullptr){
              z = y->left;
         } else {
              z = y->right;
         }

         if(z != nullptr){
              z->parent = y->parent;
         }

         if(y->parent == nullptr){
              this->root = z;
         } else {
              if(y == y->parent->left){ // Se y for filho da esquerda
                   y->parent->left = z;
              } else {
                   y->parent->right = z;
              }
         }

         if(x != y){
              x->key = y->key;
              x->value = y->value;
         }
         return y;
    }

    // Exercício INDORDER - Impressão da árvore em ordem crescente
    void inOrder(node<T>* x){
         if(x != nullptr){
              inOrder(x->left);
              cout << x->key << " ";
              inOrder(x->right);
         }
    }
};

#endif /*BST_H*/
