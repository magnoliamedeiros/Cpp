#include <iostream>

using namespace std;

// An AVL tree node
struct Node
{
    int cont; // Contador
    int key;
    struct Node *left;
    struct Node *right;
    int height; // altura
};

// A utility function to get maximum of two integers
int max(int a, int b); // Pega o maior número

// A utility function to get the height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node* insert(struct Node* node, int key, int &cont)
{
     /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key) {
        node->left  = insert(node->left, key, cont);
        cont++;
   } else if (key > node->key) {
        node->right = insert(node->right, key, cont);
        cont++;
   } else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search tree, return the
node with minimum key value found in that tree.
Note that the entire tree does not need to be
searched. */
struct Node * minValueNode(struct Node* node)
{
	struct Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}
// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
struct Node* deleteNode(struct Node* root, int key, int &cont)
{
	// STEP 1: PERFORM STANDARD BST DELETE

	if (root == NULL)
		return root;

	// If the key to be deleted is smaller than the
	// root's key, then it lies in left subtree
	if ( key < root->key ){
		root->left = deleteNode(root->left, key, cont);
          cont++;
	// If the key to be deleted is greater than the
	// root's key, then it lies in right subtree
     } else if( key > root->key ) {
		root->right = deleteNode(root->right, key, cont);
          cont++;
	// if key is same as root's key, then This is
	// the node to be deleted
     } else {
		// node with only one child or no child
		if( (root->left == NULL) || (root->right == NULL) )
		{
			struct Node *temp = root->left ? root->left :
											root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			*root = *temp; // Copy the contents of
							// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			struct Node* temp = minValueNode(root->right);

			// Copy the inorder successor's data to this node
			root->key = temp->key;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->key, cont);
		}
	}

	// If the tree had only one node then return
	if (root == NULL)
	return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left),
						height(root->right));

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

struct Node* searchNode(struct Node* node, int key, int &cont){
     cont++;
     if (node == NULL || node->key == key){
          return node;
     } else {
          if ( key < node->key){
               searchNode(node->left, key, cont);
          } else {
               searchNode(node->right, key, cont);
          }
     }
}

     // A utility function to print preorder traversal of
     // the tree.
     // The function also prints height of every node
     void preOrder(struct Node *root)
     {
     	if(root != NULL)
     	{
     		printf("%d ", root->key);
     		preOrder(root->left);
     		preOrder(root->right);
     	}
     }

/* Drier program to test above function*/

int main()
{
  struct Node *root = NULL;
  struct Node *node;
  int cont = 0;

/* Constructing tree given in the above figure */
// root = insert(root, 9, cont);
// root = insert(root, 5, cont);
// root = insert(root, 10, cont);
// root = insert(root, 0, cont);
// root = insert(root, 6, cont);
// root = insert(root, 11, cont);
// root = insert(root, -1, cont);
// root = insert(root, 1, cont);
// root = insert(root, 2, cont);
// cout << "cont insert = " << cont << endl;

  // root = insert(root, 1, cont);
  // root = insert(root, 2, cont);
  // root = insert(root, 3, cont);
  // root = insert(root, 4, cont);
  // root = insert(root, 5, cont);
  // root = insert(root, 6, cont);
  // root = insert(root, 7, cont);
  // root = insert(root, 8, cont);
  // root = insert(root, 9, cont);
  // root = insert(root, 10, cont);
  // root = insert(root, 11, cont);
  // root = insert(root, 12, cont);
  // root = insert(root, 13, cont);
  // root = insert(root, 14, cont);
  // root = insert(root, 15, cont);
  // root = insert(root, 16, cont);
  // root = insert(root, 17, cont);
  // root = insert(root, 18, cont);
  // root = insert(root, 19, cont);
  // root = insert(root, 20, cont);
  // root = insert(root, 21, cont);
  // root = insert(root, 22, cont);
  // root = insert(root, 23, cont);
  // root = insert(root, 24, cont);
  // root = insert(root, 25, cont);
  // root = insert(root, 26, cont);
  // root = insert(root, 27, cont);
  // root = insert(root, 28, cont);
  // root = insert(root, 29, cont);
  // root = insert(root, 30, cont);
  // root = insert(root, 31, cont);
  // root = insert(root, 32, cont);
  // root = insert(root, 33, cont);
  // root = insert(root, 34, cont);
  // root = insert(root, 35, cont);
  // root = insert(root, 36, cont);
  // root = insert(root, 37, cont);
  // root = insert(root, 38, cont);
  // root = insert(root, 39, cont);
  // root = insert(root, 40, cont);
  // root = insert(root, 41, cont);
  // root = insert(root, 42, cont);
  // root = insert(root, 43, cont);
  // root = insert(root, 44, cont);
  // root = insert(root, 45, cont);
  // root = insert(root, 46, cont);
  // root = insert(root, 47, cont);
  // root = insert(root, 48, cont);
  // root = insert(root, 49, cont);
  // cont = 0;
  // root = insert(root, 10, cont);
  // cout << "cont insert = " << cont << endl;

     for (int i = 1; i < 5; i++) {
         root = insert(root, i, cont);
     }

     cout << "Inserindo..." << endl;
     cont = 0;
     root = insert(root, 5, cont);
     printf("Preorder\n");
     preOrder(root);
     cout << "\nTempo 'insert' = " << cont << endl;

     cout << "\n" << endl;

     cout << "Buscando a chave 4..." << endl;
     cont = 0;
     cout << "Chave "  << searchNode(root, 4, cont)->key << " encontrada." << endl;
     cout << "Tempo 'search' = " << cont << endl;

     cout << "\n" << endl;

     cout << "Deletando a chave 5..." << endl;
     cont = 0;
     root = deleteNode(root, 5, cont);
     cout << "Tempo 'delete' = " << cont << endl;
     printf("Preorder\n");
	preOrder(root);

     return 0;
}
