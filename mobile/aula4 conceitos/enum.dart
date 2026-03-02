//casos de uso de enum: quando voce tem valores definidos e praticamente imutaveis para determinados objetos e 
//situações(EX: dia da semana, meses, tipo de combustivel, estados diversos).
enum DiaSemana {
  domingo,
  segunda,
  terca,
  quarta,
  quinta,
  sexta,
  sabado
}


enum StatusLampada {
    ligada,
    desligada,
    offline
}

class Lampada {
  int id;
  String modelo;
  StatusLampada status;
  Lampada(this.id, this.modelo, this.status);

  bool equals(Lampada outra){
    if(outra.id == this.id){
      return true;
    }
    return false;
  }
}

void main() {
  Lampada l1 = Lampada(1, 'A01', StatusLampada.offline);
  Lampada l2 = Lampada(1, 'A01', StatusLampada.offline);
  if(l1 == l2){
    print('são as mesmas lampadas');
  } else{
    print('Não são as mesmas lampadas = instancias diferentes');
  }

  /*if(l1.id == l2.id){
    print('para a impresa são as mesmas lampadas');
  }*/

  if(l1.equals(l2)){
    print('sao as mesmas lampadas');
  }
}