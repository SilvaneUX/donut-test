package Percobaan5;
class ThrowDemo {
    public static void main(String[] args) {
        String input = "Invalid Input";
        try{
            if(input.equals("Invalid Input")){
                throw new RuntimeException("Throw demo");
            }else{
                System.out.println(input);
            }
            System.out.println("After throwing");
        }catch(RuntimeException e){
            System.out.println("Exception Caught : "+e);
        }
    }
}
