abstract class Animal{
 void show(){
  print('tocando musica padrao... tambores...');
  }
 void hide(){
    print('fumacinha... puff.. sumiu...');
  }
}


class dog extends Animal{
  @override
  void show(){
    super.show();
    print('caminhando ate o centro... parou...');
  }
  void bark(){
    print('au au...');
  }
}

class cat extends Animal{
  @override
  void show(){
    super.show();
    print('pulando de arvore em arvore... parou no centro...');
  }
  void meow(){
    print('miauu...');
  }
}

void main(){
  var c = cat();
  c.show();
  c.meow();
  c.hide();
  print('opções de palavras para a criança clicar');

  var d = dog();
  d.show();
  d.bark();
  d.hide();
  print('opções de palavras para a criança clicar');
}