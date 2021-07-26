/*
 * File:  estruturas.c
 * Autor:  Laercio Costa Rodrigues
 * Descricao: Teste Técnico Intelitrader
*/

#include "listas.h"
#include "estruturas.h"


/* Cria/inicializa/retorna um no_estoque (struct estr_estoque). */
pt_no_estoque cria_no_estoque(int codigo, int qt_inicial, int qt_co) {

    pt_no_estoque novo_no = (pt_no_estoque) malloc(sizeof(no_estoque));
    int* pt_codigo = (int*) malloc(sizeof(int));
    int* pt_qt_inicial = (int*) malloc(sizeof(int));
    int* pt_qt_co = (int*) malloc(sizeof(int));

    *pt_codigo = codigo;
    *pt_qt_inicial = qt_inicial;
    *pt_qt_co = qt_co;

    if (novo_no == NULL)         /* Verifica alocacao de memoria. */
        puts("cria_no_estoque: Erro. malloc retornou NULL\n");

    novo_no->codigo = pt_codigo;
    novo_no->qt_inicial = pt_qt_inicial; 
    novo_no->qt_co = pt_qt_co;
    novo_no->proximo = NULL;

    return novo_no;
}   


/* Cria/inicializa/retorna um no_venda (struct estr_venda). */
pt_no_venda cria_no_venda(int codigo, int qt_vendida, int situacao_venda, int canal_venda) {

    pt_no_venda novo_no = (pt_no_venda) malloc(sizeof(no_venda));
    int* pt_codigo = (int*) malloc(sizeof(int));
    int* pt_qt_vendida = (int*) malloc(sizeof(int));
    int* pt_situacao_venda = (int*) malloc(sizeof(int));
    int* pt_canal_venda = (int*) malloc(sizeof(int));

    *pt_codigo = codigo;
    *pt_qt_vendida = qt_vendida;
    *pt_situacao_venda = situacao_venda;
    *pt_canal_venda = canal_venda;

    if (novo_no == NULL)         /* Verifica alocacao de memoria. */
        puts("cria_no_venda: Erro. malloc retornou NULL\n");

    novo_no->codigo = pt_codigo;
    novo_no->qt_vendida = pt_qt_vendida;
    novo_no->situacao_venda = pt_situacao_venda;
    novo_no->canal_venda = pt_canal_venda;
    novo_no->proximo = NULL;

    return novo_no;
} 


/* Liberta toda a memoria associada a um no_estoque (struct estr_estoque) */
void liberta_no_estoque(pt_no_estoque no_libertar){
   
    free(no_libertar->codigo);
    free(no_libertar->qt_inicial);
    free(no_libertar->qt_co);
    free(no_libertar);
    return;
}


/* Liberta toda a memoria associada a um no_venda (struct estr_venda) */
void liberta_no_venda(pt_no_venda no_libertar){
    
    free(no_libertar->codigo);
    free(no_libertar->qt_vendida);
    free(no_libertar->situacao_venda);
    free(no_libertar->canal_venda);
    free(no_libertar);
    return;
}