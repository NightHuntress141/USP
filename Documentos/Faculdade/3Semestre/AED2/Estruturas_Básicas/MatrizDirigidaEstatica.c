#include <stdio.h>
#include <stdbool.h>

#define V 5  // Número fixo de vértices

// Matriz de adjacência estática
int matriz[V + 1][V + 1];  // Índices de 0 a V

// Inicializa a matriz com zeros
void inicializar() {
    for (int i = 0; i <= V; i++) {
        for (int j = 0; j <= V; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Verifica se há uma aresta entre i e j
bool arestaExiste(int i, int j) {
    return matriz[i][j] == 1;
}

// Insere uma aresta no grafo dirigido
void inserirAresta(int i, int j) {
    matriz[i][j] = 1;
}

// Retorna o grau de saída de um vértice i
int grauSaida(int i) {
    int grau = 0;
    for (int j = 1; j <= V; j++) {
        if (matriz[i][j] == 1) grau++;
    }
    return grau;
}

int main() {
    inicializar();  // Inicializa a matriz

    inserirAresta(2, 2);

    if (arestaExiste(2, 2)) {
        printf("Aresta entre 2 e 2 existe.\n");
    }

    int grau = grauSaida(2);
    printf("Grau de saída do vértice 2: %d\n", grau);

    return 0;
}
