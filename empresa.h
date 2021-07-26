/*
 * File:  empresa.h
 * Autor:  Laercio Costa Rodrigues
 * Descricao: Teste Técnico Intelitrader
*/

#ifndef _EMPRESA_
#define _EMPRESA_

#include "listas.h"


/* Registra produtos no estoque */
void registra_produto(lista_estoque* le, int codigo, int qtInicial, int qtCO);


/* Registra produtos no venda */
void registra_venda(lista_venda* lv, int codigo, int qtVendida, int situacaoVenda, int canalVenda);


/* Inicializa valores de vendas por canal */
void inicializa_vendas_por_canal();


/* Incrementa Venda pelo canal Representantes */
void incrementa_representantes(int qtVendida);


/* Incrementa Venda pelo canal WebSite */
void incrementa_website(int qtVendida);


/* Incrementa Venda pelo canal App Android */
void incrementa_app_android(int qtVendida);


/* Incrementa Venda pelo canal App Iphone */
void incrementa_app_iphone(int qtVendida);


/* Retorna Venda pelo canal Representantes */
int retorna_representantes();


/* Retorna Venda pelo canal WebSite */
int retorna_website();


/* Retorna Venda pelo canal App Android */
int retorna_app_android();


/* Retorna Venda pelo canal App Iphone */
int retorna_app_iphone();


#endif