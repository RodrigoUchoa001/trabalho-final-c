#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

//#define MAX 100000

TFilaSequencial criarFilaSequencial(){
  TFilaSequencial novaFila;
  novaFila.prim = 0;
  novaFila.fim = 0;
  novaFila.tamanho = 0;
  
  //PARA USO DO QUICKSORT
  novaFila.nComparacoes=0;
  novaFila.nMovimentacoes=0;
  
  return novaFila;
}

int adicionar(TFilaSequencial *fila, int numero){
  if(fila->tamanho < MAX){
    fila->vetor[fila->fim] = numero;
    fila->fim++;
    fila->tamanho++;
    if(fila->fim >= MAX){
      fila->fim = 0;
    }
    return 1;
  }else{
    return 0;
  }
}

int removerFila(TFilaSequencial *fila){
  if(fila->tamanho > 0){
      int elementoRemovido=fila->vetor[fila->prim];
      
    fila->prim++;
    fila->tamanho--;
    if(fila->prim >= MAX){
      fila->prim = 0;
    }
    return elementoRemovido; //MODIFICACAO PARA QUE ESSE METODO RETORNE O ELEMENTO QUE ACABOU DE SER REMOVIDO
  }else{
    return 0;
  }
}

void imprimirTodosElementos(TFilaSequencial *fila){
    int i = 0;
    int aux = fila->prim;
    while(i < fila->tamanho){
        printf("posicao %d:",i);
        printf("  %d  \n", fila->vetor[aux]);
        aux++;
        if(aux >= MAX){
            aux = 0;
        }
        i++;
  }
}


//MÉTODOS DO QUICKSORT
int escolheQuantValores(){
    int quant;
    scanf("%d",&quant);
    
    if (quant==0){
        return 100;
    } 
    else if (quant==1){
        return 1000;
    }
    else if (quant==2){ 
        return 10000;
    }
    else if(quant==3){ 
        return 100000;
    }
    else{
        return -1;
    }
}

TFilaSequencial criaVetor(TFilaSequencial *fila, int quant){
    int valor;
    for (int i=0;i<quant;i++){
        valor=rand()%(quant*2); //SERÁ INSERIDO NO VETOR UM NUMERO ENTRE 0 E O DOBRO DO N DE POSICOES
        adicionar(fila, valor);
    }
    
    return *fila;
}

int escolheFormaOrdenecao(){
    int ord;
    scanf("%d",&ord);
    
    if (ord==0){
        return 0;
    } 
    else if (ord==1){
        return 1;
    }
    else if (ord==2){ 
        return 2;
    }
    else return -1;
    
}

TFilaSequencial ordenaVetor(TFilaSequencial *fila, int ord){ //TO DO
    return *fila;
}

int imprimeRelatorioCompMonv(TFilaSequencial *fila){
    printf("\nDurante a ordenação desse vetor houveram: \n");
    printf("%d comparacoes e ",fila->nComparacoes);
    printf("%d movimentacoes\n\n",fila->nMovimentacoes);
    
}




