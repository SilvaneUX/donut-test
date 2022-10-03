package Percobaan2;

public class percobaan22 {
    public static void main(String[] args) {
        int bil= 10 ;
        try{
            System.out.println(bil/0);
        }catch(ArithmeticException e){
            System.out.println("Tidakboleh membagi bilangan dengan 0");
        }
    }
}
