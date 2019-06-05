#include "tipo.h"

#ifndef PILHA_H
#define PILHA_H

#define STACK_NULL_PTR -5
#define STACK_EMPTY    -4

typedef struct stack stack;

/**
 * Cria uma pilha inicialmente vazia e retorna o endereço de memória alocado para a pilha.
 * @return: um ponteiro para pilha.
 */ 
stack *stack_create(void);

/**
 * Libera o espaço em memória ocupado pela pilha e destroi todos os elementos guardados nela.
 * @param stck: ponteiro para pilha em memória.
 */
void stack_free(stack *stck);

/**
 * Consulta o elemento do topo da pilha sem removê-lo.
 * @param stck: ponteiro para pilha;
 * @param elemento: um endereço de memória para armazenar o elemento consultado.
 * @return: codigo de erro da funcao.
 */
int stack_peek(stack *stck, item *elemento);

/**
 * Remove um elemento do topo da pilha.
 * @param stck: ponteiro para pilha;
 * @param elemento: um endereço de memória para armazenar o elemento removido da pilha.
 * @return: codigo de erro da função.
 */
int stack_pop(stack *stck, item *elemento);

/**
 * Insere um elemento no topo da pilha.
 * @param stck: ponteiro para pilha;
 * @param elemento: um elemento qualquer;
 * @return: codigo de erro da funcao.
 */
int stack_push(stack *stck, item elemento);

/**
 * Informa o tamanho da pilha.
 * @param stck: ponteiro para pilha;
 * @param size: endereço de memória onde será armazenado o tamanho da pilha.
 * @return: codigo de erro da funcao.
 */
int stack_size(stack *stck, int *size);

#endif // PILHA_H
