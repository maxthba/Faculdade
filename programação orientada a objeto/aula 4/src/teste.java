public class teste{
    public static void main(String[] args) throws Exception
    {
       ControladorDeErros teste = null;
       try{
        teste = new ControladorDeErros(20);
        System.out.println(teste.toString());
       } catch (Exception erro){
        System.err.println(erro);
       }

       ControladorDeErros teste_copia = null;
       try{
            teste_copia = new ControladorDeErros(teste);
            System.out.println(teste_copia.toString());
       } catch (Exception erro) {
            System.out.println(erro);
       }
    }
}
