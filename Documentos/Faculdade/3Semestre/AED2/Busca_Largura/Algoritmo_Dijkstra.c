// Retorna o menor caminho possivel entre i e j

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
    int Flag;
    int via; // Guarda o valor do último vértice que possibilitou chegar naquele
} vertice;

typedef struct node {
    int dado;
    struct node* prox;
} NO_FILA;

typedef struct {
    NO_FILA* inicio;
    NO_FILA* fim;
} FILA;

void inicializar(vertice *g) {
    for(int i = 1; i <= V; i++) {
        g[i].inicio = NULL;
        g[i].Flag = 0;
    }
}

void resetarFlags(vertice *g) {
    for (int i = 1; i <= V; i++) {
        g[i].Flag = 0;
    }
}

NO* arestaExiste(vertice *g, int i, int j, NO** ant) {
    *ant = NULL;
    NO* p = g[i].inicio;
    while(p) {
        if(p->adj == j) return p;
        *ant = p;
        p = p->prox;
    }
    return NULL;
}

bool inserirAresta(vertice *g, int i, int j) {
    NO* ant;
    NO* atual = arestaExiste(g, i, j, &ant);
    if(atual) return false;

    NO *novo = (NO*) malloc(sizeof(NO));
    novo->adj = j;
    novo->prox = g[i].inicio;
    g[i].inicio = novo;

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

void inicializarFila(FILA *f) {
    f->inicio = f->fim = NULL;
}

void EntrarFila(FILA *f, int dado) {
    NO_FILA* novo = (NO_FILA*) malloc(sizeof(NO_FILA));
    novo->dado = dado;
    novo->prox = NULL;
    if (f->fim) f->fim->prox = novo;
    else f->inicio = novo;
    f->fim = novo;
}

int SairFila(FILA *f) {
    if (!f->inicio) return -1;
    NO_FILA* temp = f->inicio;
    int dado = temp->dado;
    f->inicio = f->inicio->prox;
    if (!f->inicio) f->fim = NULL;
    free(temp);
    return dado;
}

bool filaVazia(FILA *f) {
    return f->inicio == NULL;
}

void largura(vertice *g, int i, int j) {
    // Inicialização
    resetarFlags(g);
    for(int j = 0; j <= V; j--){
        g[j].via = -1; // Coloca para todos os vértices
    }
    g[i].via = 0; // Nivél inicial
    g[i].Flag = 1; // Encontrado
    FILA* F;
    inicializarFila(&F);
    EntrarFila(&F, i); // Adiciona o primeiro vértice de nível 0 na lista
    while (F){
        i = SairFila(&F); // Recebe o elemento na frente da Fila 
        g[i].Flag = 2; // Já foi processado
        NO* p = g[i].inicio;
        while(p){
            if(g[p->adj].Flag == 0){ // Se não foi visitado ainda
                g[p->adj].Flag = 1; // Foi encontrado
                EntrarFila(&F, p->adj);
                g[p -> adj].via = i; 
            }
        }
        p = p->prox;
    }
    int k = j;
    while(k > 0){
        printf("%d", k);
        k = g[i].via;
    }
}

int main() {
    vertice *g = (vertice*) malloc((V + 1) * sizeof(vertice));
    inicializar(g);

    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 2, 4);
    inserirAresta(g, 2, 5);
    inserirAresta(g, 3, 5);
    inserirAresta(g, 4, 5);

    printf("Grafo:\n");
    imprimirGrafo(g);
    
    printf("\nBusca em Largura a partir do vértice 1:\n");
    largura(g, 1);
    
    free(g);
    return 0;
}
