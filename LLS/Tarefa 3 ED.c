#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "listals.c"

/*
    Receber duas strings
    Uma servira como um padrão, que validara a outra.
    A padrão terá caracteres a serem reconhecidos:
        A: Qualquer letra maiuscula
        a: Qualquer letra minuscula
        0: Qualquer numero de 0 a 9
        [1-9]: O numero correspondente
        #: Dever contar uma hashtag
        !: Dever contar uma exclamaçãoo
        ?: Dever contar uma interrogação
    Se os tamanhos das strings forem diferentes, retornar um erro.
    Se houver algum caractere invalido no padrao, retornar um erro.
    Se a string a ser validade corresponder com o padrão desejado, a string eh valida.
    Caso contrario, sera invalida.
*/

void llsGets(node **lls) {
    char tmp;

    do {
        tmp = getche();
        if (tmp == 8) {
            printf(" %c", 8);
            if (getSize(*lls) > 1) removerPosN(lls, getSize(*lls) - 1);
        }
        else if (tmp != 13) inserirFinal(lls, tmp);
        else break;
    } while (1);

    return;
}

int main() {

    int i, tam;
    BOOL str_valida = TRUE, p_valido = TRUE;
    node *padrao, *str, *ch_padrao, *ch_str;

    inicializar(&str);
    inicializar(&padrao);

    printf("Tamanho maximo dos inputs: 100\n");

    printf("\nDigite o padrao:\n");
    inserirInicio(&padrao, 0);
    llsGets(&padrao);
    removerFinal(&padrao);

    show(padrao);

    printf("\n\nDigite a string a ser validada:\n");
    inserirInicio(&str, 0);
    llsGets(&str);
    removerFinal(&str);

    show(str);

    tam = getSize(padrao);
    if (tam != getSize(str)) {
        printf("\n\nErro: Strings com tamanhos diferentes");
        return -1;
    }
    else if (tam == 0) {
        printf("\n\nErro: As strings estao vazias");
        return(-1);
    }

    for (i = 1; i <= tam; i++) {
        ch_padrao = getElemPosN(&padrao, i);
        ch_str = getElemPosN(&str, i);

        switch (ch_padrao->info) {
        case 'A':
            if (ch_str->info < 'A' || ch_str->info > 'Z') str_valida = FALSE;
            break;
        case 'a':
            if (ch_str->info < 'a' || ch_str->info > 'z') str_valida = FALSE;
            break;
        case '0':
            if (ch_str->info < '0' || ch_str->info > '9') str_valida = FALSE;
            break;
        case '#':
            if (ch_str->info != '#') str_valida = FALSE;
            break;
        case '!':
            if (ch_str->info != '!') str_valida = FALSE;
            break;
        case '?':
            if (ch_str->info != '?') str_valida = FALSE;
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            if (ch_str->info != ch_padrao->info) str_valida = FALSE;
            break;
        default:
            p_valido = FALSE;
            str_valida = FALSE;
            break;
        }

        if (!p_valido) break;
    }
    
    if (!p_valido) {
        printf("\n\nErro: Caractere invalido no padrao -> %c", ch_padrao->info);
        return -1;
    }
    else if (str_valida) {
        printf("\n\nA string eh valida! :O");
        return 0;
    }
    else {
        printf("\n\nA string NAO eh valida! ;-;");
        return -1;
    }

}