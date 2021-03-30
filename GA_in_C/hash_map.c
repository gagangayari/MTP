#include<stdio.h>
#include<stdlib.h>
#include"ga.h"

 
// An AVL tree node
struct Node
{
    unsigned int key;
    struct Node *left;
    struct Node *right;
    int height;
};
 
// A utility function to get maximum of two integers
unsigned int max(unsigned int a,unsigned int b);
 
// A utility function to get the height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
unsigned int max(unsigned int a,unsigned int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(unsigned int key)
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
struct Node* insert(struct Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        /*{if(key%2 ==0){
            printf("Even \n");

        }
        else{
            printf("Odd \n");

        }
        }
        */
        // printf("equal nodes : %d\n",key);
        // count_repeat++;
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

int search(unsigned int val,struct Node *head){
    if( head ==NULL){
        return 0;
    }
    if(head->key == val){
        return 1;

    }
    else if(head->key >val){
        return search(val,head->left);

    }

    else{
        return search(val,head->right);


    }

}

void disp_map(struct Node *head){
  if(head ==NULL){
    return;
  }
  disp_map(head->left);
  printf("%lu \t",head->key);
  disp_map(head->left);
  printf("\n");

}

void print_inorder(struct Node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%lu\n",tree->key);
        print_inorder(tree->right);
    }
}

int count_nodes(struct Node *tree)
{
    int c =  1;             //Node itself should be counted
    if (tree ==NULL)
        return 0;
    else
    {
        c += count_nodes(tree->left);
        c += count_nodes(tree->right);
        return c;
    }
}


/*int main(){
    struct Node* map =NULL;
    map =insertNode(map,4);
    map =insertNode(map,2);
    map =insertNode(map,5);
    map =insertNode(map,6);
    if(search(0,map)){
        printf("Present \n");

    }
    else{
        printf("Not Present \n");
    }
    
    
    
    

    return 0;
}
*/

