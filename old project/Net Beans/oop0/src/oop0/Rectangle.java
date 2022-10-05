/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package oop0;

/**
 *
 * @author Krisna
 */
public class Rectangle {
    
    //definisi atribut
    public int panjang;
    public int lebar;
    

    //definisi methode
    public int calculateArea(){
        return this.panjang*this.lebar;
    }

    public int calculatePerimeter(){
        return 2*(this.panjang+this.lebar);
    }
    
}
