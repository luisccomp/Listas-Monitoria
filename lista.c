#include <stdlib.h>
#include "lista.h"


typedef struct node node;

struct list {
    int size;   // Tamanho da lista
    node *head; // Ponteiro para a cabeça da lista (primeiro elemento)
};

struct node {
    item element; // Elemento armazenado no nó da lista
    node *next;   // Referêncoa para o próximo elemento da lista
};


/**
 * Insere um elemento no fim da lista encadeada.
 * @param lst: um ponteiro para lista encadeada.
 * @param element: um elemento qualquer.
 * @return: codigo de erro da função.
 */
int list_append(list *lst, item element) {
    node *new_node, *curr;

    if (!lst)
        return -1;

    new_node = (node *) malloc(sizeof(struct node));
    new_node->element = element;
    curr = lst->head;

    // Se a cabeça da lista for vazia
    if (!curr) {
        new_node->next = lst->head;
        lst->head = new_node;
    }
    else {
        while (curr->next)
            curr = curr->next;

        // O elemento novo passa a ser o ultimo elemento da lista
        new_node->next = curr->next;
        curr->next = new_node;
    }

    // Atualiza o tamanho da lista
    lst->size ++;

    return 0;
}


/**
 * Aloca um espaço de memória para uma lista encadeada vazia e retorna um ponteiro para
 * essa região de memória.
 * @return: um ponteiro para descritor de lista encadeada.
 */
list *list_create(void) {
    list *lst;

    lst = (list *) malloc(sizeof(struct list));

    if (lst) {
        lst->size = 0;
        lst->head = NULL;
    }

    return lst;
}


/**
 * Libera o espaço em meória ocupado pela lista encadeada e seus elementos.
 * @param lst: ponteiro para lista encadeada.
 */
void list_free(list *lst) {
    node *prev, *curr;

    if (lst) {
        curr = lst->head;

        while (curr) {
            prev = curr;
            curr = curr -> next;
            free(prev);
        }    

        free(lst);
    }
}


/**
 * Dado um indice, retorna o elemento que se encontra nessa determinada posição. O indice
 * da lista começa por 0.
 * @param lst: ponteiro para lista encadeada.
 * @param i: posição do elemento na lista.
 * @param element: endereço de memória para armazenar o elemento retornado.
 */
int list_get(list *lst, int i, item *element) {
    int pos;
    node *curr;

    if (!lst)
        return -1;

    if (i < 0 || i > lst->size - 1)
        return -4;

    curr = lst->head;

    pos = i;

    while (pos --) {
        curr = curr->next;
    }

    *element = curr->element;

    return 0;
}


/**
 * Remove um item do inicio da lista. O elemento removido será armazenado em um endereço
 * de memória especificado pelo programador.
 * @param lst: um ponteiro para lista encadeada;
 * @param element: um endereço de memória para "retornar" o elemento removido da lista.
 * @return: codigo de erro da função.
 */
int list_pop(list *lst, item *element) {
    node *curr;

    if (!lst)
        return -1;
    else if (!(lst->head))
        return -3;

    curr = lst->head;
    // A cabeça da lista passa a ser o próximo elemento referenciado pelo antigo elemento
    lst->head = curr->next;
    lst->size --;
    *element = curr->element;
    free(curr);

    return 0;
}


/**
 * Insere um elemento na cabeça da lista encadeada.
 * @param lst: ponteiro para lista encadeada;
 * @param element: um item qualquer;
 * @return: retorna um código de erro da função.
 */
int list_push(list *lst, item element) {
    node *new_node;

    if (!lst)
        return -1;

    new_node = (node *) malloc(sizeof(struct node));

    if (!new_node)
        return -2;

    // O novo elemento inserido passa a ser a cabeça da lista
    new_node->element = element;
    new_node->next = lst->head;
    lst->head = new_node;
    // Incrementa a quantidade de elementos da lista
    lst->size ++;

    return 0;
}


/**
 * Remove um elemento no fim da lista encadeada.
 * @param lst: um ponteiro para lista encadeada;
 * @param element: um endereço de memória para "retornar" o elemento removido da lista.
 * @return: codigo de erro da função.
 */
int list_remove_end(list *lst, item *element) {
    node *prev, *curr;

    if (!lst)
        return -1;
    else if (!(lst->head))
        return -3;

    curr = lst->head;

    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }

    *element = curr->element;

    // se o elemento a ser removido for a cabeça
    if (curr == lst->head) {
        lst->head = curr->next;
        free(curr);
    }
    else {
        prev->next = curr->next;
        free(curr);
    }

    lst->size --;

    return 0;
}


/**
 * Retorna ao usuário o tamanho da lista encadeada.
 * @param lst: um ponteiro para lista encadeada.
 * @param size: endereço de memória para armazenar o tamanho da lista.
 * @return: codigo de erro da função.
 */
int list_size(list *lst, int *size) {
    if (!lst)
        return -1;

    *size = lst->size;

    return 0;
}
