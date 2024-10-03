package latihansoal2;
public class ASE {
    public static void main(String[] args) {
        try {
            Object a[] = new Double[2];
            a[0] = 4;
        }
        catch (ArrayStoreException e) {
            System.out.println("ArrayStoreException terjadi ");
        }
    }
}
