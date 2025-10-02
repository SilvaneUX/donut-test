/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package oop0;

/**
 *
 * @author Krisna
 */
public class Circle {
    
    //definisi atribut
    public int djari;

    

    //definisi methode
    public double calculateArea(){
        return (this.djari*this.djari)*Math.PI;
    }

    public double calculatePerimeter(){
        return (this.djari)*2*Math.PI;
    }
    
}
