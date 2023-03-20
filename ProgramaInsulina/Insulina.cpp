#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


#include "util.h"
int main(){
    Celula * list;
    ifstream procurador;

    lerArquivoOrdenado(list);

    exibirListaSimples(list);

    return 1;
}