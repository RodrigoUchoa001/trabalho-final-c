#define MAX 100000

//METODOS DE CRIACAO DO VETOR
int escolheQuantValores();
int escolheFormaOrdenecao();
void criaVetor(int *vetor, int quant,int formaOrd);
int geraNumero(int quant);

//METODO DE EXIBICAO DO VETOR
void exibeVetor(int *vetor,int tamanho);

//METODOS DE ORDENACAO DO VETOR
void ordenaQuickSort(int *vetor, int *nCompMovi, int primeiraPosi, int ultimaPosi);
void trocaPosicoes(int *vetor, int posi1, int posi2);
int particiona(int *vetor, int *nCompMovi, int primeiraPosi, int ultimaPosi);


//METODO DE COPIAR O VETOR
void copiaVetor(int *vetor, int *vetorAnterior, int quant);
