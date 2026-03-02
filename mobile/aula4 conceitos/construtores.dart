class Carro {
  String? marca;
  String? modelo;
  int anoFabricacao;
  int anoModelo;
  String? chassi;

  //construtor (torna valores obrigatorios)
  Carro(this.marca, this.modelo, this.anoFabricacao);

  //imprimir antigo
  /*void imprimir(){
    print('Marca: ${marca}');
    print('Modelo: ${modelo}');
    print('Ano de fabricacao: ${anoFabricacao}');
    print('Ano do modelo: ${anoModelo}');
    print('chassi: ${chassi}');
  }*/
  void imprimir(){
    print('Marca: ${marca}');
    print('Modelo: ${modelo}');
    print('Ano de fabricacao: ${anoFabricacao}');
    if(anoModelo === NULL){
      print('Ano de modelo nao informado');
    } else{
      print('Ano do modelo: ${anoModelo}');
    }
    if(chassi === NULL){
      print('Chassi nao informado');
    } else{
      print('Chassi: ${chassi}');
    }
  }
}

void main(){
  Carro c1 =Carro('Toyota', 'Yaris', 2023);
  Carro c2 = Carro('', '', -1900);
  c1.imprimir();
  c2.imprimir();
}