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
    StaticStack* stack = createStack();
    int option;
    char value;

    do { // do-while permite que o bloco de código execute pelo menos uma vez antes da condição
        system(CLEAR);
        printStack(stack, printChar);
        displayMenu();

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Digite um caractere para empilhar: ");
                scanf(" %c", &value); // O espaço em branco (" %c") diz ao scanf para: Ignorar todos os whitespaces (espaços, tabs, quebras de linha) antes de ler o próximo caractere. Só então ler o caractere desejado (não-whitespace).
                push(stack, &value, sizeof(char));
                break;
            case 2: {
                char* popped = (char*)pop(stack);
                if (popped) {
                    printf("Valor desempilhado: %c\n", *popped);
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
            while (getchar() != '\n'); // Problema resolvido: Quando o usuário digita algo como "1abc", o scanf("%d", &option) lê apenas o 1, deixando "abc\n" no buffer. Solução: getchar() lê cada caractere residual até encontrar uma quebra de linha ('\n'). Descarta tudo que estiver "sujando" o buffer.
            getchar(); // Espera Enter, susbstitui o "system("pause")" que é so do windows
        }
    } while (option != 0);

    destroyStack(stack);
    return 0;
}
