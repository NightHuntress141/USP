package Exercícios.Collections;

import java.util.LinkedList;

public class LinkedList_teste {
    public static void main(String[] args) {
        // Declarando uma lista ligada, portanto seu funcionamento é dinâmico e não necessáriamente ocupam um bloco na memória,
        // mas estão ligadas a partir de ponteiros que apontam para o próximo elemento na lista
        LinkedList<Integer> nova_lista = new LinkedList<>();

        // Adicionando e removendo elementos -> Observe que a operação de remover nesse caso é muito menos complexa do que quando comparada
        // com a operção em ArraysLists, pois, nesse caso, não é necessário deslocar nenhum elemento, mas sim apenas mudar o ponteiro que aponta para 
        // o proximo da lista
        nova_lista.add(2);
        nova_lista.add(45);
        nova_lista.remove(0); // Perceba que nesse caso, estamos falando do index, não do valor em si
        nova_lista.remove(Integer.valueOf(45));

        nova_lista.clear();


    }
}