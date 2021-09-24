#include "Quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

/*
RECEBE UM VALOR DIGITADO PELO USUARIO DE ACORDO COM A MENSAGEM DO MAIN
E RETORNA O NUMERO DE POSICOES ESCOLHIDO
*/
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

/*
RECEBE UM VALOR DIGITADO PELO USUARIO DE ACORDO COM A MENSAGEM DO MAIN
E RETORNA O NUMERO DIGITADO, CASO ELE SEJA UM VALOR VALIDO (0, 1 OU 2)
*/
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

/*
ONDE É CRIADO O VETOR COM AS INFORMAÇOES ESCOLHIDAS
*/
void criaVetor(int *vetor, int quant,int formaOrd){
    int valor; //VAI SER USADO NO CASO DE VETOR ALEATORIO
    int posicao=0; //VAI SER USADO NO CASO DE VETOR DECRESCENTE
    
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
                valor=geraNumero(quant);
                vetor[i]=valor;
            }
    }
    
}

/*
GERA UM NUMERO ALEATORIO E RETORNA PARA SER INSERIDO NO VETOR
ESSE METODO É USADO NO CASO DO USUARIO ESCOLHER UM VETOR COM VALORES ALEATORIOS
*/
int geraNumero(int quant){
    int valor=rand()%(quant*2); //SERÁ INSERIDO NO VETOR UM NUMERO ENTRE 0 E O DOBRO DO N DE POSICOES
    return valor;
}

/*
PERCORRE O VETOR EXIBINDO SEUS ELEMENTOS
*/
void exibeVetor(int *vetor, int tamanho){
    for (int i=0;i<tamanho;i++){
        printf("posicao %d: %d\n",i,vetor[i]);
    }
}

/*
TROCA AS DUAS POSICOES PASSADAS POR PARAMETRO NAQUELE VETOR, ESTE TAMBEM 
PASSADO COMO PARAMETRO
*/
void trocaPosicoes(int *vetor, int posi1, int posi2){
    int aux = vetor[posi1];
    vetor[posi1] = vetor[posi2];
    vetor[posi2] = aux;
}

/*
MÉTODO A SER CHAMADO NA HORA DE COMECAR A ORDENACAO COM QUICKSORT
*/
void ordenaQuickSort(int *vetor,int *nCompMovi, int primeiraPosi, int ultimaPosi){
    if (primeiraPosi<ultimaPosi){ //TESTA SE HÁ PELO MENOS DOIS VALORES NO VETOR
    
        /*
        RETORNA A POSIÇÃO DO PIVO E ORGANIZA OS VALORES DE FORMA QUE OS NUMEROS ANTES 
        DELE SEJAM MENORES QUE ELE, E OS QUE ESTAO DEPOIS DELE SEJAM MAIORES QUE ELE,
        FAZENDO ASSIM, O PARTICIONAMENTO DO VETOR
        */
        int pivo=particiona(vetor,nCompMovi,primeiraPosi,ultimaPosi); 
        
        //ORDENA OS VALORES QUE ESTÃO ANTES DO PIVO
        ordenaQuickSort(vetor,nCompMovi,primeiraPosi,pivo-1);
        
        //ORDENA OS VALORES QUE ESTÃO DEPOIS DO PIVO
        ordenaQuickSort(vetor,nCompMovi,pivo+1,ultimaPosi);
    }
}

