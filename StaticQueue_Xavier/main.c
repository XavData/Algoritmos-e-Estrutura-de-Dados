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
}

int main() {
    StaticQueue *queue = createQueue();
    int choice, value;

    do {
        system(CLEAR);
        printQueue(queue);
        displayMenu();
        printf("\nDigite uma op‡Æo: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(queue)) {
                    printf("\nERRO: Fila cheia!\n");
                } else {
                    printf("Digite o valor para enfileirar: ");
                    scanf("%d", &value);
                    enqueue(queue, value);
                }
                break;

            case 2:
                if (isEmpty(queue)) {
                    printf("\nERRO: Fila vazia!\n");
                } else {
                    printf("\nValor desenfileirado: %d\n", dequeue(queue));
                }
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOp‡Æo inv lida!\n");
        }
    } while (choice != 0);

    free(queue);
    return 0;
}