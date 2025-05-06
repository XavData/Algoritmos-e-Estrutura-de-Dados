#include "Queue.h"

DynamicQueue* createQueue() {
    DynamicQueue *queue = (DynamicQueue*)malloc(sizeof(DynamicQueue));
    if (!queue) {
        perror("Failed to allocate memory for queue");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    queue->memoryUsed = sizeof(DynamicQueue);
    return queue;
}

void destroyQueue(DynamicQueue *queue) {
    Node *current = queue->front;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    free(queue);
}


void displayQueueStatus(DynamicQueue *queue) {
    printf("\nPrimeiro: ");
    if (queue->front != NULL) {
        printInt(queue->front->data);
    } else {
        printf("NULL");
    }

    printf("\nÚltimo: ");
    if (queue->rear != NULL) {
        printInt(queue->rear->data);
    } else {
        printf("NULL");
    }

    printf("\nTamanho: %zu", queue->size);
    printf("\nMemória alocada: %zu bytes", queue->memoryUsed);
    
    printf("\nFila: ");
    if (queue->front == NULL) {
        printf("Vazia!");
    } else {
        Node *current = queue->front;
        while (current != NULL) {
            printInt(current->data);
            if (current->next != NULL) printf(" <- ");
            current = current->next;
        }
    }
    printf("\n");
}

void enqueue(DynamicQueue *queue, void *data, size_t dataSize) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = malloc(dataSize);
    if (!newNode->data) {
        free(newNode);
        perror("Failed to allocate memory for data");
        exit(EXIT_FAILURE);
    }
    memcpy(newNode->data, data, dataSize);
    newNode->next = NULL;
    newNode->prev = queue->rear;

    if (queue->rear == NULL) { // Empty queue
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->size++;
    queue->memoryUsed += sizeof(Node) + dataSize;
}

void* dequeue(DynamicQueue *queue) {
    if (queue->front == NULL) return NULL;

    Node *removed = queue->front;
    void *data = removed->data;

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    } else {
        queue->front->prev = NULL;
    }

    queue->size--;
    queue->memoryUsed -= sizeof(Node) + sizeof(int); 
    free(removed);
    return data; 
}

void printInt(void *data) {
    printf("%d", *(int*)data);
}

void printQueue(DynamicQueue *queue, void (*printFunc)(void*)) {
    printf("Front: ");
    if (queue->front != NULL) {
        printFunc(queue->front->data);
    } else {
        printf("NULL");
    }
    printf("\n");

    printf("Rear: ");
    if (queue->rear != NULL) {
        printFunc(queue->rear->data);
    } else {
        printf("NULL");
    }
    printf("\n");

    printf("Size: %zu\n", queue->size);
    printf("Memory Used: %zu bytes\n", queue->memoryUsed);

    printf("Queue: ");
    if (queue->front == NULL) {
        printf("Empty!\n");
    } else {
        Node *current = queue->front;
        while (current != NULL) {
            printFunc(current->data);
            if (current->next != NULL) printf(" -> ");
            current = current->next;
        }
        printf("\n");
    }
}