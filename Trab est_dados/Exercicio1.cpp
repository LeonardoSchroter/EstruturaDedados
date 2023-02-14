#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <fstream>

using namespace std;

#include "pilha.h"

int main(){
    ifstream procurador;

    Celula *pilha = NULL;
    string nomeArquivo = "Comandos.txt";

    procurador.open(nomeArquivo);
    int valor;

    string linha;
    do {
        getline(procurador,linha);
        
        if (linha == "") break;
        
        
        if(linha[0]=='I'){
            linha = linha.substr(1, 40);
            
            int num = stoi(linha);
            pilha = inserir(num,pilha);
        }
        else if(linha[0] =='E'){
            cout << "Exibindo pilha de comandos" << endl;
            exibir(pilha);            
        }
        else{
            pilha = remover(pilha);
        }
        
    } while(!procurador.eof());
    procurador.close();



    return 1;
}