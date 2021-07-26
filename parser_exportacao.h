/*
 * File:  parser_exportacao.h
 * Autor:  Laercio Costa Rodrigues
 * Descricao: Teste Técnico Intelitrader
*/

#ifndef _PARSEREXPORTACAO_
#define _PARSEREXPORTACAO_

#include "listas.h"
#include "estruturas.h"
#include "empresa.h"
#include <stdio.h>  


/* Exporta dados para o Arquivo Divergencias.txt */
void divergencia_nao_encontrado(int contador_linhas, int codigo, char* arquivo_divergencias);


/* Linha LL – Venda cancelada */
void divergencia_cancelada(int linha, char* arquivo_divergencias);


/* Linha LL – Venda não finalizada */
void divergencia_nao_finalizada(int linha, char* arquivo_divergencias);


/* Linha LL – Erro desconhecido*/
void divergencia_erro(int linha, char* arquivo_divergencias);


/* Exporta dados para o Arquivo TRANSFERE.txt */
void exporta_transfere(lista_estoque* le, lista_venda* lv, char* arquivo_transfere);


/* Exporta dados para o Arquivo TOTCANAIS.txt */
void exporta_relatorio_por_canais(char* arquivo_relatorios_por_canais);


#endif