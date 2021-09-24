/******************************************************************************
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <stdio.h>
#include "Quicksort.h"

int main()
{
    int vetor[MAX]; //VETOR ONDE VAI SER INSERIDO OS VALORES A SEREM ORDENADOS
    int vetorAnterior[MAX];  //VETOR QUE TERÁ UMA COPIA DO VETOR ANTERIOR ANTES DE PASSAR PELO PROCESSO DE ORDENACAO
    
    /*
    NESSE VETOR SERAO INSERIDOS O NUMERO DE comparacoes E DE movimentacoes, NESSA ORDEM
    */
    int nCompMovi[]={0,0};
    
    int quant; //VAI GUARDAR A quantidade DE VALORES DO VETOR 
    int formaOrd; //VAI GUARDAR O NUMERO A SER USADO PARA ESCOLHER O TIPO DE ORDENACAO, ANTES DE PASSAR NO QUICKSORT
    
    printf("=== QUICKSORT ===\n");
    /*
    ESSE DO WHILE VAI GARANTIR QUE O USUARIO SÓ POSSA DIGITAR UM DOS VALORES CORRETOS: 0,1,2 OU 3
    */
    do{
        printf("\nPrimeiramente digite a quantidade de valores para o vetor: \n");
        printf("[0] 100\n[1] 1.000\n[2] 10.000\n[3] 100.000\n\n");
            
        quant=escolheQuantValores();
        if (quant==-1) printf("valor invalido digite novamente!\n\n");
            
    }while(quant==-1);
    
    
    /*
    ESSE DO WHILE VAI GARANTIR QUE O USUARIO SÓ POSSA DIGITAR UM DOS VALORES CORRETOS: 0,1, OU 2
    */
    do{
        printf("\nAgora escolha a ordem dos valores deste vetor criado: \n");
        printf("[0] ordem crescente\n[1] ordem decrescente\n[2] ordem aleatória \n\n");
            
        formaOrd=escolheFormaOrdenecao();
        if (formaOrd==-1) printf("valor invalido digite novamente!\n\n");
        
    }while(formaOrd==-1);
    
    //PREENCHE O VETOR COM AS INFORMACOES DADAS
    criaVetor(vetor,quant,formaOrd);
    
    //FAZ A COPIA DO VETOR PREENCHIDO A CIMA
    copiaVetor(vetor,vetorAnterior,quant);
    
    /*
    ONDE ACONTECE A ORDENACAO
    OBSERVAÇÃO: O VETOR "nCompMovi" TAMBEM É PASSADO POR PARAMETRO PARA QUE SEJA POSSIVEL
    FAZER A CONTAGEM DE comparacoes E movimentacoes
    */
    ordenaQuickSort(vetor,nCompMovi,0,quant-1);
    //
    
    //VARIAVEIS PARA USO DO PROXIMO "DO WHILE"
    int qualVetor; //GUARDA QUAL VETOR O USUARIO DESEJA VER, 0 SE O VETOR ORIGINAL, ANTES DE ORDENAR, OU outro valor CASO QUEIRA VER O VETOR ORDENADO
    int verNovamente; //GUARDA A VALOR 0 SE O USUARIO DESEJA VER UM VETOR NOVAMENTE OU outro valor CASO NAO
    
    printf("\nOrdenação Concluida!\n");
    do{
        printf("Digite qual vetor deseja ver: \n");
        printf("[0] vetor original\n[outro valor] vetor ordenado\n\n");
        scanf("%d",&qualVetor);
        
        if (qualVetor==0){
            printf("\nEste é o vetor antes de ser ordenado: \n");
            exibeVetor(vetorAnterior,quant);
        }else{
            printf("\nEste é o vetor apos ser feita a ordenacao: \n");
            exibeVetor(vetor,quant);
        }
        
        printf("Deseja ver outro vetor novamente? \n");
        printf("[0] SIM\n[outro valor] NAO\n\n");
        scanf("%d",&verNovamente);
        
    }while(verNovamente==0);
    
    //APOS O USUARIO NÃO QUERER MAIS VER UM DOS VETORES É EXIBIDO O NUMERO DE comparacoes E movimentacoes
    printf("\nNessa ordenacao houveram: \n");
    printf("%d comparacoes e %d movimentacoes\n",nCompMovi[0],nCompMovi[1]);
    
    printf("\nFim do programa!");

    return 0;
}
