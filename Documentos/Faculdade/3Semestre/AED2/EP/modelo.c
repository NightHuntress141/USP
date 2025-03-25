//--------------------------------------------------------------
// COLOQUE OS NOMES DOS RESPONSÁVEIS AQUI: blablabla E blablabla
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// INFORME O NRO DO GRUPO CONFORME PLANILHA DIVULGADA
int grupo() {
  return 0;
}

// ######### ESCREVA O NROUSP AQUI
int nroUSP1() {
    return 0;
}

// E O SEGUNDO NROUSP AQUI, SE HOUVER
int nroUSP2() {
    return 0;
}

// elemento da lista de resposta - NAO ALTERE ESTA DEFINICAO
typedef struct estr {
      int adj; // um nro. de vertice
      struct estr *prox;
} NO;


// funcao principal
NO *equidistantes(int V, int A, int ij[], int *v1, int *v2);

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO *equidistantes(int V, int A, int ij[], int *v1, int *v2)
{
	NO* resp = NULL;

	// seu codigo AQUI
	//...

	return resp;
}



//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main() {


	// aqui vc pode incluir codigo de teste - mas não precisa entregar isso




	// o EP sera testado com uma serie de chamadas como esta
	NO* teste = null;
	teste = NO *equidistantes(int V, int A, int ij[], int *v1, int *v2);

}

// por favor nao inclua nenhum código abaixo da função main()
