/* 15. Seja um grafo g não-conexo e não-dirigido. Escreva uma função para contar a quantidade de 
grupos disjuntos de vértices mutuamente alcançáveis em g. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5

typedef struct r{
    struct r *prox;
    int adj;
} NO;

typedef struct{
    NO* inicio;
    int flag;
} vertice;

void inicializar(vertice *g){
    int i;
    for(i = 1; i <= V; i++) g[i].inicio = NULL;
}

NO* arestaExiste(vertice *g, int i, int j, NO** ant){
    // Recebemos como argumento um ponteiro auxiliar que indicara o vértice anterior
    *ant = NULL;
    // Criamos um ponteiro p que vai iniciar do começo de cada lista (vertice)
    NO* p = g[i].inicio;
    // Loop que percorre lista por lista em busca da aresta que aponta de um vértice para outro
    while(p){
        if(p -> adj == j) return p; // Achou o vértice
        *ant = p; // Anterior recebe o valor do atual
        p = p -> prox; // Atual recebe o valor do pŕoximo
    }
    return NULL; //aresta não existe
}

bool inserirAresta(vertice *g, int i, int j) {
    if (!arestaExiste(g, i, j, NULL)) {
        NO* novo = (NO*)malloc(sizeof(NO));
        novo->adj = j;
        novo->prox = g[i].inicio;
        g[i].inicio = novo;
    }
    if (!arestaExiste(g, j, i, NULL)) {
        NO* novo = (NO*)malloc(sizeof(NO));
        novo->adj = i;
        novo->prox = g[j].inicio;
        g[j].inicio = novo;
    }
    return true;
}

bool excluiAresta(vertice *g, int i, int j) {
    // Criamos um ponteiro auxiliar que indicara o vértice anterior
    NO *ant;
    // Recebemos o valor achado que indica o vértice i que aponta para j
    NO *atual = arestaExiste(g, i, j, &ant);

    if (!atual) return false; //Não existe, não tem como excluir

    // Se existe um anterior, então apenas aponte para o próximo
    if (ant) 
        ant->prox = atual->prox;
    // Caso contrário, se o elemento está no início da lista
    else 
        g[i].inicio = atual->prox;

    free(atual); // Libera espaço

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
    free(g);
}

void zerarFlag(vertice* g){
    for(int i = 1; i <= V; i++){
        g[i].flag = 0;
    }
}

bool buscaProf(vertice *g, int i) {
    g[i].flag = 1; // Vértice está sendo visitado
    NO* p = g[i].inicio;
    while (p) {
        if (g[p->adj].flag == 1) return true; // Encontrou um ciclo
        if (g[p->adj].flag == 0 && buscaProf(g, p->adj)) return true;
        p = p->prox;
    }
    g[i].flag = 2; // Vértice já foi completamente processado
    return false;
}



int main() {
    vertice *g = (vertice*) malloc((V + 1) * sizeof(vertice));
    inicializar(g);

    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 2, 4);
    inserirAresta(g, 3, 5);
    
    free(g);
    return 0;
}