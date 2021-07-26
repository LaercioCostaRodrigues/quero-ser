/*
 * File:  parser_exportacao.c
 * Autor:  Laercio Costa Rodrigues
 * Descricao: Teste Técnico Intelitrader
*/

#include "parser_exportacao.h"


/* Exporta dados para o Arquivo transfere.txt */
void exporta_transfere(lista_estoque* le, lista_venda* lv, char* arquivo_transfere) {
   
   if(!eh_vazia_estoque(le) && !eh_vazia_venda(lv)){

      int necessario, transferir;
      pt_no_estoque estoque = le->inicio;
      pt_no_venda venda = NULL;
      FILE* escritor;
      escritor = fopen(arquivo_transfere, "w");

      fprintf(escritor, "Necessidade de Transferência Armazém para CO\n\n");
      fprintf(escritor, "Produto  QtCO  QtMin  QtVendas  Estq.após  Necess.  Transf. de\n");
      fprintf(escritor, "                                   Vendas            Arm p/ CO\n");

      while (estoque != NULL){

         if((venda = procura_no_venda(lv, *(estoque->codigo)))){
            necessario = 0;

            if (*(estoque->qt_inicial) - *(venda->qt_vendida) - *(estoque->qt_co) < 0)
               necessario = *(estoque->qt_co) - (*(estoque->qt_inicial) - *(venda->qt_vendida));
            
            if (necessario > 1 && necessario < 10)
               transferir = 10;
            else
               transferir = necessario;

            fprintf(escritor, "%d", *(estoque->codigo)); /* Coluna 1 -> Produto */
            fprintf(escritor, "%8d", *(estoque->qt_inicial)); /* Coluna 2 -> QtCO */
            fprintf(escritor, "%7d", *(estoque->qt_co)); /* Coluna 3 -> QtMin */
            fprintf(escritor, "%10d", *(venda->qt_vendida)); /* Coluna 4 -> QtVendas */
            /* Coluna 5 -> Estq.após Vendas */
            fprintf(escritor, "%11d", *(estoque->qt_inicial) - *(venda->qt_vendida));
            fprintf(escritor, "%9d", necessario); /* Coluna 6 -> Necess. */
            fprintf(escritor, "%12d\n", transferir); /* Coluna 7 - > Transf. de Arm p/ CO */
         }

         estoque = estoque->proximo;
      }
      
      fclose(escritor);
   }

}


/* Exporta dados para o Arquivo TOTCANAIS.txt */
void exporta_relatorio_por_canais(char* arquivo_relatorio_por_canais) {
   
   FILE* escritor;
   escritor = fopen(arquivo_relatorio_por_canais, "w");

   fprintf(escritor, "Quantidades de Vendas por canal\n\n");
   fprintf(escritor, "Canal                  QtVendas\n");
   fprintf(escritor, "1 - Representantes %12d", retorna_representantes());
   fprintf(escritor, "\n2 - Website %19d", retorna_website());
   fprintf(escritor, "\n3 - App móvel Android %9d", retorna_app_android());
   fprintf(escritor, "\n4 - App móvel iPhone %10d\n", retorna_app_iphone());
   
   fclose(escritor);
}


/*  Relatório de Divergências */
/* Linha LL – Código de Produto não encontrado CCCCC */
void divergencia_nao_encontrado(int linha, int codigo, char* arquivo_divergencias) {

   FILE* escritor;
   escritor = fopen(arquivo_divergencias, "a");

   fprintf(escritor, "Linha %d - ", linha);
   fprintf(escritor, "Código de Produto não encontrado %d\n", codigo);

   fclose(escritor);
}


/* Linha LL – Venda cancelada */
void divergencia_cancelada(int linha, char* arquivo_divergencias) {

   FILE* escritor;
   escritor = fopen(arquivo_divergencias, "a");

   fprintf(escritor, "Linha %d - Venda cancelada\n", linha);

   fclose(escritor);
}


/* Linha LL – Venda não finalizada */
void divergencia_nao_finalizada(int linha, char* arquivo_divergencias) {

   FILE* escritor;
   escritor = fopen(arquivo_divergencias, "a");

   fprintf(escritor, "Linha %d - Venda não finalizada\n", linha);

   fclose(escritor);
}


/* Linha LL – Erro desconhecido*/
void divergencia_erro(int linha, char* arquivo_divergencias) {

   FILE* escritor;
   escritor = fopen(arquivo_divergencias, "a");

   fprintf(escritor, "Linha %d - Erro desconhecido. Acionar equipe de TI\n", linha);

   fclose(escritor);
}