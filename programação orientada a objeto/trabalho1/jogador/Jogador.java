package jogador;

public interface Jogador
{
    Marca getMarca ();

    void facaSuaJogada ();

    void vcGanhou ();

    void vcPerdeu ();

    void deuVelha ();

    boolean querMaisUmaPartida ();
}