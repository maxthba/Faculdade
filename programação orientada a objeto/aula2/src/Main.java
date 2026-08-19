public class Main {
    public static void main(String[] args) {
        Data aniversarioMax = null;
        try {
            aniversarioMax = new Data((byte)25, (byte)11, (short)2006);
            System.out.println(aniversarioMax.toString());
            System.out.println(aniversarioMax.getDiaAnterior());
            System.out.println(aniversarioMax.getVariosDiasAtras(10));


        } catch (Exception erro) {
            System.err.println(erro.getMessage());
        }
    }
}
