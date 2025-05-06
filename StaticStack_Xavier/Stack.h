#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Tamanho máximo da pilha

typedef struct {
    void* items[MAX_SIZE];  // Array genérico
    int top;                // Índice do topo
    size_t memoryUsed;      // Memória total alocada
} StaticStack;

// Definição das funções
StaticStack* createStack();
void destroyStack(StaticStack* stack);
bool push(StaticStack* stack, void* data, size_t dataSize);
void* pop(StaticStack* stack);
bool isEmpty(StaticStack* stack);
void printStack(StaticStack* stack, void (*printFunc)(void*));
void printChar(void* data);

#endif

