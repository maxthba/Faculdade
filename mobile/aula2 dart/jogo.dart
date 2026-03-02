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

 class duck extends Animal{
  @override
  void show(){
    super.show();
    print('nadando no lago... parou no centro...');
  }
  void quack(){
    print('quaaaack....');
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

  var du = duck();
  du.show();
  du.quack();
  du.hide();
  print('opções de palavras para a criança clicar');
}