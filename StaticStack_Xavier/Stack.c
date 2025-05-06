#include "Stack.h"
#include <string.h>

// Criando uma pilha
StaticStack* createStack(){
    StaticStack* stack = (StaticStack*)malloc(sizeof(StaticStack));
    if(!stack){
        perror("Erro ao alocar memória para a pilha!");
        exit(EXIT_FAILURE);
    }

    stack->top = -1;
    stack->memoryUsed = sizeof(StaticStack);
    return stack;
}

// Empilhando
bool push(StaticStack* stack, void* data, size_t dataSize){
    if (stack->top >= MAX_SIZE - 1) {
        printf("Erro ao tentar emplilhar um novo elemento, pilha cheia!");
        return false;
    }

    stack->items[++stack->top] = malloc(dataSize);
    if (!stack->items[stack->top]) {
        printf("Erro ao alocar memória para um novo elemento na pilha!");
        return false;}

    memcpy(stack->items[stack->top], data, dataSize);
    stack->memoryUsed += dataSize;
    return true;
}

// Desempilhando
void* pop(StaticStack* stack) {
    if (isEmpty(stack)) return NULL;

    void* data = stack->items[stack->top--];
    stack->memoryUsed -= sizeof(char); 
    return data;
}

// Verificando se a pilha está vázia
bool isEmpty(StaticStack* stack) {
    return stack->top == -1;
}

// Limpando/destruindo a pilha
void destroyStack(StaticStack* stack){
    while (!isEmpty(stack)) {
        free(pop(stack));
    }
    free(stack);
}


void printChar(void* data) {
    printf("%c", *(char*)data);
}

// printando a pilha
void printStack(StaticStack* stack, void (*printFunc)(void*)) {
    printf("Topo: ");
    if (!isEmpty(stack)) printFunc(stack->items[stack->top]);
    else printf("NULL");

    printf("\nTamanho: %d", stack->top + 1);
    printf("\nMemória alocada: %zu bytes", stack->memoryUsed);

    printf("\nPilha: ");
    if (isEmpty(stack)) printf("Vazia!");
    else {
        for (int i = stack->top; i >= 0; i--) {
            printFunc(stack->items[i]);
            if (i > 0) printf(" -> ");
        }
    }
    printf("\n");
}
