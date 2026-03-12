
class Pessoa {
    final String nome;
    final double peso;
    final double altura;
    double? _imc;

    Pessoa(this.nome, this.peso, this.altura){
        this._calcularImc();
    }
    // acrescentar _ ("underline") no nome do metodo
    //modifica a acessibilidade dele,
    //tornando-o privado,
    //para que este metodo possa ser chamado apenas dentro na classe.
    void _calcularImc(){
        this._imc = (this.peso / (this.altura * this.altura));
    }

    //metodo para permitir que o imc seja lido de fora
    //pela instancia.
    double? get imc => _imc;
}