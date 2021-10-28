package latihansoal2;
public class NASE {
    public static void main(String[] args) {
        int arrSize = -8;
        try {
            int[] myArray = new int[arrSize];
        } catch (NegativeArraySizeException ex) {
            System.out.println("NegativeArraySizeException telah terjadi");
        }
    }
}
