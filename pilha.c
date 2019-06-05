#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

struct stack {
    list *lst;
};


/**
 * Cria uma pilha inicialmente vazia e retorna o endereço de memória alocado para a pilha.
 * @return: um ponteiro para pilha.
 */ 
stack *stack_create(void) {
    stack *stck = (stack *) malloc(sizeof(struct stack));

    if (stck) {
        stck->lst = list_create();

        if (!(stck->lst)) {
            free(stck);
            stck = NULL;
        }
    }

    return stck;
}

/**
 * Libera o espaço em memória ocupado pela pilha e destroi todos os elementos guardados nela.
 * @param stck: ponteiro para pilha em memória.
 */
void stack_free(stack *stck) {
    if (stck) {
        list_free(stck->lst);
        free(stck);
    }
}

/**
 * Consulta o elemento do topo da pilha sem removê-lo.
 * @param stck: ponteiro para pilha;
 * @param elemento: um endereço de memória para armazenar o elemento consultado.
 * @return: codigo de erro da funcao.
 */
int stack_peek(stack *stck, item *elemento) {
    if (!stck)
        return -5;

    return list_get(stck->lst, 0, elemento);
}

/**
 * Remove um elemento do topo da pilha.
 * @param stck: ponteiro para pilha;
 * @param elemento: um endereço de memória para armazenar o elemento removido da pilha.
 * @return: codigo de erro da função.
 */
int stack_pop(stack *stck, item *elemento) {
    if (!stck)
        return -5;

    return list_pop(stck->lst, elemento);
}

/**
 * Insere um elemento no topo da pilha.
 * @param stck: ponteiro para pilha;
 * @param elemento: um elemento qualquer;
 * @return: codigo de erro da funcao.
 */
int stack_push(stack *stck, item elemento) {
    if (!stck) 
        return -5;

    return list_push(stck->lst, elemento);
}

/**
 * Informa o tamanho da pilha.
 * @param stck: ponteiro para pilha;
 * @param size: endereço de memória onde será armazenado o tamanho da pilha.
 * @return: codigo de erro da funcao.
 */
int stack_size(stack *stck, int *size) {
    if (!stck)
        return -5;

    return list_size(stck->lst, size);
}
