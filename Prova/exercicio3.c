// 3) Faça um método recursivo que receba um vetor de inteiros,
//  seu tamanho e um valor de inicialização. 
//  O método deve colocar em todas as posições do vetor o valor passado para a incialização.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void exibirR(int *v, int n) {
    if (n > 0) {
        exibirR(v, n - 1);
        printf("[%d]:%d\t",n - 1, v[n - 1]);
    }
}

void popularR(int *v, int n, int inicializacao) {
    if (n > 0) {
        v[n - 1] = inicializacao;
        popularR(v, n - 1, inicializacao);
    }
}

int main(){
    int vetor[TAM];
    srand(time(NULL));
    popularR(vetor, TAM, 7);
    exibirR(vetor, TAM);
}
