import java.io.*;

public class ParserExportacao {

   private Empresa empresa;

   ParserExportacao(Empresa empresa) {
      this.empresa = empresa;
   }

   // Exporta dados para o Arquivo transfere.txt
   void exportaTransfere(String NomeArquivo) {
      try (BufferedWriter escritor = new BufferedWriter(new FileWriter(NomeArquivo))) {
         escritor.write("Necessidade de Transferência Armazém para CO\n\n");
         escritor.write("Produto  QtCO  QtMin  QtVendas  Estq.após  Necess.  Transf. de\n");
         escritor.write("                                   Vendas            Arm p/ CO\n");
         for (String s : empresa.getTransfereLista()) {
            escritor.write(s.toString() + "\n");
         }
      } catch (IOException e) { e.printStackTrace(); }
}

   // Exporta dados para o Arquivo TOTCANAIS.txt
   void exportaRelatorioPorCanais(String NomeArquivo) {
      try (BufferedWriter escritor = new BufferedWriter(new FileWriter(NomeArquivo))) {
         escritor.write("Quantidades de Vendas por canal\n\n");
         escritor.write("Canal                  QtVendas\n");
         escritor.write(String.format("1 - Representantes %12d", empresa.getRepresentantes()));
         escritor.write(String.format("\n2 - Website %19d", empresa.getWebSite()));
         escritor.write(String.format("\n3 - App móvel Android %9d", empresa.getAppAndroid()));
         escritor.write(String.format("\n4 - App móvel iPhone %10d", empresa.getAppIphone()));
      } catch (IOException e) { e.printStackTrace(); }
   }

   // Exporta arquivo DIVERGENCIAS.TXT
   void exportaRelatorioDivergencias(String NomeArquivo) {
      try (BufferedWriter escritor = new BufferedWriter(new FileWriter(NomeArquivo))) {
         for (String linha : empresa.getDivergenciaLista()) {
            escritor.write(linha + "\n");
         }
      } catch (IOException e) { e.printStackTrace(); }
   }

}