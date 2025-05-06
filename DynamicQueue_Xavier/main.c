#include "Queue.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

void displayMenu() {
    printf("\nMENU (0 para encerrar o programa):\n");
    printf("1 - Enfileirar \n");
    printf("2 - Desenfileirar \n");
    printf("0 - Encerrar o programa\n");
    printf("Digite uma opcao: ");
}

int main() {
    DynamicQueue *queue = createQueue();
    int choice, value;
    
    do {
        system(CLEAR);
        displayQueueStatus(queue);
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor para enfileirar: ");
                scanf("%d", &value);
                enqueue(queue, &value, sizeof(int));
                break;
                
            case 2:
                if (queue->size == 0) {
                    printf("\nA fila est  vazia!\n");
                } else {
                    int *removed = (int*)dequeue(queue);
                    printf("\nValor desenfileirado: %d\n", *removed);
                    free(removed);
                }
                break;
                
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
                
            default:
                printf("\nOp‡Æo inv lida! Tente novamente.\n");
        }
    } while (choice != 0);

    destroyQueue(queue);
    return 0;
}