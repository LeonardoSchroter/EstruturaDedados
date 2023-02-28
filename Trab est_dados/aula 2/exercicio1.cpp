#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "util.h"

Celula *popular(Celula *lista, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        lista = inserirListaSimplesSemDuplicados(rand() % 5, lista);
    }
    return lista;
}

int main() {
    Celula *lista = NULL;
    lista = popular(lista, 10);
    exibirListaSimples(lista);

    //contar celulas
    contarListaSimples(lista);
    //localizar o menor valor
     localizarMenorValor(lista);
    //localizar o maior valor
     localizarMaiorValor(lista);
    //calcular e exibir a média
    calculaMedia(lista);
    //fazer uma versao do inserir que nao permita duplicados
    
    return 1;
}