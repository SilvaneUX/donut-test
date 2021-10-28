package latihansoal2;
public class NFE {
    private static String inputString = "123.33";    
    public static void main(String[] args) {  
        try {  
                int a = Integer.parseInt(inputString);  
        }catch(NumberFormatException ex){  
            System.err.println("NumberFormatException Telah Terjadi");  
        }  
    }  
}
