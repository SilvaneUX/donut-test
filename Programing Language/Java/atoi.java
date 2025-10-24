import java.util.Scanner;

public class atoi {

    public static int myAtoi(String str) {
        str = str.trim();
        if (str.isEmpty()) return 0;

        int sign = 1, base = 0, i = 0;
        if (str.charAt(0) == '-' || str.charAt(0) == '+') {
            sign = (str.charAt(0) == '-') ? -1 : 1;
            i++;
        }

        while (i < str.length() && Character.isDigit(str.charAt(i))) {
            int digit = str.charAt(i) - '0';

            // Check for overflow
            if (base > (Integer.MAX_VALUE - digit) / 10) {
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            base = base * 10 + digit;
            i++;
        }

        return base * sign;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str =sc.nextLine();
        int result = myAtoi(str);
        System.out.println("Converted integer: " + result);
        sc.close();
    }
}
