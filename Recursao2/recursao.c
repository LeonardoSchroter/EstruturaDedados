/**
 * Recursão == repetição
 *  - void
 *  - return
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

void popularVetorR(int *v, int n, int faixa) {
    if (n > 0) {

        popularVetorR(v, n-1, faixa); //ponto de recursao
        
        v[n-1] = rand() % faixa;
    }
}

void exibirVetorR(int *v, int n) {
    if (n > 0) {

        exibirVetorR(v, n-1); //ponto de recursao
        
        printf("[%d]:%d\n", n-1, v[n-1]);
    }
}

int contarParesR(int *v, int n) {
    if (n > 0){
        if (v[n-1] % 2 == 0) {
            return 1 + contarParesR(v, n-1);//par localizado e empilhando
        } 
        return 0 + contarParesR(v, n-1);//par nao localizado e empilhando
    } 
    return 0; //ponto de início do desempilhamento
}

int somarR(int *v, int n) {
    if (n > 0){
        return v[n-1] + somarR(v, n-1);//par localizado e empilhando        
    } 
    return 0; //ponto de início do desempilhamento
}

int menorR(int *v, int n) {
    if (n > 1) {
        int vemDeCima = menorR(v, n-1);
        if (vemDeCima < v[n-1])
            return vemDeCima;
        return v[n-1];
    }
    return v[n - 1]; //assume-se que o menor é o primeiro elemento, posicao 0
}

int maiorR(int *v, int n) {
    if (n > 1) {
        int vemDeCima = maiorR(v, n-1);
        if (vemDeCima > v[n-1])
            return vemDeCima;
        return v[n-1];
    }
    return v[n - 1]; //assume-se que o menor é o primeiro elemento, posicao 0
}

int contarImparesR(int *v, int n) {
    if (n > 0){
        if (v[n-1] % 2 != 0) {
            return 1 + contarImparesR(v, n-1);//par localizado e empilhando
        } 
        return 0 + contarImparesR(v, n-1);//par nao localizado e empilhando
    } 
    return 0; //ponto de início do desempilhamento
}

void substituirR(int *v, int n, int val, int dest){
    if (n>0){
        if(v[n-1] == val) 
            v[n-1] = dest;
      
        substituirR(v, n - 1, val, dest);
    }
}

int main() {
    int vetor[TAM];
  
    srand(time(NULL));
    popularVetorR(vetor, TAM, 10);
    exibirVetorR(vetor, TAM);

    printf("Total de pares:%d\n", contarParesR(vetor, TAM));
    printf("Total de impares:%d\n", contarImparesR(vetor, TAM));
    printf("A soma dos elementos:%d\n", somarR(vetor, TAM));
    printf("O menor elemento: %d\n", menorR(vetor, TAM));
    printf("O maior elemento: %d\n", maiorR(vetor, TAM));
    substituirR(vetor, TAM, 2, 5);
    printf("Novo vetor :\n");
    exibirVetorR(vetor, TAM);
    return 1;
}