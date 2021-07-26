/*
 * File:  main.c
 * Autor:  Laercio Costa Rodrigues
 * Descricao: Teste Técnico Intelitrader
*/

#include "listas.h"
#include "parser_importacao.h"
#include "parser_exportacao.h"


int main(){    

    lista_estoque* le_1;
    lista_venda* lv_1;
    
    lista_estoque* le_2;
    lista_venda* lv_2;
    

    /* Importa dados do Arquivo produtos.txt / retorna lista_estoque */
    le_1 = importa_estoque("c1_produtos.txt");
    

    /* Importa dados do Arquivo vendas.txt */
    /* Exporta arquivo DIVERGENCIAS.TXT*/
    /* Retorna lista venda */
    lv_1 = importa_venda("c1_vendas.txt", "DIVERGENCIAS_1.TXT", le_1);


    /* Exporta dados para o Arquivo transfere.txt */
    exporta_transfere(le_1, lv_1, "transfere_1.txt");


    /* Exporta dados para o Arquivo TOTCANAIS.txt */
    exporta_relatorio_por_canais("TOTCANAIS_1.txt");


    /* Liberta toda a memoria associada a lista de estoque. */
    liberta_lista_estoque(le_1);


    /* Liberta toda a memoria associada a lista de venda. */
    liberta_lista_venda(lv_1);





    /* Importa dados do Arquivo produtos.txt / retorna lista_estoque */
    le_2 = importa_estoque("c2_produtos.txt");
    

    /* Importa dados do Arquivo vendas.txt */
    /* Exporta arquivo DIVERGENCIAS.TXT*/
    /* Retorna lista venda */
    lv_2 = importa_venda("c2_vendas.txt", "DIVERGENCIAS_2.TXT", le_2);


    /* Exporta dados para o Arquivo transfere.txt */
    exporta_transfere(le_2, lv_2, "transfere_2.txt");


    /* Exporta dados para o Arquivo TOTCANAIS.txt */
    exporta_relatorio_por_canais("TOTCANAIS_2.txt");


    /* Liberta toda a memoria associada a lista de estoque. */
    liberta_lista_estoque(le_2);


    /* Liberta toda a memoria associada a lista de venda. */
    liberta_lista_venda(lv_2);


    return 0;
}

/*

    *****  All heap blocks were freed -- no leaks are possible *****

dell@Latitude:/mnt/f/quero-ser-master/Resolucao_C$ gcc -g -Wall -Wextra -Werror -ansi -pedantic *.c
dell@Latitude:/mnt/f/quero-ser-master/Resolucao_C$ valgrind ./a.out
==3721== Memcheck, a memory error detector
==3721== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3721== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3721== Command: ./a.out
==3721==
==3721==
==3721== HEAP SUMMARY:
==3721==     in use at exit: 0 bytes in 0 blocks
==3721==   total heap usage: 397 allocs, 397 frees, 181,292 bytes allocated
==3721==
==3721== All heap blocks were freed -- no leaks are possible
==3721==
==3721== For counts of detected and suppressed errors, rerun with: -v
==3721== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
dell@Latitude:/mnt/f/quero-ser-master/Resolucao_C$

*/