// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
// C program to demonstrate delete operation in binary search tree

struct node
{
     int cont; // Contador
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key, int &cont)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key){
		node->left = insert(node->left, key, cont);
          cont++;
	} else {
		node->right = insert(node->right, key, cont);
          cont++;
     }
	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
struct node * minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

/* Given a binary search tree and a key, this function deletes the key
and returns the new root */
struct node* deleteNode(struct node* root, int key, int &cont)
{
	// base case
	if (root == NULL) return root;

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (key < root->key){
		root->left = deleteNode(root->left, key, cont);
          cont++;
	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
     } else if (key > root->key){
		root->right = deleteNode(root->right, key, cont);
          cont++;
	// if key is same as root's key, then This is the node
	// to be deleted
     } else {
		// node with only one child or no child
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key, cont);
	}
	return root;
}

// C function to search a given key in a given BST
struct node* search(struct node* root, int key, int &cont)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;

    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key, cont);
       cont++;

    // Key is smaller than root's key
    return search(root->left, key, cont);
}

// Driver Program to test above functions
int main()
{

	struct node *root = NULL;
     int cont = 0;

	root = insert(root, 1, cont);
	root = insert(root, 2, cont);
	root = insert(root, 3, cont);
	root = insert(root, 4, cont);
	root = insert(root, 5, cont);
	root = insert(root, 6, cont);
	root = insert(root, 7, cont);

     printf("Inorder traversal of the given tree \n");
	inorder(root);

     cont = 0;
  	printf("\nSearch o 7\n");
     if (search(root, 7, cont) != NULL) {
          cout << "Achou!" << endl;
          cout << "\ncont 'search' = " << cont << endl;
     } else {
          cout << "Não achou" << endl;
          cout << "\ncont 'search' = " << cont << endl;
     }

	// printf("Inorder traversal of the given tree \n");
	// inorder(root);
     //
     // cont = 0;
	// printf("\nDelete o 2\n");
	// root = deleteNode(root, 2, cont);
	// printf("Inorder traversal of the modified tree \n");
     // inorder(root);
     // cout << "\ncont 'delete' = " << cont << endl;

	// printf("\nDelete 3\n");
	// root = deleteNode(root, 3, cont);
	// printf("Inorder traversal of the modified tree \n");
	// inorder(root);
     //
	// printf("\nDelete 5\n");
	// root = deleteNode(root, 5, cont);
	// printf("Inorder traversal of the modified tree \n");
	// inorder(root);

	return 0;
}
