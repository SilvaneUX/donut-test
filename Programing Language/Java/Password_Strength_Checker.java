import java.util.Scanner;

public class PasswordStrengthChecker {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your password: ");
        String password = sc.nextLine();

        int length = password.length();
        boolean hasUpper = false;
        boolean hasLower = false;
        boolean hasDigit = false;
        boolean hasSpecial = false;

        for (char ch : password.toCharArray()) {
            if (Character.isUpperCase(ch))
                hasUpper = true;
            else if (Character.isLowerCase(ch))
                hasLower = true;
            else if (Character.isDigit(ch))
                hasDigit = true;
            else if (!Character.isLetterOrDigit(ch))
                hasSpecial = true;
        }

        System.out.println("\nPassword Analysis:");
        System.out.println("------------------");
        System.out.println("Length: " + length);
        System.out.println("Contains Uppercase: " + (hasUpper ? "Yes" : "No"));
        System.out.println("Contains Lowercase: " + (hasLower ? "Yes" : "No"));
        System.out.println("Contains Digit: " + (hasDigit ? "Yes" : "No"));
        System.out.println("Contains Special Character: " + (hasSpecial ? "Yes" : "No"));

        if (length >= 8 && hasUpper && hasLower && hasDigit && hasSpecial)
            System.out.println("\n✅ Password Strength: STRONG");
        else if (length >= 6 && ((hasUpper && hasLower) || hasDigit))
            System.out.println("\n⚠️ Password Strength: MODERATE");
        else
            System.out.println("\n❌ Password Strength: WEAK");

        sc.close();
    }
}
