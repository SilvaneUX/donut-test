/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package oop0;

/**
 *
 * @author Krisna
 */
public class Oop0 {
    
    

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        System.out.println("================");
        System.out.println("");
        Info.Info();
        System.out.println("");
        System.out.println("================");
        
        System.out.println("===== Persegi =====");
        Square kotakA = new Square();
        kotakA.sisi = 5;
        System.out.println("luas kotak A = "+kotakA.calculateArea());
        System.out.println("keliling kotak A = "+kotakA.calculatePerimeter());

        Square kotakB = new Square();
        kotakB.sisi = 10;
        System.out.println("luas kotak B = "+kotakB.calculateArea());
        System.out.println("keliling kotak B = "+kotakB.calculatePerimeter());

        Square kotakC = new Square();
        kotakC.sisi = 90;
        System.out.println("luas kotak C = "+kotakC.calculateArea());
        System.out.println("keliling kotak C = "+kotakC.calculatePerimeter());
        
        rectangle();
        circle();
        ellipse();
        
    }
    
        public static void rectangle() {
        
        System.out.println("===== Persegi panjang =====");
            
        Rectangle pp1 = new Rectangle();
        pp1.panjang=10;
        pp1.lebar=20;
        
        System.out.println("luas pp 1 = "+pp1.calculateArea());
        System.out.println("keliling pp 1 = "+pp1.calculatePerimeter());
        
    }
    
        
        public static void circle() {
        
        System.out.println("===== Lingkaran =====");
            
        Circle ling1 = new Circle();
        ling1.djari=7;
        
       // Double jari = 
        System.out.println("luas lingkaran 1 = "+ling1.calculateArea());
        System.out.println("keliling lingkaran 1 = "+ling1.calculatePerimeter());
        System.out.println("PI = "+Math.PI);
    }
        
        
      public static void ellipse() {
        
        System.out.println("===== Elipse =====");
            
        Ellipse el1 = new Ellipse();
        el1.jariK=7;
        el1.jariB=10;
        
       // Double jari = 
        System.out.println("luas Elipse 1 = "+el1.calculateArea());
        System.out.println("keliling Elipse 1 = "+el1.calculatePerimeter());
        System.out.println("PI = "+Math.PI);
    }
        
}