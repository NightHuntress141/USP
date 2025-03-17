package Caneta;

// Public -> Faz referencia a visibilidade dessa classe, podendo ser privada ou pública
public class Caneta{

    // Criando os campos (variáveis de instâncias) de uma classe -> Armazenam valores 
    // para o objeto utilizar
    public String modelo;
    public String cor;
    public int ponta;
    public boolean tampada;

    // Construtor parametrizado -> responsável por inicializar os objetos com os valores recebidos
    public Caneta(String modelo, String cor, int ponta, boolean tampada){
        // Aqui podemos podemos fazer com que os objetos inicializem com valores já definidos
        this.modelo = modelo;
        this.cor = cor;
        this.ponta = ponta;
        this.tampada = tampada;
        // No código apresentado, a palavra-chave this é usada para referenciar os atributos da 
        // própria instância do objeto. Como os parâmetros do construtor têm os mesmos nomes que 
        // os atributos da classe, o this. é necessário para diferenciar entre eles. 
    }

    // Construtor não parametrizado -> responsável por inicializar os objetos com os valores já pré-definidos
    public Caneta() {
        this.modelo = "Bic";
        this.cor = "Azul";
        this.ponta = 1;
        this.tampada = true;
    }

    // Construtor parametrizado que ainda pode colocar valores pré-definidos
    /*public Caneta(String modelo, String cor, int ponta, boolean tampada) {
        this.modelo = (modelo != null) ? modelo : "Bic";
        this.cor = (cor != null) ? cor : "Azul";
        this.ponta = (ponta > 0) ? ponta : 1;
        this.tampada = tampada;
    }*/
    
    // Criando os métodos
    public void status(){
        System.out.println("Modelo: " + this.modelo);
        System.out.println("Cor: " + this.cor);
        System.out.println("Ponta: " + this.ponta);
        System.out.println("Está tampada? " + this.tampada);
    }
    public boolean AbrirCaneta(){
        return this.tampada = false;
    }
    public boolean FecharCaneta(){
        return this.tampada = true;
    }
}

