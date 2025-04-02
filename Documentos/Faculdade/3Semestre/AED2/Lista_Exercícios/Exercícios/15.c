#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5

typedef struct r {
    struct r *prox;
    int adj;
} NO;

typedef struct {
    NO* inicio;
    int flag;
} vertice;

void inicializar(vertice *g) {
    for (int i = 1; i <= V; i++) {
        g[i].inicio = NULL;
        g[i].flag = 0;
    }
}

NO* arestaExiste(vertice *g, int i, int j, NO** ant) {
    *ant = NULL;
    NO* p = g[i].inicio;
    while (p) {
        if (p->adj == j) return p;
        *ant = p;
        p = p->prox;
    }
    return NULL;
}

bool inserirAresta(vertice *g, int i, int j) {
    if (!arestaExiste(g, i, j, NULL)) {
        NO* novo = (NO*)malloc(sizeof(NO));
        if (!novo) return false;
        novo->adj = j;
        novo->prox = g[i].inicio;
        g[i].inicio = novo;
    }
    if (!arestaExiste(g, j, i, NULL)) {
        NO* novo = (NO*)malloc(sizeof(NO));
        if (!novo) return false;
        novo->adj = i;
        novo->prox = g[j].inicio;
        g[j].inicio = novo;
    }
    return true;
}

bool excluiAresta(vertice *g, int i, int j) {
    NO *ant;
    NO *atual = arestaExiste(g, i, j, &ant);
    if (!atual) return false;

    if (ant) 
        ant->prox = atual->prox;
    else 
        g[i].inicio = atual->prox;

    free(atual);
    return true;
}

void imprimirGrafo(vertice *g) {
    for (int i = 1; i <= V; i++) {
        printf("Vértice %d:", i);
        NO* p = g[i].inicio;
        while (p) {
            printf(" -> %d", p->adj);
            p = p->prox;
        }
        printf("\n");
    }
}

void liberarGrafo(vertice *g) {
    for (int i = 1; i <= V; i++) {
        NO* atual = g[i].inicio;
        while (atual) {
            NO* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
}

void zerarFlag(vertice* g) {
    for (int i = 1; i <= V; i++) {
        g[i].flag = 0;
    }
}

void buscaProf(vertice *g, int i) {
    g[i].flag = 1;
    NO* p = g[i].inicio;
    while (p) {
        if (g[p->adj].flag == 0) 
            buscaProf(g, p->adj);
        p = p->prox;
    }
    g[i].flag = 2;
}

int contarGruposDisjuntos(vertice* g) {
    zerarFlag(g);
    int grupos = 0;
    for (int i = 1; i <= V; i++) {
        if (g[i].flag == 0) {
            buscaProf(g, i);
            grupos++;
        }
    }
    return grupos;
}

int main() {
    vertice *g = (vertice*)malloc((V + 1) * sizeof(vertice));
    if (!g) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    inicializar(g);

    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 2, 3);
    inserirAresta(g, 4, 5);

    printf("Grafo original:\n");
    imprimirGrafo(g);

    int grupos = contarGruposDisjuntos(g);
    printf("\nQuantidade de grupos do grafo não dirigido desconexo: %d\n", grupos);

    liberarGrafo(g);
    free(g); // Liberar o grafo apenas uma vez, no final do programa.
    return 0;
}