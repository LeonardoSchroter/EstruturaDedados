// 4) Faça um método recursivo que receba uma matriz inteira e quadrada,
// A a quantidade de linhas e a quantidade de colunas. O método deve exibir somente os números pares,
// indicando a linha e a coluna do número.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5


void popular(int matriz[TAM][TAM], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            matriz[i][j] = rand() % 50;
        }
    }
}

void exibir(int matriz[TAM][TAM], int lin, int col) {
    for (int i = 0; i <= lin-1; i++) {
        for (int j = 0; j <= col-1; j++) {
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
}

void exibirParesR(int matriz[TAM][TAM], int lin, int col, int backLin, int backcol){
    if (col > 0) {
        if(matriz[lin-1][col-1] % 2 == 0){
            exibirParesR(matriz, lin, col - 1, backLin, backcol);
            printf("[%d][%d] = %d\n",lin -1 ,col - 1, matriz[lin - 1][col - 1]);
        }
        else {
            exibirParesR(matriz, lin, col - 1, backLin, backcol);
        }
    } else if (lin - 1 > 0) {
        exibirParesR(matriz, lin - 1, backcol ,backLin, backcol);
    }
}

int main(){
    int matriz[TAM][TAM];
    srand(time(NULL));
    popular(matriz, TAM, TAM);
    exibir(matriz, TAM, TAM);
    printf("\n");
    exibirParesR(matriz, TAM, TAM, TAM, TAM);
}