#include "Quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

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

void criaVetor(int *vetor, int quant,int formaOrd){
    int valor; //VAI SER USADO NO CASO DE ALEATORIO
    int posicao=0; //VAI SER USADO NO CASO DE DECRESCENTE
    
    switch (formaOrd){
        case 0: //CRESCENTE
            for (int i=0;i<quant;i++){
                vetor[i]=i;
            }
            break;
        case 1: //DECRESCENTE
             //
            for (int i=quant;i>0;i--){
                vetor[posicao]=i;
                posicao++;
            }
            break;
        case 2: //ALEATORIO
            
            srand(time(NULL)); //NECESSARIO PARA SEMPRE QUANDO EXECUTAR VIR Ns DIFERENTES
            
            for (int i=0;i<quant;i++){
                //valor=rand()%(quant*2); 
                valor=geraNumero(quant);
                vetor[i]=valor;
            }
    }
    
}

int geraNumero(int quant){
    int valor=rand()%(quant*2); //SERÁ INSERIDO NO VETOR UM NUMERO ENTRE 0 E O DOBRO DO N DE POSICOES
    return valor;
}


void exibeVetor(int *vetor, int tamanho){
    for (int i=0;i<tamanho;i++){
        printf("posicao %d: %d\n",i,vetor[i]);
    }
}

void ordenaQuickSort(int *vetor,int *nCompMovi){
    nCompMovi[0]=2; //NUMERO DE COMPARACOES
    nCompMovi[1]=3; //NUMERO DE MOVIMENTACOES
    
    //nComparacoes=2;
    //nMovimentacoes=3;
}

