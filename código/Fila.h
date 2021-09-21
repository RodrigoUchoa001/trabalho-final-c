#define MAX 100000

typedef struct{
  int prim;
  int fim;
  int vetor[MAX];
  int tamanho;
  
  //PARA USO DO QUICKSORT
  int nComparacoes;
  int nMovimentacoes;
}TFilaSequencial;


TFilaSequencial criarFilaSequencial();
int adicionar(TFilaSequencial *fila, int numero);
int removerFila(TFilaSequencial *fila);
void imprimirTodosElementos(TFilaSequencial *fila);

//MÉTODOS DO QUICKSORT
int escolheQuantValores();
TFilaSequencial criaVetor(TFilaSequencial *fila, int quant);
int escolheFormaOrdenecao();
TFilaSequencial ordenaVetor(TFilaSequencial *fila, int ord);
int imprimeRelatorioCompMonv(TFilaSequencial *fila);