// 5) Faça um método recursivo que receba uma matriz inteira e quadrada, 
// a quantidade de linhas e a quantidade de colunas. O método deve retornar a quantidade de números
// pares presentes na matriz.
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

int contarPares(int matriz[TAM][TAM], int lin, int col, int backLin, int backcol){
    if (col > 0) {
        if(matriz[lin-1][col-1] % 2 == 0){
            return 1 + contarPares(matriz, lin, col - 1, backLin, backcol);
        }
        else {
            return 0 + contarPares(matriz, lin, col - 1, backLin, backcol);
        }
    } else if (lin - 1 > 0) {
        return 0 + contarPares(matriz, lin - 1, backcol ,backLin, backcol);
    }
    return 0;
}

int main(){
    int matriz[TAM][TAM];
    srand(time(NULL));
    popular(matriz, TAM, TAM);
    exibir(matriz, TAM, TAM);
    printf("\n");
    printf("Ha %d numeros pares na matriz",contarPares(matriz, TAM, TAM, TAM, TAM));
}