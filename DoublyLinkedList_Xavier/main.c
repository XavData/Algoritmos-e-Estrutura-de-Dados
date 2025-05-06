#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

void displayMenu(){
    printf("\nMENU (0 para encerrar o programa):\n");
    printf("1 - Inserir no inicio\n");
    printf("2 - Inserir no final\n");
    printf("3 - Remover do inicio\n");
    printf("4 - Remover do final\n");
    printf("Digite uma opcao: ");
}

int main() {
    DoublyLinkedList *list = createList();
    int option, value;

    do {
        system(CLEAR); // Limpa a tela
        printList(list, printInt);
        displayMenu();

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Digite o valor a ser inserido no inicio: ");
                scanf("%d", &value);
                insertAtBeginning(list, &value, sizeof(int));
                break;
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &value);
                insertAtEnd(list, &value, sizeof(int));
                break;
            case 3: {
                int *removedValue = (int*)removeFromBeginning(list);
                if (removedValue != NULL) {
                    printf("Valor removido do inicio: %d\n", *removedValue);
                    free(removedValue);
                } else {
                    printf("Lista vazia, nada para remover.\n");
                }
                break;
            }
            case 4: {
                int *removedValue = (int*)removeFromEnd(list);
                if (removedValue != NULL) {
                    printf("Valor removido do final: %d\n", *removedValue);
                    free(removedValue);
                } else {
                    printf("Lista vazia, nada para remover.\n");
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
            while (getchar() != '\n'); // Problema resolvido: Quando o usuário digita algo como "1abc", o scanf("%d", &option) lê apenas o 1, deixando "abc\n" no buffer. Solução: getchar() lê cada caractere residual até encontrar uma quebra de linha ('\n'). Descarta tudo que estiver "sujando" o buffer.
            getchar(); // Espera Enter, susbstitui o "system("pause")" que é so do windows
        }
    } while (option != 0);

    destroyList(list);
    return 0;
}
