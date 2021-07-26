import java.util.*;

public class Empresa {

   private Map<Integer, Estoque> estoqueMapa;
   private Map<Integer, Venda> vendaMapa;
   private List<String> divergenciasLista;
   private List<String> transfereLista;
   private int representantes = 0, webSite = 0;
   private int appAndroid = 0, appIphone = 0;

   public Empresa() {
      estoqueMapa = new LinkedHashMap<Integer, Estoque>();
      vendaMapa = new LinkedHashMap<Integer, Venda>();
      divergenciasLista = new ArrayList<String>();
      transfereLista = new ArrayList<String>();
   }

   /* Incrementa Venda pelo canal Representantes */
   public void incrementaRepresentantes(int representantes) {
      this.representantes += representantes;
   }

   /* Incrementa Venda pelo canal WebSite */
   public void incrementaWebSite(int webSite) {
      this.webSite += webSite;
   }

   /* Incrementa Venda pelo canal App Android */
   public void incrementaAppAndroid(int appAndroid) {
      this.appAndroid += appAndroid;
   }

   /* Incrementa Venda pelo canal App Iphone */
   public void incrementaAppIphone(int appIphone) {
      this.appIphone += appIphone;
   }

   public int getRepresentantes() { return representantes; }

   public int getWebSite() { return webSite; }

   public int getAppAndroid() { return appAndroid; }

   public int getAppIphone() { return appIphone; }


   void registraProduto(int codigo, int qtInicial, int qtCO) {
      estoqueMapa.put(codigo, new Estoque(codigo, qtInicial, qtCO));
   }

   void registraVenda(int codigo, int qtVendida , int situacaoVenda, int canalVenda ) {
      vendaMapa.put(codigo, new Venda(codigo, qtVendida, situacaoVenda, canalVenda));
   }

   void registraDivergencia(String linha){
      divergenciasLista.add(linha);
   }

   public boolean contemEstoque(int codigo) {
      return estoqueMapa.containsKey(codigo);
   }

   public boolean contemVenda(int codigo) {
      return vendaMapa.containsKey(codigo);
   }

   void incrementaVenda(int codigo, int qtVendida) {
      Venda v = vendaMapa.get(codigo);
      if (v != null)
         v.incrementaQtVendida(qtVendida);
   }

   public Collection<Estoque> getEstoqueMapa() {
      return Collections.unmodifiableCollection(estoqueMapa.values());
   }

   public Collection<String> getDivergenciaLista() {
      return Collections.unmodifiableCollection(divergenciasLista);
   }

   public Collection<String> getTransfereLista() {
      return Collections.unmodifiableCollection(transfereLista);
   }

   void criaTransfere() {

      for (Estoque e : getEstoqueMapa()) {
         Venda v = vendaMapa.get(e.getCodigo());
         String linha = "";

         if (v != null) {
            int necessario = 0, transferir;

            if (e.getQtInicial() - v.getQtVendida() - e.getQtCO() < 0)
               necessario = e.getQtCO() - (e.getQtInicial() - v.getQtVendida());
               
            if (necessario > 1 && necessario < 10)
               transferir = 10;
            else
               transferir = necessario;

            linha += e.getCodigo(); // Coluna 1 -> Produto
            linha += String.format("%8d", e.getQtInicial()); // Coluna 2 -> QtCO
            linha += String.format("%7d", e.getQtCO()); // Coluna 3 -> QtMin
            linha += String.format("%10d", v.getQtVendida()); // Coluna 4 -> QtVendas
            linha += String.format("%11d", e.getQtInicial() - v.getQtVendida()); // Coluna 5 -> Estq.após Vendas
            linha += String.format("%9d", necessario); // Coluna 6 -> Necess.
            linha += String.format("%12d", transferir); // Coluna 7 - > Transf. de Arm p/ CO

            transfereLista.add(linha);
         }
      }
   }

   // Importa dados do Arquivo produtos.txt
   void importaEstoque(String txtfile) {
         ParserImportacao parser = new ParserImportacao(this);
         parser.importaEstoque(txtfile);
      }

   // Importa dados do Arquivo vendas.txt
   void importaVenda(String txtfile) {
      ParserImportacao parser = new ParserImportacao(this);
      parser.importaVenda(txtfile);
   }

   // Exporta dados para o Arquivo transfere.txt
   void exportaTransfere(String txtfile) {
      criaTransfere();
      ParserExportacao parser = new ParserExportacao(this);
      parser.exportaTransfere(txtfile);
   }

   // Exporta arquivo DIVERGENCIAS.TXT
   void exportaRelatorioDivergencias(String txtfile) {
      ParserExportacao parser = new ParserExportacao(this);
      parser.exportaRelatorioDivergencias(txtfile);
   }

   // Exporta dados para o Arquivo TOTCANAIS.txt
   void exportaRelatorioPorCanais(String txtfile) {
      ParserExportacao parser = new ParserExportacao(this);
      parser.exportaRelatorioPorCanais(txtfile);
   }
}