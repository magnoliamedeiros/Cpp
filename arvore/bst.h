#ifndef BST_H
#define BST_H

template <typename T>
struct node {
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
     void insert(node<T>* x) {
          node<T>* y = nullptr;
          node<T>* z = root;
          while (z != nullptr) {
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
     node<T>* search(node<T>* x, int k, int& tempo){
          tempo++;
          if(x == nullptr || x->key == k){
               return x;
          } else {
               if (k < x->key){
                    search(x->left, k, tempo);
               } else {
                    search(x->right, k, tempo);
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
};

#endif /*BST_H*/
