#include "Queue.h"

StaticQueue* createQueue() {
    StaticQueue *queue = (StaticQueue*)malloc(sizeof(StaticQueue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

bool enqueue(StaticQueue *queue, int value) {
    if (isFull(queue)) return false;
    
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;
    queue->size++;
    return true;
}

int dequeue(StaticQueue *queue) {
    if (isEmpty(queue)) return -1; 
    
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return value;
}

bool isEmpty(StaticQueue *queue) {
    return (queue->size == 0);
}

bool isFull(StaticQueue *queue) {
    return (queue->size == MAX_SIZE);
}

void printQueue(StaticQueue *queue) {
    printf("\nPrimeiro: ");
    if (isEmpty(queue)) printf("NULL");
    else printf("%d", queue->data[queue->front]);

    printf("\nÚltimo: ");
    if (isEmpty(queue)) printf("NULL");
    else printf("%d", queue->data[queue->rear]);

    printf("\nTamanho: %zu", queue->size);
    printf("\nMemória alocada: %zu bytes", sizeof(StaticQueue));

    printf("\nFila: ");
    if (isEmpty(queue)) {
        printf("Vazia!");
    } else {
        int i = queue->front;
        for (int count = 0; count < queue->size; count++) {
            printf("%d", queue->data[i]);
            if (count < queue->size - 1) printf(" <- ");
            i = (i + 1) % MAX_SIZE;
        }
    }
    printf("\n");
}