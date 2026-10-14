public class Tabuleiro implements Cloneable
{
    // a principio, toda igual a null
    private Marca matriz [][] = new Marca [3][3];

    public boolean haMarcaNaPosicao (int lin, int col) throws Exception
    {
        // verifico se em matriz[lin][col]
        // tem null, retornando false em caso
        // afirmativo, ou true em caso negativo
        // dar excecao caso lin ou col invalido
        if (lin < 0 || lin > 2 || col < 0 || col > 2)
            throw new Exception("linha ou coluna invalida");

        return this.matriz[lin][col] != null;
    }

    public Marca getMarcaNaPosicao (int lin, int col) throws Exception
    {
        // retornar a marca que tem em
        // matriz[lin][col]
        // dar excecao caso lin ou col invalido
        if (lin < 0 || lin > 2 || col < 0 || col > 2)
            throw new Exception("linha ou coluna invalida");
        
        return this.matriz[lin][col];
    }

    public void setMarcaNaPosicao (Marca mrc, int lin, int col) throws Exception
    {
        // colocar mrc em matriz[lin][col],
        // dar excecao caso lin ou col invalido
        // dar excecao caso mrc seja null
        if (mrc == null)
            throw new Exception("marca nula");
        
        if (lin < 0 || lin > 2 || col < 0 || col > 2)
            throw new Exception("linha ou coluna invalida");
        
        this.matriz[lin][col] = mrc;
        
    }

    @Override
    public String toString ()
    {
        // retornar em um String o tabuleiro
        // formatado para ser exibido na tela
        String ret = "";

        for (int l = 0; l < 3; l++){
            for (int c = 0; c < 3; c++){
                if (this.matriz[l][c] == null)
                    ret += " ";
                else
                    ret += this.matriz[l][c].getSimbolo();

                if (c < 2)
                    ret += " | ";
            }

            if (l < 2)
                ret += "\n--+---+--\n";
        }

        return ret;
    }

    @Override
    public boolean equals (Object obj)
    {
        // retornar true se this for igual a obj ou false caso contrario
        if (this == obj)
            return true;

        if (obj == null)
            return false;

        if (this.getClass() != obj.getClass())
            return false;

        Tabuleiro outro = (Tabuleiro)obj;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (this.matriz[i][j] == null && outro.matriz[i][j] != null)
                    return false;

                if (this.matriz[i][j] != null && !this.matriz[i][j].equals(outro.matriz[i][j]))
                    return false;
            }
        }

        return true;
    }

    @Override
    public int hashCode ()
    {
        int hash = 17;
        for (int l = 0; l < 3; l++){
            for (int c = 0; c < 3; c++){
                hash += 31 * hash + ((this.matriz[l][c] == null)? 0: this.matriz[l][c].hashCode());
            }
        }

        if (hash < 0)
            return = -hash
        
        return hash;
    }

    // construtor de copia
    public Tabuleiro (Tabuleiro modelo) throws Exception
    {
        if (modelo == null)
            throw new Exception ("Modelo ausente");

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                this.matriz[i][j] = modelo.matriz[i][j];
    }

    @Override
    public Object clone ()
    {
        try
        {
            return new Tabuleiro (this);
        }
        catch (Exception erro)
        {
            return null;
        }
    }
}