package conjunto;

import clonador.Clonador;

public class Conjunto <X> implements Cloneable
{
    protected Object[] elem;
    protected int qtd = 0;
    protected int capacidadeInicial;

    public Conjunto (int capacidadeInicial) throws Exception
    {
        if (capacidadeInicial <= 0)
            throw new Exception ("Capacidade invalida");

        this.elem = new Object [capacidadeInicial];
        this.capacidadeInicial = capacidadeInicial;
    }

    public Conjunto ()
    {
        this.elem = new Object [10];
        this.capacidadeInicial = 10;
    }

    protected void redimensioneSe (int novaCap)
    {
        if (novaCap <= 0)
            novaCap = 1;

        Object[] novo = new Object [novaCap];

        for (int i = 0; i < this.qtd; i++)
            novo[i] = this.elem[i];

        this.elem = novo;
    }

    protected Object[] ondeEsta (X x)
    {
        if (x == null)
            return new Object[] {false, this.qtd};

        for (int i = 0; i < this.qtd; i++)
        {
            if (this.elem[i] != null && x.equals(this.elem[i]))
            {
                Object[] ret = {true, i};
                return ret;
            }
        }

        Object[] ret = {false, this.qtd};
        return ret;
    }

    public void inclua (X x) throws Exception
    {
        if (x == null)
            throw new Exception ("Elemento ausente");

        Object[] onde = this.ondeEsta(x);
        boolean achou = (Boolean)onde[0];
        int posicao = (Integer)onde[1];

        if (achou)
            throw new Exception ("Elemento repetido");

        if (this.qtd == this.elem.length)
            this.redimensioneSe (2 * this.elem.length);

        for (int i = posicao; i < this.qtd; i++)
            this.elem[i + 1] = this.elem[i];

        if (x instanceof Cloneable)
        {
            Clonador<X> clonador = new Clonador<X>();
            this.elem[posicao] = clonador.clone(x);
        }
        else
            this.elem[posicao] = x;

        this.qtd++;
    }

    public X getElemento (int posicao) throws Exception
    {
        if (posicao < 0 || posicao >= this.qtd)
            throw new Exception ("Posicao invalida");

        if (this.elem[posicao] instanceof Cloneable)
        {
            Clonador<X> clonador = new Clonador<X>();
            return clonador.clone((X)this.elem[posicao]);
        }
        else
            return (X)this.elem[posicao];
    }

    public void remova (X x) throws Exception
    {
        if (x == null)
            throw new Exception ("Elemento ausente");

        Object[] onde = this.ondeEsta(x);
        boolean achou = (Boolean)onde[0];
        int posicao = (Integer)onde[1];

        if (!achou)
            throw new Exception ("Elemento inexistente");

        for (int i = posicao; i < this.qtd - 1; i++)
            this.elem[i] = this.elem[i + 1];

        this.qtd--;
        this.elem[this.qtd] = null;

        if (this.elem.length > this.capacidadeInicial && this.qtd <= (int)(0.25 * this.elem.length))
            this.redimensioneSe (Math.max(1, this.elem.length / 2));
    }

    public int getQtdElementos ()
    {
        return this.qtd;
    }

    public Conjunto<X> uniao (Conjunto<X> conj) throws Exception
    {
        if (conj == null)
            throw new Exception ("Conjunto ausente");

        Conjunto<X> ret = new Conjunto<X> (Math.max(1, this.qtd + conj.qtd));

        Conjunto<X> menor, maior;

        if (this.qtd < conj.qtd)
        {
            menor = this;
            maior = conj;
        }
        else
        {
            menor = conj;
            maior = this;
        }

        ret.qtd = maior.qtd;
        for (int i = 0; i < maior.qtd; i++)
            ret.elem[i] = maior.elem[i];

        int posicao = ret.qtd;
        for (int i = 0; i < menor.qtd; i++)
        {
            Object[] onde = ret.ondeEsta((X)menor.elem[i]);
            boolean achou = (Boolean)onde[0];

            if (!achou)
            {
                ret.elem[posicao++] = menor.elem[i];
                ret.qtd++;
            }
        }

        return ret;
    }

