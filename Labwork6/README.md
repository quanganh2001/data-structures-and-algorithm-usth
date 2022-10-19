A binary tree can be used to sort n elements of an array data. First, create a complete binary tree, a tree with all leaves at one level, whose height h = (lg n) + 1, and store all elements of the array in the first n leaves. In each empty leaf, store an element E greater than any element in the array.

Figure (a) shows an example for data = 8, 20, 41, 7, 2, h = (lg(5)) + 1 = 4, and E = 42. 

[![image.png](https://i.postimg.cc/RCQJYZQS/image.png)](https://postimg.cc/fkybtZrp)

Then, starting from the bottom of the tree, assign to each node the minimum of its two children values, as in Figure (b), so that the smallest element e_{min} n in the tree is assigned to the root.

[![image.png](https://i.postimg.cc/kgDVDFrG/image.png)](https://postimg.cc/FY5FBSHX)

If a leaf node is to be removed, this node is replaced by a new node with the same value of its parent node.

If a node is added into the tree, it will be a leaf node. Normally a node with value E is replaced with new value. It's necessary to verify recursively all values of its parent and make any possible modification if necessary so that the tree rules are respected.

Implement this tree structure in C/C++ with the necessary functions.

- Write a function to initialize an array with n random values
- Write a function to build this binary tree with the above definition with any data structure learn in lectures.
- Write a function to display the tree information
```c
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
#include <malloc.h>
#include <math.h>
#define SPACE 10 // define a number using in formatting the image of the tree

// There is a note at the end of the program, please check it carefully.

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree = NULL; // initialize the tree
void program(); // main program is here
void sort(int arr[], int); // sort the input array using bubble sort
struct node *create_tree(int arr[], int, int); // build the internal nodes and leaf nodes using recursive method
void display(struct node *, int); // print out the picture of the tree
void preorderTraversal(struct node*);

int main() {
    printf("\n\t*********BINARY SEARCH TREE PROGRAM*********");
    printf("\nCreated: Nguyen Quang Anh - BA10-002 - Group 1");
    program();
    return 0;
}

void program() {
    /* INITIALIZE THE INPUT */
    // 1. ask user to enter the input
    int i = 0, n, num;
    int arr[100];
    printf("\n\n***Enter number of elements: "); scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter a[%d]: ", i); scanf("%d", &arr[i]);
    }
    sort(arr, n);
    printf("---->Your input: ");
    for(int j = 0; j < n; j++) {
        printf(" %d ", arr[j]);
    }

    // 2. Calculate the number of leaf nodes then add more leaf nodes
    // that have value equal to the maximum of the array
    printf("\n\n***Calculate the number of leaf nodes:");
    int h = round(log(n) / log(2)); // mathematically, log2(n) = log(n) / log(2)
    int numLeaf = pow(2,h);
    int max = arr[i-1];
    printf("\n\t\th = round_up(log2(%d)) = %d", n, h);
    printf("\n\tNumber of leaf nodes = 2^h = %d", numLeaf);

    int count; // final number of elements of the final array
    if (numLeaf >= n) {
        count = numLeaf;
        for(i = n - 1; i < numLeaf; i++) { // add more number
            arr[i] = max;
        }
    }
    else {
        count = n;
    }
    printf("\n---->So we need to add %d node(s) more.", count - n);

    // 3. print out the final array to confirm
    printf("\n---->The final array is: [");
    for (int j = 0; j < count; j++) {
        printf(" %d ", arr[j]);
    }
    printf("]");


    // Create the binary search tree based on the final input
    tree = create_tree(arr, 0, count/2);


    // Print out the diagram of the tree
    printf("\n\n***START PRINTING OUT THE TREE");
    printf("\n(The picture of the tree is rotated 90 degrees counter-clockwise)\n");
    display(tree, 0);


    // Print out the inorder traversal
    printf("\n***Preorder Traversal: ");
    preorderTraversal(tree);
}

void sort(int arr[], int n) { // bubble sort algorithm
    int i, j;
    int temp;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

struct node *create_tree(int arr[], int index, int length) {
    // create the root
    struct node *tree = (struct node *)malloc(sizeof(struct node));
    tree -> data = arr[index + length - 1];

    // base case
    if (length == 1) {
        // add left node to an internal node
        tree -> left = (struct node *)malloc(sizeof(struct node));
        tree -> left -> data = arr[index];
        tree -> left -> left = tree -> left -> right = NULL;
        // add right node to an internal node
        tree -> right = (struct node *)malloc(sizeof(struct node));
        tree -> right -> data = arr[index + 1];
        tree -> right -> left = tree -> right -> right = NULL;
        return tree;
    }
    // recursively create both left and right subtree from root.
    struct node *leftSubtree = create_tree(arr, index, length/2);
    struct node *rightSubtree = create_tree(arr, index + length, length/2);
    tree -> left = leftSubtree;
    tree -> right = rightSubtree;

    return tree;
}

void display(struct node *ptr, int space) {
    // Base case
    if (ptr == NULL)
        return;
    // Increase distance between levels
    space += SPACE;

    // Process right child first
    display(ptr -> right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = SPACE; i < space; i++)
        printf(" ");
    printf("%d\n", ptr -> data);

    // Process left child
    display(ptr -> left, space);
}

void preorderTraversal(struct node *ptr) {
    if (ptr != NULL) {
        printf("%d ", ptr -> data);
        preorderTraversal(ptr -> left);
        preorderTraversal(ptr -> right);
    }
}
```
Output:
```txt
        *********BINARY SEARCH TREE PROGRAM*********
Created: Nguyen Quang Anh - BA10-002 - Group 1

***Enter number of elements: 6
Enter a[0]: 1
Enter a[1]: 2
Enter a[2]: 4
Enter a[3]: 8
Enter a[4]: 12
Enter a[5]: 14
---->Your input:  1  2  4  8  12  14 

***Calculate the number of leaf nodes:
                h = round_up(log2(6)) = 3
        Number of leaf nodes = 2^h = 8
---->So we need to add 2 node(s) more.
---->The final array is: [ 1  2  4  8  12  14  14  14 ]

***START PRINTING OUT THE TREE
(The picture of the tree is rotated 90 degrees counter-clockwise)

                              14

                    14

                              14

          14

                              14

                    12


8

                              8

                    4

                              4

          2

                              2

                    1

                              1

***Preorder Traversal: 8 2 1 1 2 4 4 8 14 12 12 14 14 14 14
```
# Solution from Chegg
```c
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
```
The result is the tree is not balanced.