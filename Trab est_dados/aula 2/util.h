typedef struct no {
    int valor;
    struct no *prox;
} Celula;

Celula *inserirListaSimples(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    Celula *p, *pR;

    //depositar valores
    novo->valor = valor;
    novo->prox = NULL;

    //para a primeira alocação
    if (!lista) return novo;

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
}

void exibirListaSimples(Celula *lista) {
    if (!lista) return;

    Celula *p;
    for (p = lista; p; p = p->prox) {
        cout << p->valor << "\t";
    }
    cout << endl;
}

void contarListaSimples(Celula *lista) {
    if (!lista) return;
    int i=0;
    Celula *p;
    for (p = lista; p; p = p->prox) {
        i++;
    }
    cout <<"A quantidade de elementos da lista eh: " << i << endl;
}

void localizarMenorValor(Celula *lista) {
    if (!lista) return;
    int m= lista->valor;
    Celula *p;
    for (p = lista; p; p = p->prox) {
        if(m > p->valor){
            m = p->valor;
        };
    }
    cout <<"O menor elemento da lista eh: " << m << endl;
}

void localizarMaiorValor(Celula *lista) {
    if (!lista) return;
    int m= lista->valor;
    Celula *p;
    for (p = lista; p; p = p->prox) {
        if(m < p->valor){
            m = p->valor;
        };
    }
    cout <<"O maior elemento da lista eh: " << m << endl;
}

void calculaMedia(Celula *lista) {
    if (!lista) return;
    float m=0; 
    int c = 0;

    Celula *p;
    for (p = lista; p; p = p->prox) {
       m= m+ p->valor;
       c++;
    }
    m = m/c;
    cout <<"a media dos elemento da lista eh: " << m << endl;
}

Celula *inserirListaSimplesSemDuplicados(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    Celula *p, *pR;

    //depositar valores
    novo->valor = valor;
    novo->prox = NULL;

    //para a primeira alocação
    if (!lista) return novo;

    Celula *pc;
    for (pc = lista; pc; pc = pc->prox) {
        if(valor == pc->valor){
            cout << "Valor ja contido na lista" << endl;
            free(novo);
            return lista;
        }
    }
    cout << endl;

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
}