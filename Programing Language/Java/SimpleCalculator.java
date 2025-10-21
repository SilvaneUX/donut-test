// SimpleCalculator.java
// Author: Your Name
// Description: A simple calculator that performs +, -, *, / operations.

import java.util.Scanner;

public class SimpleCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("===== Simple Calculator =====");

        System.out.print("Enter first number: ");
        double num1 = sc.nextDouble();

        System.out.print("Enter an operator (+, -, *, /): ");
        char operator = sc.next().charAt(0);

        System.out.print("Enter second number: ");
        double num2 = sc.nextDouble();

        double result;

        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    System.out.println("Error: Division by zero is not allowed.");
                    sc.close();
                    return;
                }
                result = num1 / num2;
                break;
            default:
                System.out.println("Invalid operator!");
                sc.close();
                return;
        }

        System.out.println("Result: " + result);
        System.out.println("=============================");
        System.out.println("Thank you for using Simple Calculator!");

        sc.close();
    }
}
