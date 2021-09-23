/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include "Quicksort.h"

int main()
{
    int quant;
    int formaOrd;
    
    int vetor[MAX];
    
    printf("=== QUICKSORT ===\n");
    
    do{
        printf("\nPrimeiramente digite a quantidade de valores para o vetor: \n");
        printf("[0] 100\n[1] 1.000\n[2] 10.000\n[3] 100.000\n\n");
            
        quant=escolheQuantValores();
        //printf("%d",quant);
        if (quant==-1) printf("valor invalido digite novamente!\n\n");
            
    }while(quant==-1);
    
    do{
        printf("\n\nAgora escolha a ordem que este vetor será criado: \n");
        printf("[0] ordem crescente\n[1] ordem decrescente\n[2] ordem aleatória \n\n");
            
        formaOrd=escolheFormaOrdenecao();
        if (formaOrd==-1) printf("valor invalido digite novamente!\n\n");
        
    }while(formaOrd==-1);
    
    criaVetor(vetor,quant,formaOrd);
    
    printf("\nOs valores gerados estão sendo exibidos a seguir: \n");
    exibeVetor(vetor,quant);
    
    

    return 0;
}
