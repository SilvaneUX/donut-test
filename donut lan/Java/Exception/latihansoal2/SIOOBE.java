package latihansoal2;
public class SIOOBE {
    public static void main(String[] args) {
        String str = "Hello gan gan gan";
        for(int i=0; i< str.length(); i++) {
           System.out.print(str.charAt(i));
        }
        System.out.println("\n" +str.length());
        //Accessing element at greater than the length of the String
        try {
            System.out.println("memanggil charAt pada indeks 18");
            System.out.println(str.charAt(18));
        }catch(StringIndexOutOfBoundsException e){
           System.out.println("StringIndexOutOfBoundsException telah terjadi");
        }
     }
}
