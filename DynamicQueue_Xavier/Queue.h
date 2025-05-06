#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure (same as DLL)
typedef struct Node {
    void *data;
    struct Node *next;
    struct Node *prev;
} Node;

// Queue structure (modified for FIFO)
typedef struct DynamicQueue {
    Node *front;  // Points to the first element (for dequeue)
    Node *rear;   // Points to the last element (for enqueue)
    size_t size;
    size_t memoryUsed;
} DynamicQueue;

// Function prototypes
DynamicQueue* createQueue();
void destroyQueue(DynamicQueue *queue);
void enqueue(DynamicQueue *queue, void *data, size_t dataSize);
void* dequeue(DynamicQueue *queue);
void printQueue(DynamicQueue *queue, void (*printFunc)(void*));
void printInt(void *data);
void displayQueueStatus(DynamicQueue *queue);

#endif