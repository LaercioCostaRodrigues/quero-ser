/*
 * File:  empresa.c
 * Autor:  Laercio Costa Rodrigues
 * Descricao: Teste Técnico Intelitrader
*/

#include "empresa.h"


int representantes, website, app_android, app_iphone;


/* Registra produtos no estoque */
void registra_produto(lista_estoque* le, int codigo, int qt_inicial, int qt_co) {
    pt_no_estoque novo_no = cria_no_estoque(codigo, qt_inicial, qt_co);
    adiciona_estoque_fim(le, novo_no);
}


/* Registra produtos no venda */
void registra_venda(lista_venda* lv, int codigo, int qt_vendida,
                             int situacao_venda, int canal_venda){
                                 
    pt_no_venda novo_no = cria_no_venda(codigo, qt_vendida, situacao_venda, canal_venda);
    adiciona_venda_fim(lv, novo_no);
}


/* Inicializa valores de vendas por canal */
void inicializa_vendas_por_canal() {
    representantes = 0;
    website = 0;
    app_android = 0;
    app_iphone = 0;
}


/* Incrementa Venda pelo canal Representantes */
void incrementa_representantes(int qtVendida) {
    representantes += qtVendida;
}


/* Incrementa Venda pelo canal WebSite */
void incrementa_website(int qtVendida) {
    website += qtVendida;
}


/* Incrementa Venda pelo canal App Android */
void incrementa_app_android(int qtVendida) {
    app_android += qtVendida;
}


/* Incrementa Venda pelo canal App Iphone */
void incrementa_app_iphone(int qtVendida) {
    app_iphone += qtVendida;
}


/* Retorna Venda pelo canal Representantes */
int retorna_representantes(){
    return representantes;
}


/* Retorna Venda pelo canal WebSite */
int retorna_website(){
    return website;
}


/* Retorna Venda pelo canal App Android */
int retorna_app_android(){
    return app_android;
}


/* Retorna Venda pelo canal App Iphone */
int retorna_app_iphone(){
    return app_iphone;
}