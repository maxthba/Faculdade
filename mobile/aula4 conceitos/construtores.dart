class Carro {
  String? marca;
  String? modelo;
  int? anoFabricacao;
  int? anoModelo;
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

  bool isvalid(){
    if(marca == null || marca!.isEmpty){
      return false;
    }
    if(modelo == null || modelo!.isEmpty){
      return false;
    }
    if(anoFabricacao == null || anoFabricacao! < 1886 || anoFabricacao! > 2100){
      return false;
    }
    if(anoModelo != null && (anoModelo! < 1886 || anoModelo! > 2100)){
      return false;
    }
    return true;
  }

  void imprimir(){
    if(isvalid()){
      print('Marca: ${marca}');
      print('Modelo: ${modelo}');
      print('Ano de fabricacao: ${anoFabricacao}');
      if(anoModelo == null){
        print('Ano de modelo nao informado');
      } else{
        print('Ano do modelo: ${anoModelo}');
      }
      if(chassi == null){
        print('Chassi nao informado');
      } else{
        print('Chassi: ${chassi}');
      }
    } else{
      print('carro da marca :${marca}. Modelo ${modelo}. eh invalido');
    }
  }
}

void main(){
  Carro c1 = Carro('Toyota', 'Yaris', 2023);
  Carro c2 = Carro('', '', -1900);
  c1.imprimir();
  c2.imprimir();
}