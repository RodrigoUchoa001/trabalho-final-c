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


void trocaPosicoes(int *vetor, int posi1, int posi2){
    int aux = vetor[posi1];
    vetor[posi1] = vetor[posi2];
    vetor[posi2] = aux;
}


void ordenaQuickSort(int *vetor,int *nCompMovi, int primeiraPosi, int ultimaPosi){
    if (primeiraPosi<ultimaPosi){
        int pivo=particiona(vetor,nCompMovi,primeiraPosi,ultimaPosi);
        
        ordenaQuickSort(vetor,nCompMovi,primeiraPosi,pivo-1);
        
        ordenaQuickSort(vetor,nCompMovi,pivo+1,ultimaPosi);
    }
}


int particiona(int *vetor,int *nCompMovi, int inicio, int fim){
    int meio = (inicio + fim) / 2;
    int a = vetor[inicio];
    int b = vetor[meio];
    int c = vetor[fim];
    int medianaIndice;
    
    if (a < b) {
        nCompMovi[0]++;
        
        if (b < c) {
             nCompMovi[0]++;
            
            //a < b && b < c
            medianaIndice = meio;
        } else {
             nCompMovi[0]++;
            
            if (a < c) {
                 nCompMovi[0]++;
                
                //a < c && c <= b
                medianaIndice = fim;
            } else {
                 nCompMovi[0]++;
                
                //c <= a && a < b
                medianaIndice = inicio;
            }
        }
    } else {
         nCompMovi[0]++;
        
        if (c < b) {
             nCompMovi[0]++;
            
            //c < b && b <= a
            medianaIndice = meio;
        } else {
             nCompMovi[0]++;
            
            if (c < a) {
                 nCompMovi[0]++;
                
                //b <= c && c < a
                medianaIndice = fim;
            } else {
                 nCompMovi[0]++;
                
                //b <= a && a <= c
                medianaIndice = inicio;
            }
        }
    }
    
    trocaPosicoes(vetor, medianaIndice, fim);
    nCompMovi[1]++;
    
    //*******************ALGORITMO DE PARTIÇÃO DE CORMEN*********************
    //o pivo é o elemento final
    int pivo = vetor[fim];
    int i = inicio - 1;
    int j;
    /*
     * Este laço irá varrer os vetores da esquerda para direira
     * procurando os elementos que são menores ou iguais ao pivô.
     * Esses elementos são colocados na partição esquerda.         
     */
    for (j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i = i + 1;
            trocaPosicoes(vetor, i, j);
            
            nCompMovi[1]++;
        }
        nCompMovi[0]++;
        
    }
    //coloca o pivô na posição de ordenação
    trocaPosicoes(vetor, i + 1, fim);
    
    nCompMovi[1]++;
    
    return i + 1; //retorna a posição do pivô
}



void copiaVetor(int *vetor, int *vetorAnterior, int quant){
    for (int i=0;i<quant;i++){
        vetorAnterior[i]=vetor[i];
    }
}

