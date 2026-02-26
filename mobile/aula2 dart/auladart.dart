/*
  uma classe que representa apenas dados de algo do mundo real, chamamos de classe de entidade(entity class)
*/
class Pessoa {
  String? nome;
  String? dataNascimento;
  double? peso;
  double? altura;
  void imprimir(){
    print('nome: ${nome}');
    print('data de nascimento: ${dataNascimento}');
    print('peso: ${peso}');
    print('altura: ${altura}');
  }
}

class Estudante extends Pessoa {
  String? registroAcademico;
  void imprimir(){
    super.imprimir();
    print('Registro Academico: ${registroAcademico}');
  }
}
void main() {
  //criando uma instancia da classe pessoa
  //chamamos isso de "INSTANCIAR UM OBJETO PESSOA"
  var p1 = Pessoa();
  p1.nome = 'Joaquim';
  p1.dataNascimento = '2000-11-01';
  p1.peso = 80.0;
  p1.altura = 1.70;
  
  var p2 = Pessoa();
  p2.nome = 'Maria';
  p2.dataNascimento = '2000-11-22';
  p2.peso = 70;
  p2.altura = 1.65;
  
  p1.imprimir();
  p2.imprimir();
  
  
  //instanciar um estudante de exemplo
  var e1 = Estudante();
  e1.nome = 'Max';
  e1.dataNascimento = '2006-11-25';
  e1.peso = 64.1;
  e1.altura = 1.76;
  e1.registroAcademico = '2502350052735';
  e1.imprimir();
}
