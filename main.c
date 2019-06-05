#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"


/**
 * Converte uma string em notação infixa para notação pósfixa.
 * @param inf: string em notação infixa.
 * @return: uma string em notação posfixa.
 */
char *infixa_posfixa(char *inf) {
    char *posf;
    int n, i, j;
    stack *s;

    n = strlen(inf);
    posf = (char *) malloc((n + 1) * sizeof(char));
    s = stack_create();
    stack_push(s, inf[0]); // empilhando o '('
    j = 0;

    for (i = 1; inf[i] != '\0'; i ++) {
        switch(inf[i]) {
            char x;

            case '(':
                stack_push(s, inf[i]);
                break;
            case ')':
                stack_pop(s, &x);

                while (x != '(') {
                    posf[j++] = x;
                    stack_pop(s, &x);
                }

                break;
            case '+':
            case '-':
                stack_pop(s, &x);

                while (x != '(') {
                    posf[j++] = x;
                    stack_pop(s, &x);
                }

                stack_push(s, x);
                stack_push(s, inf[i]);
                break;
            case '/':
            case '*':
                stack_pop(s, &x);
                
                while(x != '(' && x != '+' && x != '-') {
                    posf[j++] = x;
                    stack_pop(s, &x);
                }

                stack_push(s, x);
                stack_push(s, inf[i]);
                break;
            default:
                posf[j++] = inf[i];
        }
    }

    return posf;
}


int main(int argc, char **argv) {
    char infixa[] = "(A+B*(C-D))", *posfixa;

    posfixa = infixa_posfixa(infixa);
    printf("infixa: %s\n", infixa);
    printf("posfixa: %s\n", posfixa);

    return 0;
}
