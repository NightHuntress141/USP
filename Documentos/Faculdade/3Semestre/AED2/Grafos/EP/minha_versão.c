#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

/*
-> Estruturas complementares:
- FILA

-> Funções complementares:
- Todas relacionadas a fila -> Inicializar, entrar, sair, vazia
- Todas relacionadas a lista -> Inicializar, adicionar, imprimir

- Fazemos uma lista de distâncias dos outros vértices com busca em largura para o vértice v1 (Função Busca em Largura)
- Fazemos uma lista de distâncias dos outros vértices com busca em largura para o vértice v2 (Função Busca em Largura)
- Comparamos essas listas descontando os próprios valores de v1 e v2 e retornamos uma lista (Função equidistantes)
*/


// elemento da lista de resposta - NAO ALTERE ESTA DEFINICAO
typedef struct estr {
      int adj; // um nro. de vertice
      struct estr *prox;
} NO;

// Estruturas da Fila
typedef struct node {
    int dado;
    struct node* prox;
} NO_FILA;

typedef struct {
    NO_FILA* inicio;
    NO_FILA* fim;
} FILA;

// Funções da Fila
void EntrarFila(FILA *f, int dado) {
    NO_FILA* novo = (NO_FILA*) malloc(sizeof(NO_FILA));
    novo -> dado = dado;
    novo -> prox = NULL;
    if (f->fim) f-> fim -> prox = novo;
    else f -> inicio = novo;
    f -> fim = novo;
}

int SairFila(FILA *f) {
    if (!f -> inicio) return -1;
    NO_FILA* temp = f -> inicio;
    int dado = temp -> dado;
    f -> inicio = f -> inicio -> prox;
    if (!f -> inicio) f -> fim = NULL;
    free(temp);
    return dado;
}

bool FilaVazia(FILA *f) {
    return f -> inicio == NULL;
}

void caminhoMaiscurto(vertice* g, int i, int d, int V) {
    zerarFlag(g);
    int distancias[V + 1]; // Índices de 1 a V
    for (int k = 1; k <= V; k++) {
        distancias[k] = -1; // Inicializa com -1 (inacessível)
    }
    
    FILA f;
    inicializarFila(&f);
    entrarFila(&f, i);
    g[i].flag = 1;
    distancias[i] = 0;
    
    while (!filaVazia(&f)) {
        int atual = sairFila(&f);
        g[atual].flag = 2;
        
        NO* p = g[atual].inicio;
        while (p) {
            if (g[p->adj].flag == 0) {
                g[p->adj].flag = 1;
                distancias[p->adj] = distancias[atual] + 1;
                entrarFila(&f, p->adj);
            }
            p = p->prox;
        }
    }
    
    printf("Usuários relacionados a %d com até %d graus de distância:\n", i, d);
    for (int k = 1; k <= V; k++) {
        if (k == i) continue;
        if (distancias[k] != -1 && distancias[k] <= d) {
            printf("Grau entre %d e %d é %d\n", i, k, distancias[k]);
        }
    }
}

// Grafo de V vértices numeradas de 1 a V e A arestas. O vetor ij[] contém exatamente 2*A elementos, e cada par representa uma aresta i,j. 
NO* equidistantes(int V, int A, int ij[], int v1, int v2);

NO* equidistantes(int V, int A, int ij[], int v1, int v2){
	NO* resp = NULL;


	return resp;
}


int main() {


	// aqui vc pode incluir codigo de teste - mas n�o precisa entregar isso




	// o EP sera testado com uma serie de chamadas como esta
	NO* teste = NULL;
	teste = NO *equidistantes(int V, int A, int ij[], int *v1, int *v2);

}

// por favor nao inclua nenhum c�digo abaixo da fun��o main()
