// INCOMPLETED


#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *left, *right; 
} Node;

typedef struct binaryTree{
    Node *root;
} bTree;

void insertLeft(Node *node, int value){
    if(node->left==NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        node->left = newNode;
    }
    else{
        if (value < node->left->data){
            insertLeft(node->left, value);
        }
        else{
            insertRight(node->left, value);
        }
    }
}
void insertRight(Node *node, int value){
    if(node->right==NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        node->right = newNode;
    }
    else{
        if (value < node->right->data){
            insertLeft(node->left, value);
        }
        else {
            insertRight(node->right, value);
        }
    }
}

void insertNode(bTree *tree, int value){
    if(tree->root == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        tree->root = newNode;
    }
    else{
        if (value < tree->root->data){
            insertLeft(tree->root, value);
        }
        else{
            insertRight(tree->root, value);
        }
    }
}

void printTree(Node *root){
    if (root != NULL){
        printf("%d", root->data);
    }
}

int main()
{
    return 0;
}

