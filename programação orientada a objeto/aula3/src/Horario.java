public class Horario
{
    private byte hora, minuto, segundo;
    public /*void*/ Horario (byte hora, byte minuto, byte segundo) throws Exception
    {
        this.setHora(hora);
        this.setMinuto(minuto);
        this.setSegundo(segundo);
    }

    public void setHora (byte hora) throws Exception
    {
        if(hora>23 || hora<0){
            throw new Exception("Hora invalida");
        }
        this.hora=hora;
    }

    public void setMinuto (byte minuto) throws Exception
    {
        if(minuto>59 || minuto<0){
            throw new Exception("Minuto invalido");
        }
        this.minuto=minuto;
    }

    public void setSegundo (byte segundo) throws Exception
    {
        if(segundo>59 || segundo<0){
            throw new Exception("Minuto invalido");
        }
        this.segundo=segundo;
    }

    public byte getHora ()
    {
        return this.hora;
    }

    public byte getMinuto ()
    {
        return this.minuto;
    }

    public byte getSegundo ()
    {
        return this.segundo;
    }

    public void adiante (int qtdSegundos) throws Exception
    {
        if(qtdSegundos < 0)
            throw new Exception("quantidade adiante negativa");

        int total = this.hora * 60 * 60
                  + this.minuto * 60
                  + this.segundo
                  + qtdSegundos;

        total %= 86400;

        this.hora = (byte)(total / (60 * 60));
        total %= (60 * 60);
        this.minuto = (byte)(total / 60);
        this.segundo = (byte)(total % 60);
    }

    public void retroceda (int qtdSegundos) throws Exception
    {
        if(qtdSegundos < 0)
            throw new Exception("quantidade retrocedida negativa");

        int total = this.hora * 60 * 60
                  + this.minuto * 60
                  + this.segundo
                  - qtdSegundos;

        total %= 86400;
        if(total < 0)
            total += 86400;

        this.hora = (byte)(total / (60 * 60));
        total %= (60 * 60);
        this.minuto = (byte)(total / 60);
        this.segundo = (byte)(total % 60);
    }

    public Horario getHorarioFuturo (int qtdSegundos) throws Exception // nao altera o this
    {
        Horario retorno = new Horario(this.hora, this.minuto, this.segundo);
        retorno.adiante(qtdSegundos);
        return retorno;
    }

    public Horario getHorarioPassado (int qtdSegundos) throws Exception // nao altera o this
    {
        Horario retorno = new Horario(this.hora, this.minuto, this.segundo);
        retorno.retroceda(qtdSegundos);
        return retorno;
    }

    @Override
    public String toString()
    {
        return String.format("%02d:%02d:%02d", this.hora, this.minuto, this.segundo);
    }

    @Override
    public boolean equals(Object obj)
    {
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;

        Horario outro = (Horario) obj;
        return this.hora == outro.hora
            && this.minuto == outro.minuto
            && this.segundo == outro.segundo;
    }

    @Override
    public int hashCode()
    {
        int resultado = 17;
        resultado = 31 * resultado + this.hora;
        resultado = 31 * resultado + this.minuto;
        resultado = 31 * resultado + this.segundo;
        return resultado;
    }
}