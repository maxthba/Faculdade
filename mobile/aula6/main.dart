class Pessoa {
    String nome;
    double peso;
    double altura;
    double? imc;

    Pessoa(this.nome, this.peso, this.altura){
        this.calcularImc();
    }

    void calcularImc(){
        this.imc = (this.peso / (this.altura * this.altura));
    }
}

void main(){
    Pessoa p1 = Pessoa('Max', 60, 1.76);
    
}