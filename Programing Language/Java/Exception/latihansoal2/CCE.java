package latihansoal2;
public class CCE {
    public static void main(String[] args) {
        Object test = 0;
        try {
            System.out.println((String)test);
        }catch (ClassCastException ex){ 
            System.out.println("ClassCastException Terjadi");
        }
    }
}

