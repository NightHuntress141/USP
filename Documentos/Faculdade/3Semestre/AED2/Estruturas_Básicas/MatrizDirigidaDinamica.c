#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5

// Aloca dinamicamente a matriz de adjacência
int** criarMatrizAdjacencia() {
    int** m = (int**)malloc((V + 1) * sizeof(int*));
    for (int i = 0; i <= V; i++) {
        m[i] = (int*)calloc((V + 1), sizeof(int)); // Inicializa com zeros
    }
    return m;
}

// Libera a memória alocada para a matriz
void liberarMatriz(int** m) {
    for (int i = 0; i <= V; i++) {
        free(m[i]);
    }
    free(m);
}

// Verificação se há uma aresta entre i e j
bool arestaExiste(int** m, int i, int j) {
    return m[i][j] == 1;
}

// Inserir aresta para grafo dirigido
void inserirAresta(int** m, int i, int j) {
    m[i][j] = 1;
}

// Retornar o grau de saída de um vértice i
int grauSaida(int** m, int i) {
    int grau = 0;
    for (int j = 1; j <= V; j++) {
        if (m[i][j] == 1) grau++;
    }
    return grau;
}

int main() {
    int** m = criarMatrizAdjacencia();

    inserirAresta(m, 2, 2);

    if (arestaExiste(m, 2, 2)) {
        printf("Aresta entre 2 e 2 existe.\n");
    }

    int grau = grauSaida(m, 2);
    printf("Grau de saída do vértice 2: %d\n", grau);

    liberarMatriz(m);
    return 0;
}
