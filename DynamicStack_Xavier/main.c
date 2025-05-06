#include "Stack.h"
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
    printf("1 - Empilhar \n");
    printf("2 - Desempilhar \n");
    printf("0 - Encerrar o programa\n");
    printf("Digite uma opcao: ");
}

int main() {
    DynamicStack* stack = createStack();
    int option;
    float value;

    do {
        system(CLEAR);
        printStack(stack, printFloat);
        displayMenu();

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Digite um valor float para empilhar: ");
                scanf("%f", &value);
                push(stack, &value, sizeof(float));
                break;
            case 2: {
                float* popped = (float*)pop(stack);
                if (popped) {
                    printf("Valor desempilhado: %.2f\n", *popped);
                    free(popped);
                } else {
                    printf("Pilha vazia!\n");
                }
                break;
            }
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

        if (option != 0) {
            printf("Pressione Enter para continuar...");
            while (getchar() != '\n');
            getchar();
        }
    } while (option != 0);

    destroyStack(stack);
    return 0;
}