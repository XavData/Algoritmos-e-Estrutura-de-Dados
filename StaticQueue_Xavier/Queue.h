#ifndef STATICQUEUE_H
#define STATICQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100  // Tamanho máximo da fila estática

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    size_t size;
} StaticQueue;

StaticQueue* createQueue();
bool enqueue(StaticQueue *queue, int value);
int dequeue(StaticQueue *queue);
bool isEmpty(StaticQueue *queue);
bool isFull(StaticQueue *queue);
void printQueue(StaticQueue *queue);

#endif