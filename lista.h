#include "tipo.h"

#ifndef LISTA_H
#define LISTA_H

#define LIST_NULL_PTR           -1
#define LIST_OUT_OF_MEM         -2
#define LIST_SUCCES              0
#define LIST_EMPTY              -3
#define LIST_INDEX_OUT_OF_RANGE -4

typedef struct list list;

/**
 * Insere um elemento no fim da lista encadeada.
 * @param lst: um ponteiro para lista encadeada.
 * @param element: um elemento qualquer.
 * @return: codigo de erro da função.
 */
int list_append(list *lst, item element);

/**
 * Aloca um espaço de memória para uma lista encadeada vazia e retorna um ponteiro para
 * essa região de memória.
 * @return: um ponteiro para descritor de lista encadeada.
 */
list *list_create(void);

/**
 * Libera o espaço em meória ocupado pela lista encadeada e seus elementos.
 * @param lst: ponteiro para lista encadeada.
 */
void list_free(list *lst);

/**
 * Dado um indice, retorna o elemento que se encontra nessa determinada posição.
 * @param lst: ponteiro para lista encadeada.
 * @param i: posição do elemento na lista.
 * @param element: endereço de memória para armazenar o elemento retornado.
 */
int list_get(list *lst, int i, item *element);

/**
 * Remove um item do inicio da lista. O elemento removido será armazenado em um endereço
 * de memória especificado pelo programador.
 * @param lst: um ponteiro para lista encadeada;
 * @param element: um endereço de memória para "retornar" o elemento removido da lista.
 * @return: codigo de erro da função.
 */
int list_pop(list *lst, item *element);

/**
 * Insere um elemento na cabeça da lista encadeada.
 * @param lst: ponteiro para lista encadeada;
 * @param element: um item qualquer;
 * @return: retorna um código de erro da função.
 */
int list_push(list *lst, item element);

/**
 * Remove um elemento no fim da lista encadeada.
 * @param lst: um ponteiro para lista encadeada;
 * @param element: um endereço de memória para "retornar" o elemento removido da lista.
 * @return: codigo de erro da função.
 */
int list_remove_end(list *lst, item *element);

/**
 * Retorna ao usuário o tamanho da lista encadeada.
 * @param lst: um ponteiro para lista encadeada.
 * @param size: endereço de memória para armazenar o tamanho da lista.
 * @return: codigo de erro da função.
 */
int list_size(list *lst, int *size);

#endif // LISTA_H
