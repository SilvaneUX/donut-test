import java.util.*;

class findSecondLargest {
    public static int print2largest(int[] arr) {
       
        int max = arr[0];
        
        for(int i=0; i<arr.length; i++) {
            
            if(arr[i] > max) {
                
                max = arr[i];
            }
        }
    
        int secondLarge = 0;
        
        for(int i=0; i<arr.length; i++) {
            
            if(secondLarge < arr[i] && arr[i] != max) {
                
                secondLarge = arr[i];
            }
        }
        
        if(secondLarge != max && secondLarge != 0) {
            
            return secondLarge;
        }
        
        return -1;
    }
    
    public static void main(String args[]) {
        
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the size of the array: ");
        int size = sc.nextInt();
        
        int[] arr = new int[size];
        
        System.out.print("Enter the array elements: ");
        for(int i=0; i<size; i++) {
            arr[i] = sc.nextInt();
        }
        
        int result = print2largest(arr);
        
        System.out.print(result);
    }
}
