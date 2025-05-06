#include "Stack.h"

// Criando pilha
DynamicStack* createStack(){
    DynamicStack* stack = (DynamicStack*)malloc(sizeof(DynamicStack));
    if(!stack){
        perror("Erro ao alocar memória para a pilha!");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    stack->size = 0;
    stack->memoryUsed = sizeof(DynamicStack);
    return(stack);
}

// Destruindo pilha
void destroyStack(DynamicStack* stack){
    Node* current = stack->top;
    while(current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    free(stack);
}

// Empilhando
bool push(DynamicStack* stack, void* data, size_t dataSize){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        perror("Erro ao alocar memória para a pilha!");
        return(false);
    }
    newNode->data = malloc(dataSize);
    if (!newNode->data) {
        free(newNode);
        perror("Erro ao alocar memória para a pilha!");
        return false;
    }

    memcpy(newNode->data, data, dataSize);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    stack->memoryUsed += sizeof(Node) + dataSize;
    return true;
}

// vendo se esta vazia
bool isEmpty(DynamicStack* stack) {
    return stack->top == NULL;
}

// desempilhando
void* pop(DynamicStack* stack) {
    if (isEmpty(stack)) return NULL;

    Node* temp = stack->top;
    void* data = temp->data;
    stack->top = temp->next;
    stack->size--;
    stack->memoryUsed -= sizeof(Node) + sizeof(float); // Ajuste para float
    free(temp);
    return data;
}

void printFloat(void* data) {
    printf("%.2f", *(float*)data);
}

//printando display
void printStack(DynamicStack* stack, void (*printFunc)(void*)) {
    printf("Topo: ");
    if (!isEmpty(stack)) printFunc(stack->top->data);
    else printf("NULL");

    printf("\nTamanho: %zu", stack->size);
    printf("\nMemoria alocada: %zu bytes", stack->memoryUsed);

    printf("\nPilha: ");
    if (isEmpty(stack)) printf("Vazia!");
    else {
        Node* current = stack->top;
        while (current != NULL) {
            printFunc(current->data);
            if (current->next != NULL) printf(" -> ");
            current = current->next;
        }
    }
    printf("\n");
}