/*
 * File:  parser_importacao.c
 * Autor:  Laercio Costa Rodrigues
 * Descricao: Teste Técnico Intelitrader
*/

#include "parser_importacao.h"


/* Importa dados do Arquivo produtos.txt / retorna lista_estoque */
/* 16320;344;200 */
/* 16320 -> Código do Produto; */
/* 344 -> Quantidade em estoque no início do período; */
/* 200 -> Quantidade mínima que deve ser mantida no Centro Operacional */
lista_estoque* importa_estoque(char* arquivo_vendas) {

   int codigo, qtInicial, qtCO;
   lista_estoque* pt_lista_estoque = cria_lista_estoque();
   FILE *leitor;
   leitor = fopen(arquivo_vendas,"r");

   while(fscanf(leitor, "%d;%d;%d", &codigo, &qtInicial, &qtCO) != EOF) {
      registra_produto(pt_lista_estoque, codigo, qtInicial, qtCO);
   }

   fclose(leitor);
   return pt_lista_estoque;
}


/* Importa dados do Arquivo vendas.txt */
/* Exporta arquivo DIVERGENCIAS.TXT*/
/* Retorna lista venda */
/* 16320;1;100;2 */
/* 16320 -> Código do Produto */
/* 1 -> Quantidade vendida */
/* 100 -> Situação da venda */
/* 2 -> Canal de venda */
lista_venda* importa_venda(char* arquivo_vendas, char* arquivo_divergencias, 
                                           lista_estoque* pt_lista_estoque) {

   int codigo, qtVendida, situacaoVenda, canalVenda, contador_linhas = 0;
   lista_venda* pt_lista_venda = cria_lista_venda();
   FILE *leitor;
   FILE* escritor;
   leitor = fopen(arquivo_vendas,"r");
   /* Criar novo arquivo texto se ja existir um antigo */
   escritor = fopen(arquivo_divergencias, "w");
   fclose(escritor);   

   /* Inicializa valores de vendas por canal */
   inicializa_vendas_por_canal();

   while(fscanf(leitor, "%d;%d;%d;%d", &codigo, &qtVendida, &situacaoVenda, &canalVenda) != EOF) {

      contador_linhas++;

      if (situacaoVenda == 100 || situacaoVenda == 102) {

         if (procura_no_estoque(pt_lista_estoque, codigo) != NULL) {

            if (procura_no_venda(pt_lista_venda, codigo) != NULL)
               incrementa_venda(pt_lista_venda, codigo, qtVendida);
            else {
               registra_venda(pt_lista_venda, codigo, qtVendida, situacaoVenda, canalVenda);
            }
         }
      }
               
      /* Relatório de Divergências */
      /* Linha LL – Código de Produto não encontrado CCCCC */
      if (procura_no_estoque(pt_lista_estoque, codigo) == NULL && situacaoVenda != 999) {
         divergencia_nao_encontrado(contador_linhas, codigo, arquivo_divergencias);
      }

      switch (situacaoVenda) {
         case 135: /* Linha LL – Venda cancelada */
               divergencia_cancelada(contador_linhas, arquivo_divergencias);
               break;
         case 190: /* Linha LL – Venda não finalizada */
               divergencia_nao_finalizada(contador_linhas, arquivo_divergencias);
               break;
         case 999: /* Linha LL – Erro desconhecido. */
               divergencia_erro(contador_linhas, arquivo_divergencias);
               break;
      }

      /* Relatório por canais */
      if (situacaoVenda == 100 || situacaoVenda == 102) {
         switch (canalVenda) {
            case 1:
               incrementa_representantes(qtVendida);
               break;
            case 2:
               incrementa_website(qtVendida);
               break;
            case 3:
               incrementa_app_android(qtVendida);
               break;
            case 4:
               incrementa_app_iphone(qtVendida);
               break;
         }
      }

   }

   fclose(leitor);
   return pt_lista_venda;
}