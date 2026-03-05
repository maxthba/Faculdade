class Veiculo {
  String renavam;
  String chassi;
  String? marca;
  int? anoFabricacao;

  Veiculo(this.renavam, this.chassi);

  bool ehIgual(Veiculo outro){
    if(this.renavam == outro.renavam && this.chassi == outro.chassi){
      return true;
    } else{
      return false;
    }
  }

  @override
  bool operator ==(Object other) {
      if(identical(this, other) ||
      (other is Veiculo &&
          this.renavam == other.renavam &&
          this.chassi == other.chassi)){
            return true;
          } 
          return false;
  }
}

void main(){
  // quando instanciamos classes nossas 
  // por padrão cada instancia ocupara lugares
  // diferentes em memoria mesmo que os dados sejam identicos.
  // Veiculo v1 = Veiculo('123', 'ABC');
  // cuidado retire o override para comparar endereços de memoria.
  Veiculo v1 = Veiculo('456', 'BCD');
  Veiculo v2 = Veiculo('456', 'BCD');
  v1.marca = 'honda';
  //comparando igualdade (e isso eh subjetivo no Dart)
  //por padrao vc esta comparando enderços de alocação.
  if(v1== v2){
    print('mesmos veiculos(de conteudo)');
  } else{
    print('veiculos diferentes');
  }
  if(v1.ehIgual(v2)){
    print('veiculos iguais de acordo com o metodo equals');
  } else{
    print('veiculos diferentes de acordo com o metodo equals');
  }
}

/*void main(){
    // entendendo comparações
    //string internig 
    String a = 'oi';
    String b = 'oi';
    //identical compara referencia de memoria de duas instancias
    bool mesmaRef = identical(a,b);
    if(mesmaRef){
        print('String iguais mesma referencia');
    } else{
        print('Strings diferentes');
    }
}*/

