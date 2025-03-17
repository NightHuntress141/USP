package Caneta;

public class TesteCaneta {
    public static void main(String[] args){

        // Exibindo informações do objeto usando um construtor com parâmetros
        Caneta minhaCaneta = new Caneta("Pilot", "Preta", 2, true);
        minhaCaneta.status();

        // Trocando os valores
        minhaCaneta.cor = "rosa";
        minhaCaneta.status();
        
        // Criando um objeto usando um construtor sem parâmetros
        Caneta canetaPadrao = new Caneta();
        canetaPadrao.status();
        canetaPadrao.AbrirCaneta();
        canetaPadrao.status();
    }
}
