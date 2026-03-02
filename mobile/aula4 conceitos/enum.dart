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
  StatusLampada status;
  Lampada(this.id, this.status);
}

void main() {

}