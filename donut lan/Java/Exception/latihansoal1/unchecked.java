package latihansoal1;
public class unchecked {
    public static void main(String[] args) {
		cobaunchek(null);
	}

	static void cobaunchek(String x){
		try {
			System.out.println("First character: " + x.charAt(0));
		}
		catch(NullPointerException e) {
            System.out.println("ini adalah unchecked exception");
			System.out.println("Error NullPointer Exception !!");
		}
	}
}
