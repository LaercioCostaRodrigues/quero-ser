public class Venda {

   int codigo; // Código do Produto

   int qtVendida; // Quantidade vendida

   // 100: venda confirmada e com pagamento ok.
   // 102: venda confirmada, mas com pagamento pendente
   // 135: venda cancelada
   // 190: venda não finalizada no canal de vendas
   // 999: erro não identificado
   int situacaoVenda; // Situação da venda

   // 1: Representante comercial
   // 2: Website
   // 3: Aplicativo móvel Android
   // 4: Aplicativo móvel iPhone
   int canalVenda; // Canal de venda

   public Venda(int codigo, int qtVendida, int situacaoVenda, int canalVenda) {
      this.codigo = codigo;
      this.qtVendida = qtVendida;
      this.situacaoVenda = situacaoVenda;
      this.canalVenda = canalVenda;
   }

   public int getQtVendida() {
      return qtVendida;
   }

   public void incrementaQtVendida(int qtVendida) {
      this.qtVendida += qtVendida;
   }
}