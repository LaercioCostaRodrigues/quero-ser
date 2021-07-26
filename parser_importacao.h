/*
 * File:  parser_importacao.h
 * Autor:  Laercio Costa Rodrigues
 * Descricao: Teste Técnico Intelitrader
*/

#ifndef _PARSERIMPORTACAO_
#define _PARSERIMPORTACAO_

#include "listas.h"
#include "empresa.h"
#include "parser_exportacao.h"
#include <stdio.h>  


/* Importa dados do Arquivo produtos.txt / retorna lista_estoque */
lista_estoque* importa_estoque(char* NomeArquivo);


/* Importa dados do Arquivo vendas.txt / retorna lista venda*/
lista_venda* importa_venda(char* arquivo_vendas, char* arquivo_divergencias,
                                           lista_estoque* pt_lista_estoque);


#endif