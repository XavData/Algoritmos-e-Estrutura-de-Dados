// no .c a gente vai dizer o que as funções fazem, detalhar elas
#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

// Criando uma lista nova

DoublyLinkedList* createList(){
    DoublyLinkedList *list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (!list) {
        perror("Erro ao alocar memória para a lista!");
        exit(EXIT_FAILURE);
    }

    list->head = NULL; // como lista é um ponteiro a gente usa "->" para acessar os membros dentro dele
    list->tail = NULL;
    list->size = 0;
    list->memoryUsed = sizeof(DoublyLinkedList); // Memória da estrutura da lista
    return list;
}

// limpando/destruindo uma lista
void destroyList(DoublyLinkedList *list){
    Node *current = list->head; // faço uma váriavel que aponta para o primeiro nó ou o último
    while (current != NULL){ // enquanto essa var não for vazia eu limpo o conteúdo até que seja
        Node *temp = current; // como eu preciso ter acesso ao proximo nó faço uma var temporaria para limpar a partir dela
        current = current->next; // current recebe o proximo nó para limpar, ou se fosse da tail até o head receberia o prev
        free(temp->data);
        free(temp);
    }

    free(list); // depois de limpar todos os conteudos dos nós limpo a lista
}

// colocando um nó no começo da lista
void insertAtBeginning(DoublyLinkedList *list, void *data, size_t dataSize){
    Node *newNode  = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Erro ao alocar memória para o novo nó!");
        exit(EXIT_FAILURE);
    }
    newNode->data = malloc(dataSize);
    if (newNode->data) {
        memcpy(newNode->data, data, dataSize);

        newNode->next = list->head;
        newNode->prev = NULL;

        if (list->head != NULL) { // se a lista não for vazia
            list->head->prev = newNode;
        } else {
            list->tail = newNode;
        }

        list->head = newNode;
        list->size++;
        list->memoryUsed += sizeof(Node) + dataSize;
    } else {
        free(newNode);
        perror("Erro ao alocar memória para dados do novo nó!");
        exit(EXIT_FAILURE);
    }
}

// colocando um nó no final da lista
void insertAtEnd(DoublyLinkedList *list, void *data, size_t dataSize){
    Node *newNode  = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Erro ao alocar memória para o novo nó!");
        exit(EXIT_FAILURE);
    }
    newNode->data = malloc(dataSize);
    if (newNode->data) {
        memcpy(newNode->data, data, dataSize);

        newNode->next = NULL;
        newNode->prev = list->tail;

        if (list->tail != NULL) {
            list->tail->next = newNode;
        } else {
            list->head = newNode;
        }

        list->tail = newNode;
        list->size++;
        list->memoryUsed += sizeof(Node) + dataSize;
    } else {
        free(newNode);
        perror("Erro ao alocar memória para dados do novo nó!");
        exit(EXIT_FAILURE);
    }
}

// removendo um nó no começo da lista
void* removeFromBeginning(DoublyLinkedList *list){
    if (list->head == NULL) return NULL; // se a lista for vazia ja acaba logo aqui

    Node *removed = list->head;
    void *data = removed->data;

    list->head = list->head->next;
    if (list->head != NULL) { // se a lista não tiver ficado vazia
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }

    list->size--;
    list->memoryUsed -= sizeof(Node) + sizeof(int);

    free(removed);
    return data;
}

// removendo um nó no final da lista
void* removeFromEnd(DoublyLinkedList *list){
    if (list->tail == NULL) return NULL; // se a lista for vazia ja acaba logo aqui

    Node *removed = list->tail;
    void *data = removed->data;

    list->tail = list->tail->prev;
    if (list->tail != NULL) { // se a lista não tiver ficado vazia
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }

    list->size--;
    list->memoryUsed -= sizeof(Node) + sizeof(int);

    free(removed);
    return data;
}

// printar um int
void printInt(void *data){
    printf("%d", *(int*)data);
}

//printar a lista toda
void printList(DoublyLinkedList *list, void (*printFunc)(void*)){
    printf("Inicio: ");
    if (list->head != NULL) {
        printFunc(list->head->data);
    } else {
        printf("NULL");
    }
    printf("\n");

    printf("Final: ");
    if (list->tail != NULL) {
        printFunc(list->tail->data);
    } else {
        printf("NULL");
    }
    printf("\n");

    printf("Tamanho: %zu\n", list->size);
    printf("Memoria alocada: %zu bytes\n", list->memoryUsed);

    printf("Lista: ");
    if (list->head == NULL) {
        printf("Vazia!\n");
    } else {
        Node *current = list->head;
        while (current != NULL) {
            printFunc(current->data);
            if (current->next != NULL) {
                printf(" <-> ");
            }
            current = current->next;
        }
        printf("\n");
    }
}
