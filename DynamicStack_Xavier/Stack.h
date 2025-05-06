#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node{
    void* data;
    struct Node* next;
} Node;

typedef struct{
    Node* top;
    size_t size;
    size_t memoryUsed;
} DynamicStack;

// Definição das funções
DynamicStack* createStack();
void destroyStack(DynamicStack* stack);
bool push(DynamicStack* stack, void* data, size_t dataSize);
void* pop(DynamicStack* stack);
bool isEmpty(DynamicStack* stack);
void printStack(DynamicStack* stack, void (*printFunc)(void*));
void printFloat(void* data);

#endif