/*
METODO QUE ALEM DE RETORNAR A POSICAO DO PIVO, ORGANIZA OS VALORES DE FORMA QUE 
OS NUMEROS ANTES DELE SEJAM MENORES QUE ELE, E OS QUE ESTAO DEPOIS DELE SEJAM 
MAIORES QUE ELE
*/
int particiona(int *vetor,int *nCompMovi, int primeiraPosi, int ultimaPosi){
    
    /*
    PRIMEIRO SAO COLETADOS OS VALORES QUE ESTAO NO INICIO, MEIO E FIM DO VETOR
    PARA UM SER ESCOLHIDO COMO MEDIANA
    */
    int posiMeio = (primeiraPosi + ultimaPosi) / 2;
    int a = vetor[primeiraPosi];
    int b = vetor[posiMeio];
    int c = vetor[ultimaPosi];
    
    
    int posiMediana; //VAI GUARDAR A POSICAO DA MEDIANA ESCOLHIDA
    
    /*
    AGORA COMECAM OS TESTES PARA SABER QUAL A MEDIANA ENTRE OS TRES VALORES
    
    IMPORTANTE: AQUI COMECA A CONTAGEM DE COMPARACOES E MOVIMENTACOES ENTRE OS VALORES
    
    -SEMPRE QUE HOUVER UM "nCompMovi[0]++;" SIGNIFICA QUE ESTÁ SENDO INCREMENTADO O NUMERO
    DE COMPARACOES (AS COMPARACOES PARA ESCOLHA DA MEDIANA TAMBEM ESTAO SENDO CONTADAS)
    -SEMPRE QUE HOUVER UM "nCompMovi[1]++;" SIGNIFICA QUE ESTÁ SENDO INCREMENTADO O NUMERO
    DE MOVIMENTACOES
    */
    if (a < b) {
        nCompMovi[0]++;
        
        if (b < c) {
            nCompMovi[0]++;
            
            //SE a<b<c
            posiMediana = posiMeio;
        } else {
             nCompMovi[0]++;
            
            if (a < c) {
                 nCompMovi[0]++;
                
                //SE a<c<b
                posiMediana = ultimaPosi;
            } else {
                 nCompMovi[0]++;
                
                //SE c<a<b
                posiMediana = primeiraPosi;
            }
        }
    } else {
         nCompMovi[0]++;
        
        if (c < b) {
             nCompMovi[0]++;
            
            //SE c<b<a
            posiMediana = posiMeio;
        } else {
             nCompMovi[0]++;
            
            if (c < a) {
                 nCompMovi[0]++;
                
                //SE b<c<a
                posiMediana = ultimaPosi;
            } else {
                 nCompMovi[0]++;
                
                //SE b<a<c
                posiMediana = primeiraPosi;
            }
        }
    }
    
    /*
    APOS ESCOLHIDA O MEDIANA ELA TROCA DE POSICAO COM O VALOR DA ULTIMA POSICAO, 
    POIS USAMOS AQUI O MÉTODO DE CORMEN, ONDE O O PIVO ESCOLHIDO É SEMPRE O ELEMENTO
    QUE ESTÁ NA ULTIMA POSICAO
    */
    trocaPosicoes(vetor, posiMediana, ultimaPosi);
    nCompMovi[1]++;
    
    
    int pivo = vetor[ultimaPosi]; //O PIVO SERÁ O VALOR QUE ESTA NA ULTIMA POSICAO
    int i = primeiraPosi - 1;    //VARIAVEL QUE GUARDA A POSICAO QUE SERA TROCADA COM OUTRA DURANTE O TESTE A SEGUIR 
    
    /*
    PERCORRE O VETOR DA PRIMEIRA A ULTIMA POSICAO (DESCONSIDERANDO A POSICAO ONDE ESTA O PIVO)
    VINDA NO PARAMETRO, SEJA O VETOR INTEIRO OU SÓ PARTE DELE, CASO SEJA O MOMENTO EM QUE O 
    METODO SEJA CHAMADO RECURSIVAMENTE
    */
    for (int j = primeiraPosi; j < ultimaPosi; j++) { 
        
        /*
        TESTA SE AQUELE ELEMENTO É MENOR QUE O PIVO, CASO SEJA ELE É TROCADO DE
        POSICAO COM O VALOR QUE ESTÁ NA POSICAO i, NA ESQUERDA, E, APOS ISSO, 
        i É INCREMENTADO, PARA QUANDO FOR NECESSARIO UMA NOVA TROCA DE POSICOES,
        O i APONTE PARA A POSICAO QUE ESTÁ DEPOIS DA ULTIMA EM Q HOUVE TROCA
        */
        if (vetor[j] <= pivo) {
            i++;
            trocaPosicoes(vetor, i, j);
            
            nCompMovi[1]++;
        }
        nCompMovi[0]++;
        
    }
    
    /*
    APOS PERCORRER O VETOR, O PIVO É TROCADO DE POSICAO COM O VALOR QUE ESTÁ NA 
    POSICAO DEPOIS DA ULTIMA EM QUE HOUVE TROCA
    */
    trocaPosicoes(vetor, i + 1, ultimaPosi);
    
    nCompMovi[1]++;
    
    //E, ENFIM, É RETORNADO A POSICAO ONDE AGORA ESTÁ O PIVO
    return i + 1; 
}


/*
METODO QUE FAZ A COPIA DE UM VETOR, POR MEIO DO FOR E COLETADO UM VALOR DE UMA POSICAO
DE UM PRIMEIRO VETOR E ESTE É INSERIDO NA MESMA POSICAO DO SEGUNDO VETOR
*/
void copiaVetor(int *vetor, int *vetorAnterior, int quant){
    for (int i=0;i<quant;i++){
        vetorAnterior[i]=vetor[i];
    }
}
