#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data){
    if (root == NULL){
        return createNode(data);
    }
    if (data < root->data){
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}

void printTree(Node *root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}



int main(int argc, char const *argv[])
{
    Node* root = NULL;

    root = insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 9);
    insertNode(root, 6);
    insertNode(root, 8);
    insertNode(root, 1);
    insertNode(root, 4);

    printf("Tree Order: ");
    printTree(root);
    printf("\n");
    return 0;
}
