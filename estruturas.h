/*
 * File:  estruturas.h
 * Autor:  Laercio Costa Rodrigues
 * Descricao: Teste Técnico Intelitrader
*/

#ifndef _ESTRUTURAS_
#define _ESTRUTURAS_

#include "listas.h"
#include <stdlib.h>
#include <stdio.h>  


/****** Estruturas dos nos *****/

/* No estoque */
typedef struct estr_estoque{
    int* codigo; /* Código do Produto */
    int* qt_inicial; /* Quantidade em estoque no início do período */
    int* qt_co; /* Quantidade mínima que deve ser mantida no Centro Operacional */
    struct estr_estoque *proximo;
} no_estoque;

typedef struct estr_estoque* pt_no_estoque;


/* No venda */
typedef struct estr_venda{
    int* codigo; /* Código do Produto */
    int* qt_vendida; /* Quantidade vendida */
    int* situacao_venda; /* Situação da venda */
    int * canal_venda; /* Canal de venda */
    struct estr_venda *proximo;
} no_venda;

typedef struct estr_venda* pt_no_venda;




/****** Estruturas das Listas ******/

/* Lista estoque*/
typedef struct{
    struct estr_estoque *inicio, *fim;
} lista_estoque;


/* Lista venda*/
typedef struct{
    struct estr_venda *inicio, *fim;
} lista_venda;




/* Cria/inicializa/retorna um no_estoque (struct estr_estoque). */
pt_no_estoque cria_no_estoque(int codigo, int qt_inicial, int qt_co);


/* Cria/inicializa/retorna um no_venda (struct estr_venda). */
pt_no_venda cria_no_venda(int codigo, int qt_vendida, int situacao_venda, int canal_venda);


/* Liberta toda a memoria associada a um no_estoque (struct estr_estoque) */
void liberta_no_estoque(pt_no_estoque no_libertar);


/* Liberta toda a memoria associada a um no_venda (struct estr_venda) */
void liberta_no_venda(pt_no_venda no_libertar);


#endif