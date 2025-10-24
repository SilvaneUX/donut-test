

import java.util.*;
public class Containerwithmostwater {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] height = new int[n];
        for(int i=0;i<n;i++){
            height[i]=sc.nextInt();
        }

        int left=0,right=height.length-1,max_area=Integer.MIN_VALUE;

        while(left<=right){
            int min = (height[left]>height[right])? height[right]:height[left];
            int temp_area= min * ( right-left);
            if(temp_area>max_area){
                max_area=temp_area;
            }
            if(min==height[right]){
                right--;
            }
            else{
                left++;
            }
        }

        System.out.println("Maximum area is: " + max_area);
        sc.close();
    }
}
