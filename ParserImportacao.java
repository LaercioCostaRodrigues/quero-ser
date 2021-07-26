import java.io.*;

public class ParserImportacao {

   private Empresa empresa;

   ParserImportacao(Empresa empresa) {
      this.empresa = empresa;
   }

   // Importa dados do Arquivo produtos.txt
   void importaEstoque(String NomeArquivo) {
      String linha = null;
      try (BufferedReader leitor = new BufferedReader(new FileReader(NomeArquivo))) {
         // 16320;344;200
         // 16320 -> Código do Produto;
         // 344 -> Quantidade em estoque no início do período;
         // 200 -> Quantidade mínima que deve ser mantida no Centro Operacional
         while ((linha = leitor.readLine()) != null) {
            String[] campos = linha.split(";");
            int codigo = Integer.parseInt(campos[0]);
            int qtInicial = Integer.parseInt(campos[1]);
            int qtCO = Integer.parseInt(campos[2]);
            empresa.registraProduto(codigo, qtInicial, qtCO);
         }
      } catch (FileNotFoundException e) { e.printStackTrace();
      } catch (IOException e) { e.printStackTrace(); }
   }

   // Importa dados do Arquivo vendas.txt
   // Importa dados para formar o arquivo DIVERGENCIAS.TXT
   // Importa dados para formar o arquivo TOTCANAIS.TXT
   void importaVenda(String NomeArquivo) {
      int contadorLinhas = 0;
      String linha = null;
      try (BufferedReader leitor = new BufferedReader(new FileReader(NomeArquivo))) {
         // 16320;1;100;2
         // 16320 -> Código do Produto
         // 1 -> Quantidade vendida
         // 100 -> Situação da venda
         // 2 -> Canal de venda
         while ((linha = leitor.readLine()) != null) {
            String[] campos = linha.split(";");
            contadorLinhas++;
            int codigo = Integer.parseInt(campos[0]);
            int qtVendida = Integer.parseInt(campos[1]);
            int situacaoVenda = Integer.parseInt(campos[2]);
            int canalVenda = Integer.parseInt(campos[3]);

            if (situacaoVenda == 100 || situacaoVenda == 102) {
               if (empresa.contemEstoque(codigo)) {
                  if (empresa.contemVenda(codigo))
                     empresa.incrementaVenda(codigo, qtVendida);
                  else
                     empresa.registraVenda(codigo, qtVendida, situacaoVenda, canalVenda);
               }
            }

            //  Relatório de Divergências
            // Linha LL – Código de Produto não encontrado CCCCC
            if (!empresa.contemEstoque(codigo) && situacaoVenda != 999) {
               StringBuilder s = new StringBuilder();
               s.append("Linha " + contadorLinhas + " - ");
               s.append("Código de Produto não encontrado ");
               s.append(codigo);
               empresa.registraDivergencia(s.toString());
            }

            StringBuilder s = new StringBuilder();
            switch (situacaoVenda) {
               case 135: // Linha LL – Venda cancelada
                  s.append("Linha " + contadorLinhas + " - Venda cancelada");
                  empresa.registraDivergencia(s.toString());
                  break;
               case 190: // Linha LL – Venda não finalizada
                  s.append("Linha " + contadorLinhas + " - Venda não finalizada");
                  empresa.registraDivergencia(s.toString());
                  break;
               case 999: // Linha LL – Erro desconhecido.
                  s.append("Linha " + contadorLinhas + " - ");
                  s.append("Erro desconhecido. Acionar equipe de TI");
                  empresa.registraDivergencia(s.toString());
                  break;
            }

            // Relatório por canais
            if (situacaoVenda == 100 || situacaoVenda == 102) {
               switch (canalVenda) {
                  case 1: // 1: Representante comercial
                     empresa.incrementaRepresentantes(qtVendida);
                     break;
                  case 2: // 2: Website
                     empresa.incrementaWebSite(qtVendida);
                     break;
                  case 3: // 3: Aplicativo móvel Android
                     empresa.incrementaAppAndroid(qtVendida);
                     break;
                  case 4: // 4: Aplicativo móvel iPhone
                     empresa.incrementaAppIphone(qtVendida);
                     break;
               }
            }
         }
      } catch (FileNotFoundException e) { e.printStackTrace();
      } catch (IOException e) { e.printStackTrace(); }
   }
}