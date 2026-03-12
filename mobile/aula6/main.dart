import 'Pessoa.dart';

void main(){
    Pessoa p1 = Pessoa('Max', 60, 1.76);
    print(p1.imc);
    //nao da para alterar mais imc
    p1.imc = 10;
    p1._imc = 10;
    
}