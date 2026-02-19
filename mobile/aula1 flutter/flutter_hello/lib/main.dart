import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // o widget eh a raiz do aplicativo
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        // Esse eh o tema do aplicativo.
        //
        // tente isso: tente rodar seu aplicativo com "flutter run". voce vai ver que
        // o aplicativo tem uma barra de ferramentas roxa. entao, sem fechar o app,
        // tente mudar a seedColor no colorScheme embaixo de Colors.green
        // e entao faca um "hot reload" (salve as mudancas ou precione o botao de "hot
        // reload" em uma ide que suporte flutter, ou precione "r" se voce usou a linha de comando
        // para iniciar o app).
        //
        // note que o contador nao zerou; o app nao perde os dados durante o hot reaload
        //
        // isso funciona para codigos tambem, nao apenas valores: a maioria das mudancas de codigos podem ser
        // testadas apenas com um hot relaod.
        colorScheme: .fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  // esse widget eh a home page do seu aplicativo. eh estatal, significa
  // que tem um estado de objeto (definido abaixo) que contem campos que afeta 
  // como se parece.

  // essa classe eh a configuracao do estado. guarda um valor (nesse caso
  // um titulo) provido pelos parentes (nesse caso o widget do app) e
  // usado pelo build method of the State. campos em uma subclasse de um Widget sao
  // sempre marcados "final".

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;

  void _incrementCounter() {
    setState(() {
      // essa chamada para o setState diz para o Flutter framework que algo
      // mudou nesse estado, o que ocasiona em uma rerun do metodo de build abaixo 
      // para que o display possa mostrar os valores atualizados. se mudarmos
      // _counter sem chamar  setState(), entao o metodo de build nao vai ser chamado
      // novamente, e parecera que nada aconteceu.
      _counter++;
    });
  }

  @override
  Widget build(BuildContext context) {
    // esse metodo roda toda vez que o setState for chamado, por exemplo como eh feito
    // por _incrementCounter method abaixo.
    //
    // o framework do Flutter foi otimizado para criar metodos de rerodar builds rapido,
    // para que voce possa rebuildar qualquer coisa que precisa de atualizacao
    // ao inves de atualizar individualmente cada instancia.
    return Scaffold(
      appBar: AppBar(
        // tente isso: tente mudar a cor aqui para uma cor especifica (para
        // Colors.amber, talvez?) e ativar um hot reload para ver a AppBar
        // mudar de cor enquanto as outras cores continuam a mesma.
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        // aqui tiramos valor do MyHomePage object que foi criado pelo
        // metodo App.build , e usado apra setar a nossa appbar.
        title: Text(widget.title),
      ),
      body: Center(
        // center eh um widget de layout. eh preciso de apenas algo para
        // ficar no meio.
        child: Column(
          // Column tambem eh um widget de layout. eh preciso uma lista de coisas e ele verticaliza elas. como base, ele reorganiza seu tamanho para caber tudo
          //
          // Column tem varias propriedades para controlar como ela reorganiza seu tamanho e
          // como posiciona os objetos dentro. aqui nos usamos mainAxisAlignment para
          // centralizar os objetos verticalmente; o eixo principal aqui eh o vertical
          // porque colunas sao verticais (o eixo contrario seria o horizontal)
          // tente isto: invoque "debug painting" (escolha a acao "Toggle Debug Paint"
          // na IDE, ou precione "p" no console), para ver o
          // wireframe para cada widget.
          mainAxisAlignment: .center,
          children: [
            const Text('You have pushed the button this many times:'),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.headlineMedium,
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementCounter,
        tooltip: 'Increment',
        child: const Icon(Icons.add),
      ),
    );
  }
}
