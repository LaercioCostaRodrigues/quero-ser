/*
 * File:  listas.h
 * Autor:  Laercio Costa Rodrigues
 * Descricao: Teste Técnico Intelitrader
*/

#ifndef _LISTAS_
#define _LISTAS_

#include "estruturas.h"
#include <stdio.h>  


/* Cria nova lista de estoque vazia. */
lista_estoque* cria_lista_estoque();                


/* Cria nova lista de venda vazia. */
lista_venda* cria_lista_venda();                

/* Verifica se a lista estoque eh vazia. */
int eh_vazia_estoque(const lista_estoque* l);


/* Verifica se a lista venda eh vazia. */
int eh_vazia_venda(const lista_venda* l);


/* Adiciona um no_estoque (struct estr_estoque) como o ultimo elemento da lista. */
void adiciona_estoque_fim(lista_estoque* l, pt_no_estoque novo_no);


/* Adiciona um no_venda (struct estr_venda) como o ultimo elemento da lista. */
void adiciona_venda_fim(lista_venda* l, pt_no_venda novo_no);


/* Procura um no_estoque (struct estr_estoque). */
pt_no_estoque procura_no_estoque(const lista_estoque* le, int codigo);


/* Procura um no_venda (struct estr_venda). */
pt_no_venda procura_no_venda(const lista_venda* le, int codigo);


/* Incrementa quantidade de vendas */
void incrementa_venda(const lista_venda* le, int codigo, int qt_vendida);


/* Liberta toda a memoria associada a lista de estoques. */
void liberta_lista_estoque(lista_estoque* l);


/* Liberta toda a memoria associada a lista de vendas. */
void liberta_lista_venda(lista_venda* l);


#endif