    public Conjunto<X> interseccao (Conjunto<X> conj) throws Exception
    {
        if (conj == null)
            throw new Exception ("Conjunto ausente");

        Conjunto<X> menor, maior;

        if (this.qtd < conj.qtd)
        {
            menor = this;
            maior = conj;
        }
        else
        {
            menor = conj;
            maior = this;
        }

        Conjunto<X> ret = new Conjunto<X> (Math.max(1, menor.qtd));

        int posicao = ret.qtd;
        for (int i = 0; i < menor.qtd; i++)
        {
            Object[] onde = maior.ondeEsta((X)menor.elem[i]);
            boolean achou = (Boolean)onde[0];

            if (achou)
            {
                ret.elem[posicao++] = menor.elem[i];
                ret.qtd++;
            }
        }

        return ret;
    }

    public Conjunto<X> menos (Conjunto<X> conj) throws Exception
    {
        if (conj == null)
            throw new Exception ("Conjunto ausente");

        Conjunto<X> ret = new Conjunto<X> (Math.max(1, this.qtd));

        int posicao = 0;
        for (int i = 0; i < this.qtd; i++)
        {
            Object[] onde = conj.ondeEsta((X)this.elem[i]);
            boolean achou = (Boolean)onde[0];

            if (!achou)
            {
                ret.elem[posicao++] = this.elem[i];
                ret.qtd++;
            }
        }

        return ret;
    }

    public boolean contem (Conjunto<X> conj) throws Exception
    {
        if (conj == null)
            throw new Exception ("Conjunto ausente");

        for (int i = 0; i < conj.qtd; i++)
        {
            Object[] onde = this.ondeEsta((X)conj.elem[i]);
            boolean achou = (Boolean)onde[0];

            if (!achou)
                return false;
        }

        return true;
    }

    public boolean estaContido (Conjunto<X> conj) throws Exception
    {
        if (conj == null)
            throw new Exception ("Conjunto ausente");

        for (int i = 0; i < this.qtd; i++)
        {
            Object[] onde = conj.ondeEsta((X)this.elem[i]);
            boolean achou = (Boolean)onde[0];

            if (!achou)
                return false;
        }

        return true;
    }

    @Override
    public String toString ()
    {
        String ret = "{";

        if (this.qtd > 0)
            ret += this.elem[0];

        for (int i = 1; i < this.qtd; i++)
            ret += ", " + this.elem[i];

        return ret + "}";
    }

    @Override
    public boolean equals (Object obj)
    {
        if (this == obj)
            return true;

        if (obj == null)
            return false;

        if (this.getClass() != obj.getClass())
            return false;

        Conjunto<?> conj = (Conjunto<?>)obj;

        if (this.qtd != conj.qtd)
            return false;

        for (int i = 0; i < conj.qtd; i++)
        {
            Object[] onde = this.ondeEsta((X)conj.elem[i]);
            boolean achou = (Boolean)onde[0];

            if (!achou)
                return false;
        }

        return true;
    }

    @Override
    public int hashCode ()
    {
        int ret = 1;

        for (int i = 0; i < this.qtd; i++)
            ret = 31 * ret + ((this.elem[i] == null) ? 0 : this.elem[i].hashCode());

        if (ret < 0)
            ret = -ret;

        return ret;
    }

    public Conjunto (Conjunto<X> modelo) throws Exception
    {
        if (modelo == null)
            throw new Exception ("Modelo ausente");

        this.qtd = modelo.qtd;
        this.capacidadeInicial = modelo.capacidadeInicial;
        this.elem = new Object [modelo.elem.length];

        for (int i = 0; i < this.qtd; i++)
            this.elem[i] = modelo.elem[i];
    }

    @Override
    public Object clone ()
    {
        try
        {
            return new Conjunto<X> (this);
        }
        catch (Exception erro)
        {
            return null;
        }
    }
}
