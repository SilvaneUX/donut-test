/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package oop0;

/**
 *
 * @author Krisna
 */
public class Ellipse {
    
     //definisi atribut
    public double jariB;
    public double jariK;

    

    //definisi methode
    public double calculateArea(){
        return ((2*this.jariB)*(2*this.jariK))*Math.PI/2;
    }

    public double calculatePerimeter(){
        return ((2*this.jariK)+(2*this.jariB))*Math.PI/2;
    }
    
}
