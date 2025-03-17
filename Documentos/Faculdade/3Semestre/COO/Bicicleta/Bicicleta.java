package Bicicleta;

public class Bicicleta {

    private int cadência; 
    private int marcha;
    private int velocidade;
    private int id;

    // Static -> Faz uma variável de classe
    private static int númeroDeBicicletas = 0;

    public Bicicleta(int cadênciaInicial, int velocidadeInicial, int marchaInicial){

        marcha = marchaInicial;
        cadência = cadênciaInicial;
        velocidade = velocidadeInicial;

        /* E se colocar o mesmo nome? Nesse caso, deve se colocar o "this." 
        this.marcha = marcha;
        this.cadência = cadência;
        this.velocidade = velocidade;
        */

        // incrementa o número de bicicletas e o atribui como identificador
        id = ++númeroDeBicicletas;
    }

    // Método do tipo Getter
    public int getID() {
        return id;
    }
    
    public static int getNúmeroDeBicicletas() {
        return númeroDeBicicletas;
    }
} 
