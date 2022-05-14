#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lls.c"

/*
    Exercício:
        Verificar se uma expressão matemática esta balanceada usando uma pilha.
        Balanceada = Se um parenteses for aberto, deve ser fechado. Vale também para chaves e colchetes.

        A cada caractere de abrir encontrado, adiciona-lo a pilha.
        Se encontrado um de fechar, tirar do topo da pilha o abrir correspondente.

        Se encontrado um caractere de fechar sem um de abrir correspondente, a pilha esta desbalanceda.
        Se, ao final, a pilha conter algum caractere, a expressão esta desbalanceda.
        Se, ao final, a pilha estiver vazia, a expressão esta balanceada.
*/

int main() {

    char expr[100];
    int i, tam;
    BOOL corresp = TRUE;
    node *pilha, *aux;

    printf("Tamanho Maximo: 100 caracteres\n");
    printf("Digite a expressao a ser analizada:\n");
    gets(expr);
    printf("\n");
    tam = strlen(expr);

    inicializar(&pilha);

    for (i = 0; i < strlen(expr); i++) {
        switch (expr[i]) {
        case '(':
        case '[':
        case '{':
            inserirFinal(&pilha, expr[i]);
            break;

        case ')':
        case ']':
        case '}':
            if (isEmpty(pilha)) {
                inserirFinal(&pilha, expr[i]);
                corresp = FALSE;
                break;
            }
            aux = getElemPosN(&pilha, getSize(pilha));
            printf("%c == %c\n", aux->info, expr[i]);
            if (aux->info + 1 == expr[i] || aux->info + 2 == expr[i]) {
                removerFinal(&pilha);
            }
            else {
                inserirFinal(&pilha, expr[i]);
                corresp = FALSE;
            }
            break;

        default:
            break;
        }
        if (!corresp) break;
        // printf("%c", expr[i]);
    }

    // for (; i < strlen(expr); i++) printf("%c", expr[i]);

    show(pilha);

    if (isEmpty(pilha) && corresp) printf("\n\nA expressao eh balanceada! ;D");
    else printf("\n\nA expressao NAO eh balanceada! >:((((((((((((");

    destruir(&pilha);

    return 0;
}