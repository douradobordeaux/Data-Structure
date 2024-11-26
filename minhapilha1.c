#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* Next; 
} Node;

typedef struct stack {
    Node* top;
} Stack;

Stack initializeStack(){
    Stack p;
    p.top = NULL;
    return p;
}

Node* createNode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->Next = NULL;
    return newnode;
}

Stack push(Stack p, int data){
    Node *newnode = createNode(data);
    newnode->Next = p.top; 
    p.top = newnode;
    return p;
}

Stack pop(Stack p, int *data){
    if (p.top != NULL){
        Node *temp = p.top;
        *data = temp->data;
        p.top = temp->Next;
        free(temp);
        return p;
    }
    printf("Erro\n");
    return p;
}

int top(Stack p){
    if (p.top == NULL){
        printf("A pilha está vazia.\n");
        return -1;
    }
    return p.top->data;
}

int main(){

    Stack p = initializeStack();

    p = push(p, 40);
    p = push(p, 1);
    p = push(p, 69);

    printf("O topo da lista é: %d\n", top(p));

    int popped;
    p = pop(p, &popped);

    
    printf("O elemento retirado foi: %d, portanto: \n", popped);
    printf("O topo da lista é: %d", top(p));
    return 0;
}