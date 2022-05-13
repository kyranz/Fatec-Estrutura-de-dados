#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listals.c"

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

    printf("Digite a expressao a ser analizada:\n");
    gets(expr);
    tam = strlen(expr);

    inicializar(&pilha);

    for (i = 0; i < strlen(expr); i++) {
        switch (expr[i]) {
        case '(':
        case '[':
        case '{':
            if (corresp) inserirInicio(&pilha, expr[i]);
            break;

        case ')':
        case ']':
        case '}':
            if (isEmpty(pilha)) {
                corresp = FALSE;
                break;
            }
            aux = getElemPosN(&pilha, 1);
            if (aux->info + 1 == expr[i] || aux->info + 2 == expr[i]) {
                removerInicio(&pilha);
            }
            else if (corresp) {
                inserirInicio(&pilha, expr[i]);
                corresp = FALSE;
            }
            break;

        default:
            break;
        }
        if (!corresp) break;
        printf("%c", expr[i]);
    }

    for (; i < strlen(expr); i++) printf("%c", expr[i]);
    printf("\n");

    show(pilha);

    if (isEmpty(pilha) && corresp) printf("\n\nA expressao eh balanceada! ;D");
    else printf("\n\nA expressao NAO eh balanceada! >:((((((((((((");

    destruir(&pilha);

    return 0;
}