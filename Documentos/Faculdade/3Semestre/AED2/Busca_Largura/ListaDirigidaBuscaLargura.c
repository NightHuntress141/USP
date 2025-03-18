/* 1- Entrar i , marcar flag = 1
2- Enquanto houver fila
    3- i = sair
    4- marcar flag como 2 (concluido)
    5- entrar na fila todos os adjacentes não descobertos
6- Repete */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5

typedef struct r{
    // O campo prox é um ponteiro para o próximo nó da lista, permitindo criar listas encadeadas.
    struct r *prox;
    // O campo adj armazena o valor de um vértice adjacente 
    int adj;
    // Aqui, também poderia caber um campo "peso" para indicar valores em grafos ponderados
} NO;

typedef struct{
    // Possui apenas a cabeça da lista de adjacencia
    NO* inicio;
    int Flag;
} vertice;

void inicializar(vertice *g){
    int i;
    for(i = 1; i <= V; i++){
        g[i].inicio = NULL;
        g[i].Flag = 0;
    }
}

void resetarFlags(vertice *g) {
    for (int i = 1; i <= V; i++) {
        g[i].Flag = 0;
    }
}

// Essa função é responsável por verificar se existe uma aresta que aponta de um vértice i para um vértice j e
// retorna um ponteiro para uma estrutura do tipo NO
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

// Cria-se uma aresta de um vértice i (origem da aresta) para apontar para o vértice i (destino da aresta)
bool inserirAresta(vertice *g, int i, int j){
    // Criamos um ponteiro auxiliar que indicara o vértice anterior
    NO* ant;
    // Recebemos o valor achado que indica o vértice i que aponta para j
    NO* atual = arestaExiste(g, i, j, &ant);

    if(atual) return false; //Já existe

    NO *novo = (NO*) malloc(sizeof(NO)); // Alocamos um novo espaço na mémoria

    novo->adj = j; // Coloca o valor do vértice j
    novo->prox = g[i].inicio; // Faz com que o novo (j) aponte como proximo o vértice (i)

    // Insere o novo nó no início da lista de adjacência do vértice i
    g[i].inicio = novo; // O início da lista agora passa a ser o novo nó.

    return true;
}

void imprimirGrafo(vertice *g) {
    for (int i = 1; i < V; i++) {
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

void largura(vertice *g, int i){
    // Inicialização
    resetarFlags(g);
    FILA *F;
    inicializarFila(&F);
    EntrarFila(&F, i);
    g[i].Flag = 1; // Descoberto

    while(F){
        i = SairFila(&F);
        g[i].Flag = 2;
        NO* p = g[i].inicio;

        while(p){
            if(g[p -> adj].Flag == 0){
                g[p -> adj].Flag = 1;
                EntrarFila(&F, p -> adj);
            }
            p = p -> prox;
        }
    }
}

int main(){
    
}