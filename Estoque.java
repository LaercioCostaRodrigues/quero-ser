public class Estoque {

   int codigo; // Código do Produto

   int qtInicial; // Quantidade em estoque no início do período

   int qtCO; // 	Quantidade mínima que deve ser mantida no Centro Operacional

   public Estoque(int codigo, int qtInicial, int qtCO) {
      this.codigo = codigo;
      this.qtInicial = qtInicial;
      this.qtCO = qtCO;
   }

   public int getCodigo() {
      return codigo;
   }

   public int getQtInicial() {
      return qtInicial;
   }

   public int getQtCO() {
      return qtCO;
   }
}