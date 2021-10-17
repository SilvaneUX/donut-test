package Tugas1;
public class tes {
    public static void main(String[] args) {
        Kerucut kecurut = new Kerucut(9,6);
        System.out.println("mengdeclare kerucut dengan r : " + kecurut.getR() + " dengan tinggi " + kecurut.getTinggi());
        System.out.println(kecurut.toString());
        
        Silinder tabung = new Silinder(6,9);
        System.out.println("mengdeclare silinder dengan r : " + tabung.getR() + " dengan tinggi " + tabung.getTinggi());
        System.out.println(tabung.toString());
    } 
}
