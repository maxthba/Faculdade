public class Main {
    public static void main(String[] args) {
        try {

            Horario agora = new Horario((byte) 23, (byte) 58, (byte) 10);
            System.out.println(agora.toString());
            System.out.println(agora.getHorarioFuturo((int)120) + " Dois minutos futuros(120 segundos)");
            System.out.println(agora.getHorarioPassado((int)120) + " Dois minutos atras(120 segundos)");

            Horario outro_igual = new Horario((byte) 23, (byte) 58, (byte) 10);
            System.out.println(agora.equals(outro_igual) + " função equals quando sao iguais");

            Horario outro_diferente = new Horario((byte) 21, (byte) 53, (byte) 16);
            System.out.println(agora.equals(outro_diferente) + " função equals quando sao diferentes");

            System.out.println(agora.hashCode() + " HASHCODE do horario agora (23:58:10)");

        } catch (Exception erro) {
            System.err.println(erro.getMessage());
        }
    }
}
