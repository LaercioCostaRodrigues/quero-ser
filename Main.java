public class Main {

   public static void main(String[] args) {

      Empresa empresa1 = new Empresa();

      // Importa dados do Arquivo produtos.txt
      empresa1.importaEstoque("c1_produtos.txt");

      // Importa dados do Arquivo vendas.txt
      empresa1.importaVenda("c1_vendas.txt");

      // Exporta dados para o Arquivo transfere.txt
      empresa1.exportaTransfere("transfere_1.txt");

      // Exporta arquivo DIVERGENCIAS.TXT
      empresa1.exportaRelatorioDivergencias("DIVERGENCIAS_1.txt");

      // Exporta dados para o Arquivo TOTCANAIS.txt
      empresa1.exportaRelatorioPorCanais("TOTCANAIS_1.txt");


      Empresa empresa2 = new Empresa();

      // Importa dados do Arquivo produtos.txt
      empresa2.importaEstoque("c2_produtos.txt");

      // Importa dados do Arquivo vendas.txt
      empresa2.importaVenda("c2_vendas.txt");

      // Exporta dados para o Arquivo transfere.txt
      empresa2.exportaTransfere("transfere_2.txt");

      // Exporta arquivo DIVERGENCIAS.TXT
      empresa2.exportaRelatorioDivergencias("DIVERGENCIAS_2.txt");

      // Exporta dados para o Arquivo TOTCANAIS.txt
      empresa2.exportaRelatorioPorCanais("TOTCANAIS_2.txt");
   }
}
