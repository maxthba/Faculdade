// Usando INTERFACE (classe abstrata sem implementação)
abstract class Animal {
  void show();
  void hide();
}

// Implementação de Dog
class Dog implements Animal {
  @override
  void show() {
    print('tocando musica padrao... tambores...');
    print('caminhando ate o centro... parou...');
  }

  @override
  void hide() {
    print('fumacinha... puff.. sumiu...');
  }

  void bark() {
    print('au au...');
  }
}

// Implementação de Cat
class Cat implements Animal {
  @override
  void show() {
    print('tocando musica padrao... tambores...');
    print('pulando de arvore em arvore... parou no centro...');
  }

  @override
  void hide() {
    print('fumacinha... puff.. sumiu...');
  }

  void meow() {
    print('miauu...');
  }
}

// Implementação de Duck
class Duck implements Animal {
  @override
  void show() {
    print('tocando musica padrao... tambores...');
    print('nadando no lago... parou no centro...');
  }

  @override
  void hide() {
    print('fumacinha... puff.. sumiu...');
  }

  void quack() {
    print('quaaaack....');
  }
}

void main() {
  var c = Cat();
  c.show();
  c.meow();
  c.hide();
  print('opções de palavras para a criança clicar');

  var d = Dog();
  d.show();
  d.bark();
  d.hide();
  print('opções de palavras para a criança clicar');

  var du = Duck();
  du.show();
  du.quack();
  du.hide();
  print('opções de palavras para a criança clicar');
}
