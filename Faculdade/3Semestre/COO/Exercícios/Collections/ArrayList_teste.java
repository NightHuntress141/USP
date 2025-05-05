package Exercícios.Collections;

import java.util.ArrayList;

public class ArrayList_teste {
    public static void main(String[] args) {

        // Declarando nova array list que receberá strings
        // Observe que não é definido um indixe máximo, portanto é uma estrutura dinâmica, 
        // que crescerá seu espaço de memória conforme o usuário adicionar mais elementos
        ArrayList<String> nova_lista = new ArrayList<>();

        // Funções de adicionar e remover -> Observe que a operação de remover requer uma complexidade maior de execução, pois, ao remove rum elemento
        // os elementos de index maior do que ele devem ser movidos para uma casa a menos, então se um elemento de index 3 é removido, os elementos de maior index 4 e 5
        // devem ser movidos para ocupar, agora, as posições de index 3 e 4
        nova_lista.add("A");
        nova_lista.add("B");
        nova_lista.remove("A"); // Deleta A da lista
        // nova_lista.remove(1); -> Em teoria, deleta o elemento de index 1 (B), porém isso não funciona,
        // pois ao remover A primeiro da lista, B vai assumir o index 1
        nova_lista.remove(0);

        // Função contem e vazio
        if(nova_lista.contains("B")){
            System.out.println("A lista contém B");
        }
        if(nova_lista.isEmpty()){
            System.out.println("A lista está vazia");
        }

        nova_lista.clear();


    }
}
