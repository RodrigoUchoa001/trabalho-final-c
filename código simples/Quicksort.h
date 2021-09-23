#define MAX 100000

int escolheQuantValores();
int escolheFormaOrdenecao();
void criaVetor(int *vetor, int quant,int formaOrd);

int geraNumero(int quant);

void exibeVetor(int *vetor,int tamanho);

//ORDENACAO
void ordenaQuickSort(int *vetor, int *nCompMovi, int primeiraPosi, int ultimaPosi);
void trocaPosicoes(int *vetor, int posi1, int posi2);
int particiona(int *vetor, int *nCompMovi, int inicio, int fim);


//
void copiaVetor(int *vetor, int *vetorAnterior, int quant);
