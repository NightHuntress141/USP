/*
-> Códigos fundamentais para Grafos:
    - Inicialização (acertou)
    - Verificar se aresta existe (acertou)
    - Adicionar aresta (acertou)
    - Excluir aresta (errinho bobo)
    - Copiar Grafo
    - Grau de Saída e Entrada
    - Desalocar um Grafo
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 10 // Número de vértice que existem no grafo

typedef struct s{
    NO* inicio; //Ponteiro para o início da lista dos vértices adjacentes ao vértice que estamos analisando
    // Adicionamos o Flag aqui
}VERTICE;

typedef struct r{
    struct r* prox; //Ponteiro que aponta para estruturas do tipo NO e que guardará o próximo vértice
    int adj; //Guarda o valor do vértice adjacente
    // Adicionamos valores referentes às arestas aqui
}NO;

// Inicialização do Grafo
void inicializarGrafo(VERTICE* g){
    for(int i = 1; i <= V; i++){
        g[i].inicio = NULL;
    }
}

// Antes de adicionar ou excluir uma aresta, devemos verificar se ela existe
// A função recebe o grafo, e os valores dos vértices de origem (i) e destino (j). Ademais, é interessante adicionar um auxiliar chamado anterior para guardarmos
// o anterior 
// A função retorna um ponteiro para aquele nó
NO* existeAresta(VERTICE* g, int i, int j, NO** ant){
    *ant = NULL;

    NO* atual = g[i].inicio;
    // Percorrer a lista do vértice de origem (i) procurando o vértice de destino (j)
    while(atual){
        if(atual -> adj == j) return atual;
        *ant = atual;
        atual = atual -> prox;
    }
    return NULL;
}

// A função recebe o grafo, e os valores dos vértices de origem (i) e destino (j) que deseja-se criar novo
bool adicionarAresta(VERTICE* g, int i, int j){
    NO* ant;
    NO* atual = existeAresta(g, i, j, &ant);
    if(atual) return false; // Já existe

    NO* novo_no = (NO*) malloc(sizeof(NO));

    novo_no -> prox = g[i].inicio;
    novo_no -> adj = j;

    // Vai ser adicionado no começo da lista
    g[i].inicio = novo_no;

    return true;
}

bool excluirAresta(VERTICE* g, int i, int j){
    NO* ant;
    NO* atual = existeAresta(g, i, j, &ant);
    if(!atual) return false; // Não existe, não tem como excluir

    // Se existe um anterior, então apenas aponte para o próximo
    if (ant) 
        ant->prox = atual->prox;
    // Caso contrário, se o elemento está no início da lista
    else 
        g[i].inicio = atual->prox;

    free(atual);

    return true;
}

int main(){

    VERTICE g;
    inicializarGrafo(&g);


}


