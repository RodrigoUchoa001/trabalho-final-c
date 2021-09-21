/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
//#include "QuickSort.h"
#include "Fila.h"

//#define MAX 100000

int main()
{
    printf("=== QUICKSORT ===\n");
    int quant;
    int formaOrd;
    int usarNovamente;
    TFilaSequencial fila1;
    
    do{
        fila1=criarFilaSequencial();
        quant=-1;
        formaOrd=-1;
        usarNovamente=-1;
        
        do{
            printf("\nPrimeiramente digite a quantidade de valores para o vetor: \n");
            printf("[0] 100\n[1] 1.000\n[2] 10.000\n[3] 100.000\n\n");
            
            quant=escolheQuantValores();
            //printf("%d",quant);
            if (quant==-1) printf("valor invalido digite novamente!\n\n");
            
        }while(quant==-1);
        
        fila1=criaVetor(&fila1,quant);
        
        printf("\nOs valores gerados estão sendo exibidos a seguir: \n");
        imprimirTodosElementos(&fila1);
        
        do{
            printf("\n\nAgora escolha a forma que este vetor será ordenado: \n");
            printf("[0] ordem crescente\n[1] ordem decrescente\n[2] ordem aleatória \n\n");
            
            formaOrd=escolheFormaOrdenecao();
            if (formaOrd==-1) printf("valor invalido digite novamente!\n\n");
        
        }while(formaOrd==-1);
        
        fila1=ordenaVetor(&fila1, formaOrd);
        
        printf("\n\nApós essa operação agora os valores estão ordenados da forma escolhida: \n");
        imprimirTodosElementos(&fila1);
        imprimeRelatorioCompMonv(&fila1);
        
        printf("\nDeseja usar o programa novamente? \n[0] SIM\n[outro valor] NAO\n\n");
        scanf("%d",&usarNovamente);
        
    }while(usarNovamente==0);
    
    printf("\nObrigado por usar!");
    
    return 0;
}
