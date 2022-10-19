/* A binary tree can be used to sort n elements of an array data. First, create a complete binary tree, a tree with all leaves at one level, whose height h = (lg n) + 1, and store all elements of the array in the first n leaves. In each empty leaf, store an element E greater than any element in the array.*/

// Figure (a) shows an example for data = 8, 20, 41, 7, 2, h = (lg(5)) + 1 = 4, and E = 42. Then, starting from the bottom of the tree, assign to each node the minimum of its two children values, as in Figure (b), so that the smallest element e_{min} n in the tree is assigned to the root.

// If a leaf node is to be removed, this node is replaced by a new node with the same value of its parent node.

// If a node is added into the tree, it will be a leaf node. Normally a node with value E is replaced with new value. It's necessary to verify recursively all values of its parent and make any possible modification if necessary so that the tree rules are respected.

/* Implement this tree structure in C/C++ with the necessary functions.
- Write a function to initialize an array with n random values
- Write a function to build this binary tree with the above definition with any data structure learn in lectures.
- Write a function to display the tree information
*/
#include <stdio.h>
#include <stdlib.h>
#define bool int

/* A binary tree node has data, pointer to left child and a pointer to right child */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Returns the height of a binary tree
int height(struct node* node);

// Returns true if binary tree with root as root is height-balanced
bool isBalanced(struct node *root)
{
    int lh; // for height of left subtree
    int rh; // for height of right subtree

    // If tree is empty then return true
    if(root == NULL)
        return 1;
    
    // Get the height of left and right sub trees
    lh = height(root->left);
    rh = height(root->right);

    if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    
    // If we reach here then tree is not height-balanced
    return 0;
}

/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

// returns maximum of two integers
int max(int a, int b)
{
    return (a >= b)? a: b;
}

/* The function Complete the "height" of a tree. Height is the 
number of nodes along the longest path from the root node down
to the farthest leaf node.*/
int height(struct node* node)
{
    // base case tree is empty
    if(node == NULL)
        return 0;
    
    // If tree is not empty then height = 1 + max of left height and right heights
    return 1 + max(height(node->left), height(node->right));
}

/* Helper function that allocates a new node with the given data and NULL left and right pointers */
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if(isBalanced(root))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");
    
    getchar();
    return 0;
}