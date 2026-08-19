public class Data implements Cloneable, Comparable<Data> {
    private byte dia, mes;
    private short ano;

    private static int qnt=0;
    public byte getDia(){
        return this.dia;
    }

    public byte getMes(){
        return this.mes;

    }

    public short getAno(){
        return this.ano;
    }

    public static int getQnt() {
        return Data.qnt;
    }
    
    public static boolean isBissexto(short ano){
        //calendari juliano
        if(ano<1582){
            if(ano%4==0){
                return true;
            } else {
                return false;
            } 
            
        }
    }

    public static boolean isValida (byte dia, byte mes, short ano){
        if (ano<-45) return false;
        if (ano == 0) return false;
        if (ano == 1582 && mes == 10 && dia>5 && dia<=14) return false;

        if (dia < 1 || dia > 31 || mes < 1 || mes > 12) return false;

    }

}