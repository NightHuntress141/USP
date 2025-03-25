/* Dado um possível caminho {6, 2, 3, 1, 1, 1, 1, 2} verifique se é um caminho válido retornando
true ou false 
-> Grafo Dirigido
-> Não é um problema de busca: Devemos apenas Verificar se as arestas existem entre um vértice
                               adjacente e outro*/

boolean Verificar_Caminho(vertice *g, int C[]){
    int j;
    if(n < 2) return False;
    for(j = 0; j < (n - 1); j++){
        if(!ArestaExiste(g, c[j], c[j+1])) return false;
    }
    return true;
}

int main(){
    int c = {6,2,3,1,1,1,1,2}; // n = 8
    // Verifique se um caminho é válido retornando true ou false

}