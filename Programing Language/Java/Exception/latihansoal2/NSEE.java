package latihansoal2;
import java.util.*;
public class NSEE {
    public NSEE(){
        Scanner input = new Scanner(System.in);
        System.out.print("Masukkan var : ");
        int tes = input.nextInt();
        input.close();  
    }
    public static void main(String[] args) {
        NSEE baru = new NSEE();
        try {
            NSEE baru1 = new NSEE();
        } catch (NoSuchElementException e) {
            System.out.println("NoSuchElementException Terjadi");
        }
    }
}
