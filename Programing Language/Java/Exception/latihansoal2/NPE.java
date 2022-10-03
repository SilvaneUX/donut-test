package latihansoal2;
public class NPE {
    public static void main(String[] args) {
		String s = "abcd";
		test(null);
	}
	static void test(String x){
		try {
			System.out.println("First character: " + x.charAt(0));
		}
		catch(NullPointerException e) {
			System.out.println("NullPointerException Terjadi");
		}
	}
}
