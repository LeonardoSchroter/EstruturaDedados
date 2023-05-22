// 2) Faça um método recursivo que receba uma matriz inteira e quadrada, a quantidade de linhas,
//  a quantidade de coluna a a linha que se deseja exibir.
// O método deve exibir a linha passad no parâmetro

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

void exibir(int matriz[TAM][TAM], int lin, int col) {
    for (int i = 0; i <= lin-1; i++) {
        for (int j = 0; j <= col-1; j++) {
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
}

void popularR(int matriz[TAM][TAM], int lin, int col, int backLin, int backcol)
{
    if (col > 0) {
        matriz[lin - 1][col - 1] = rand() % 10;
        popularR(matriz, lin, col - 1, backLin, backcol);
    } else if (lin > 0) {
        popularR(matriz, lin - 1, backcol ,backLin, backcol);
    }
}

// void exibirR(int matriz[TAM][TAM], int lin, int col, int backLin, int backcol, int busca) {
//     if (col > 0) {
//         if(lin-1 == busca){
//             exibirR(matriz, lin, col - 1, backLin, backcol, busca);
//             printf("%d\t",matriz[lin - 1][col - 1]);
//         }
//     } else if (lin-1 > 0) {
//         exibirR(matriz, lin - 1, backcol ,backLin, backcol, busca);
//         printf("\n");
//     }
// }

void exibirR(int matriz[TAM][TAM], int lin, int col, int busca) {
    if(col>0){
        printf("%d\t",matriz[busca][col - 1]);
        exibirR(matriz, TAM, col - 1, busca);
    }
}

int main(){
    int matriz[TAM][TAM];
    srand(time(NULL));
    popularR(matriz, TAM, TAM, TAM, TAM);
    exibir(matriz, TAM, TAM);
    printf("\n");
   // exibir(matriz, TAM, TAM);
    exibirR(matriz, TAM, TAM, 2);
}