// Dentro da .h a gente define as estruturas e declara as funções
#ifndef DOUBLYLINKEDLIST_H // Se não foi criado
#define DOUBLYLINKEDLIST_H // Crie

#include <stdio.h> // funções pra entrada e saída de dados
#include <stdlib.h> // alocação de memória
#include <string.h> // manipulação de string

// Estrutura do Nó
typedef struct Node{
    void *data; // Ponteiro genérico para os dados
    struct Node *next; // Próximo nó
    struct Node *prev; // Nó anterior
} Node;

// Estrutura da Lista
typedef struct DoublyLinkedList{
    Node *head; // Primeiro nó
    Node *tail; // Último nó
    size_t size; // Tamanho da lista
    size_t memoryUsed; // Memória total alocada
} DoublyLinkedList;

// Declaração das Funções
DoublyLinkedList* createList();
void destroyList(DoublyLinkedList *list);
void insertAtBeginning(DoublyLinkedList *list, void *data, size_t dataSize);
void insertAtEnd(DoublyLinkedList *list, void *data, size_t dataSize);
void* removeFromBeginning(DoublyLinkedList *list);
void* removeFromEnd(DoublyLinkedList *list);
void printList(DoublyLinkedList *list, void (*printFunc)(void*));
void printInt(void *data);

#endif // termina o ifndef