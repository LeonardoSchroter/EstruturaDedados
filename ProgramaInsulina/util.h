typedef struct no {
    int valor;
    string data;
    int qtdOcorrencias;
    struct no *prox;
} Celula;


void exibirListaSimples(Celula *lista) {
    if (!lista) return;

    Celula *p;
    for (p = lista; p; p = p->prox) {
        cout << p->valor << "\t";
    }
    cout << endl;
}
Celula *lerArquivoOrdenado(  Celula *lista) {
    ifstream procurador;
    procurador.open("dados.dat");

    
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    Celula *p, *pR;
     
    //depositar valores
    
    string linha;
    //para a primeira alocação
    string data;
    int valor;
    do{
       
        getline(procurador,linha);
       
        try {
            valor = stoi(linha.substr(linha.find(" "),200));         
        } catch (int erro) {
            valor = stoi(linha.substr(linha.find("\t"),200));
        }
        data = linha.substr(0,linha.find(" "));
        
       
        

    //depositar valores
    novo->valor = valor;
    novo->data = data;
    novo->prox = NULL;
        //definir a posicao do valor na lista, ou seja, percorrer a lista
        for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
            if (valor < p->valor) {
                break;
            }
        }
        //no inicio
        if (p == lista) {
            novo->prox = lista;
            return novo;
        }
        //no fim
        if (!p) {
            pR->prox = novo;
            return lista;
        }
        //no meio
        pR->prox = novo;
        novo->prox = p;
        return lista;
    }while(procurador);
    procurador.close();
}
    


Celula *inserirOrdenado(int valor, string data, Celula *lista) {
    return NULL;
}

Celula *inserirControleOcorrencia(int valor, Celula *lista) {
    return NULL;
}


int contarElementos(Celula *lista) {
    int qtd = 0;
    Celula *p;
    for (p = lista; p; p = p->prox) {
        qtd++;
    }
    return qtd;
}

float media(Celula *lista) {

    return 1.0;
}

int mediana(Celula *lista) {
    //se a estrutura for de tamanho impar, devolver o valor da glicemia que está no meio da lista ordenada

    //se a estrutura for de tamanho par, devolver a media dos dois elementos mais ao centro da lista ordenada (parte inteira)
    return 1; 
}

int min(Celula *lista) {
    //numa lista ordenada é o primeiro elemento
    return 40;
}

int max(Celula *lista) {
    //numa lista ordenada é o ultimo elemento
    return 500;
}

Celula *moda(Celula *lista) {
    //retornar o valor que mais repete, se houver mais valores com a mesma quantidade, retornar 3 valores
    return NULL;
}