public class Countingsort{
	public static void countingsort(int array[]){
	//finding the largest element
	int largest = Integer.MIN_VALUE;
	for(int i=0;i<array.length;i++){
		largest = Math.max(largest,array[i]);
		
	}
	int count[] = new int[largest+1]; //creating an count array with size largest+1
	for(int i=0; i<array.length; i++){
		count[array[i]]++;		//incrementing count of each element in array[i] and storing that count in count array
	}							//initial count is zero
	
	//sorting
	int j = 0;
	for(int i=0; i<count.length; i++){
		while(count[i]>0){
			array[j] = i; //storing index as per count in same array
			j++;		  //incrementing array index
			count[i]--;	//decrementing count
		}
	}
	}
			
	public static void printarray(int array[]){
	for(int i=0; i<array.length;i++){
		System.out.print(array[i] + " ");
	}
	System.out.println();
}
public static void main(String args[]){
	int array[] = {5,4,1,3,2};
	countingsort(array);
	printarray(array);
}
}