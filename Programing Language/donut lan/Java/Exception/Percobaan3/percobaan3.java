package Percobaan3;

public class percobaan3 {
    public static void main(String[] args) {
        int bil=10;
        String b[] = {"a","b","c"};
        try{
            System.out.println(b[3]);
            System.out.println(bil/0);
        }catch(ArithmeticException e){
            System.out.println("Error Aritmetik");
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Error Kapasitas Array Melebihi Batas");
        }catch(Exception e){
            System.out.println("Terdapat Error");
        }
    }
}
