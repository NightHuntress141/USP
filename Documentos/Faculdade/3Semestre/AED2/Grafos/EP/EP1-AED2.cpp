//-----------------------------------------------------------------------------------------------//
// COLOQUE OS NOMES DOS RESPONSÁVEIS AQUI: Ana Julia Silva de Oliveira E Rebecka Bocci Domingues //
//-----------------------------------------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// INFORME O NRO DO GRUPO CONFORME PLANILHA DIVULGADA
int grupo() {
  return 4;
}


// ######### ESCREVA O NROUSP AQUI
int nroUSP1() {
    return 14557202;
}


// E O SEGUNDO NROUSP AQUI, SE HOUVER
int nroUSP2() {
    return 15486608;
}


// elemento da lista de resposta - NAO ALTERE ESTA DEFINICAO
typedef struct estr {
      int adj; // um nro. de vertice
      struct estr *prox;
} NO;


// Estrutura: Grafo
typedef struct {
	NO* inicio;
	int flag;
} VERTICE;


// Estrutura: Fila
typedef struct {
	NO* inicio;
	NO* fim;
} FILA;


//-----------------//
// Funções da Fila //
//-----------------//


void InicializarFila(FILA* f) {
	f -> inicio = f -> fim = NULL;
}


void EntrarFila(FILA* f, int adj) {
	NO* novo = (NO*)malloc(sizeof(NO));
	novo -> adj = adj;
	novo -> prox = NULL;
	if (f -> fim) f -> fim -> prox = novo;
	else f -> inicio = novo;
	f -> fim = novo;
}


int SairFila(FILA* f) {
	if (!f -> inicio) return -1;
	NO* temp = f -> inicio;
	int adj = temp -> adj;
	f -> inicio = f -> inicio -> prox;
	if (!f -> inicio) f -> fim = NULL;
	free(temp);
	return adj;
}


bool FilaVazia(FILA* f) {
	return (f -> inicio == NULL);
}


//------------------//
// Funções da Lista //
//------------------//


void InserirLista(NO** lista, int valor) {
	NO* novo = (NO*)malloc(sizeof(NO));
	novo -> adj = valor;
	novo -> prox = *lista;
	*lista = novo;
}


//------------------//
// Funções do Grafo //
//------------------//


void InicializarGrafo(VERTICE *g, int V) {
    for (int i = 1; i <= V; i++) {
        g[i].inicio = NULL;
        g[i].flag = 0;
    }
}


void InserirAresta(VERTICE* g, int i, int j) {
    NO* ida = (NO*)malloc(sizeof(NO));
    if (!ida) return;
    ida->adj = j;
    ida->prox = g[i].inicio;
    g[i].inicio = ida;

    NO* volta = (NO*)malloc(sizeof(NO));
    if (!volta) return;
    volta->adj = i;
    volta->prox = g[j].inicio;
    g[j].inicio = volta;
}


VERTICE* TransformarEmGrafo(int V, int A, int ij[]) {
    VERTICE* g = (VERTICE*) malloc((V + 1) * sizeof(VERTICE));
    InicializarGrafo(g, V);
    for(int k = 0; k < A*2; k++){
        if(!(k % 2 == 0)) continue;
        InserirAresta(g, ij[k], ij[k+1]);
    }
    return g;
}


void ZerarFlag(VERTICE* g, int V) {
    for (int i = 1; i <= V; i++) {
        g[i].flag = 0;
    }
}


void BuscaLargura (VERTICE* g, int V, int i, int distancias[]) {
    ZerarFlag(g, V);
    FILA f;
    InicializarFila(&f);
    EntrarFila(&f, i);
    g[i].flag = 1;
    distancias[i] = 0;
    
    while (!FilaVazia(&f)) {
        int atual = SairFila(&f);
        g[atual].flag = 2;
        
        NO* p = g[atual].inicio;
        while (p) {
            if (g[p -> adj].flag == 0) {
                g[p -> adj].flag = 1;
                distancias[p -> adj] = distancias[atual] + 1;
                EntrarFila(&f, p -> adj);
            }
            p = p->prox;
        }
    }
}


//------------------//
// Função Principal //
//------------------//


NO* equidistantes(int V, int A, int ij[], int v1, int v2) {
	NO* resp = NULL;

    int distancias_v1[1+V];
    int distancias_v2[1+V];

    for(int k = 0; k <= V; k++) {
        distancias_v1[k] = -1;
        distancias_v2[k] = -1;
    }

    VERTICE* g = TransformarEmGrafo(V, A, ij);
    BuscaLargura(g, V, v1, distancias_v1);
    BuscaLargura(g, V, v2, distancias_v2);

    for(int h = 1; h <= V; h++) {
        if(distancias_v1[h] == distancias_v2[h] && distancias_v1[h] > 0 && distancias_v2[h] > 0) {
            InserirLista(&resp, h);
        }
    }

	return resp;
}
