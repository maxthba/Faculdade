public class ControladorDeErros implements Cloneable
{
    private int qtdMax, qtdErr=0;

    public ControladorDeErros (int qtdMax) throws Exception
    {
        if(qtdMax <= 0)
            throw new Exception("qtdMax deve ser um numero positivo");
        this.qtdMax = qtdMax;
    }

    public void registreUmErro () throws Exception
    {
        if(isAtingidoMaximoDeErros())
            throw new Exception("Numero maximo de erros atingido");
        this.qtdErr++;
    }

    public boolean isAtingidoMaximoDeErros  ()
    {
        if(this.qtdErr == this.qtdMax)
            return true;
        else
            return false;
    }

    @Override
    public String toString ()
    {
        return this.qtdErr + " de " + this.qtdMax;
    }

    @Override
    public boolean equals (Object obj)
    {
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        ControladorDeErros outro = (ControladorDeErros) obj;
        return this.qtdErr == outro.qtdErr && this.qtdMax == outro.qtdMax;


    }

    @Override
    public int hashCode ()
    {
        int resultado = 17;
        resultado = resultado * 31 + ((Integer)this.qtdErr).hashCode();
        resultado = resultado * 31 + ((Integer)this.qtdMax).hashCode();
        return resultado;
    }

    public ControladorDeErros (ControladorDeErros c) throws Exception // construtor de c�pia
    {
        if (c == null)
            throw new Exception("ControladorDeErro para copia nulo");
        this.qtdErr = c.qtdErr;
        this.qtdMax = c.qtdMax;
    }

    @Override
    public Object clone ()
    {
        ControladorDeErros retorno = null;
        try {
            retorno = new ControladorDeErros(this);
        } catch(Exception erro){
            //não vai dar erro
        }
        return retorno;
    }
}
