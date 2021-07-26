/*
 * File:  listas.c
 * Autor:  Laercio Costa Rodrigues
 * Descricao: Teste Técnico Intelitrader
*/

#include "listas.h"


/* Cria nova lista de estoque vazia. */
lista_estoque* cria_lista_estoque(){

    /* Aloca memoria para struct estr_estoque. */
    lista_estoque* nova_lista = (lista_estoque*) malloc(sizeof(lista_estoque));
    
    if (nova_lista == NULL)      /* Verifica alocacao de memoria. */
        puts("cria_lista_estoque: Error. malloc returned NULL\n");
    
    nova_lista->inicio = NULL;   /* Inicializa inicio. */
    nova_lista->fim = NULL;      /* Inicializa fim. */
    
    return nova_lista;           /* Retorna ponteiro para a lista criada. */
}


/* Cria nova lista de venda vazia. */
lista_venda* cria_lista_venda(){

    /* Aloca memoria para struct estr_venda. */
    lista_venda* nova_lista = (lista_venda*) malloc(sizeof(lista_venda));

    if (nova_lista == NULL)      /* Verifica alocacao de memoria. */
        puts("cria_lista_venda: Error. malloc returned NULL\n");

    nova_lista->inicio = NULL;   /* Inicializa inicio. */
    nova_lista->fim = NULL;      /* Inicializa fim. */

    return nova_lista;           /* Retorna ponteiro para a lista criada. */
}


/* Verifica se a lista estoque eh vazia. */
int eh_vazia_estoque(const lista_estoque* l){
    return (l->inicio == NULL && l->fim == NULL);
}


/* Verifica se a lista venda eh vazia. */
int eh_vazia_venda(const lista_venda* l){
    return (l->inicio == NULL && l->fim == NULL);
}


/* Adiciona um no_estoque (struct estr_estoque) como o ultimo elemento da lista. */
void adiciona_estoque_fim(lista_estoque* l, pt_no_estoque novo_no){

    /* Adiciona em lista vazia. */
    if(l->inicio == NULL && l->fim == NULL){

        l->inicio = novo_no;
        l->fim = novo_no;
        novo_no->proximo = NULL;
    }

    /* Adiciona em lista nao vazia. */
    else{

        novo_no->proximo = NULL;
        l->fim->proximo = novo_no;
        l->fim = novo_no;
    }

    return;
}   


/* Adiciona um no_venda (struct estr_venda) como o ultimo elemento da lista. */
void adiciona_venda_fim(lista_venda* l, pt_no_venda novo_no){

    /* Adiciona em lista vazia. */
    if(l->inicio == NULL && l->fim == NULL){

        l->inicio = novo_no;
        l->fim = novo_no;
        novo_no->proximo = NULL;
    }

    /* Adiciona em lista nao vazia. */
    else{

        novo_no->proximo = NULL;
        l->fim->proximo = novo_no;
        l->fim = novo_no;
    }

    return;
}


/* Procura um no_estoque (struct estr_estoque). */
pt_no_estoque procura_no_estoque(const lista_estoque* le, int codigo){

    pt_no_estoque inicio = le->inicio;

    if(!eh_vazia_estoque(le)){

        while (inicio != NULL){

            if(*(inicio->codigo) == codigo){
                return inicio;
            }

            inicio = inicio->proximo;
        }

        return NULL;
    }

    return NULL;
}


/* Procura um no_venda (struct estr_venda). */
pt_no_venda procura_no_venda(const lista_venda* le, int codigo){

    pt_no_venda inicio = le->inicio;

    if(!eh_vazia_venda(le)){

        while (inicio != NULL){

            if(*(inicio->codigo) == codigo){
                return inicio;
            }

            inicio = inicio->proximo;
        }

        return NULL;
    }

    return NULL;
}


/* Incrementa quantidade de vendas */
void incrementa_venda(const lista_venda* le, int codigo, int qt_vendida){
    pt_no_venda no_venda = procura_no_venda(le, codigo);

    if (no_venda != NULL) {
        *(no_venda->qt_vendida) += qt_vendida;
    }
}


/* Liberta toda a memoria associada a lista de estoques. */
void liberta_lista_estoque(lista_estoque* l){

    lista_estoque* lista_velha = l;
    pt_no_estoque inicio = l->inicio;
    pt_no_estoque no_velho;

    while(inicio != NULL){

        no_velho = inicio;
        inicio = inicio->proximo;
        liberta_no_estoque(no_velho);
    }

    free(lista_velha);
    return;
}


/* Liberta toda a memoria associada a lista de vendas. */
void liberta_lista_venda(lista_venda* l){

    lista_venda* lista_velha = l;
    pt_no_venda inicio = l->inicio;
    pt_no_venda no_velho;

    while(inicio != NULL){

        no_velho = inicio;
        inicio = inicio->proximo;
        liberta_no_venda(no_velho);
    }

    free(lista_velha);
    return;
}