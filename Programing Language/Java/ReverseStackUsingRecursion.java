package Java_DSA.Problems.StackAndQueue;

// import java.util.*;
// public class Solution {

//     public static void reverseStack(Stack<Integer> stack) {
//         // write your code here
//         ArrayList<Integer> li =new ArrayList();
//         while(!stack.isEmpty()){
// 			li.add(stack.peek());
// 			stack.pop();
//         }

//         for(int i=0;i<li.size();i++){
//             stack.push(li.get(i));
//         }
//     }
// }

import java.util.Stack;
public class ReverseStackUsingRecursion {
    public static void reverse(Stack<Integer> stack) {
        //base case
        if(stack.isEmpty()){
            return;
        }
        int num = stack.peek();
        stack.pop();
        reverse(stack);
        insertAtBottom(stack,num);
    }

    public static void insertAtBottom(Stack<Integer> stack, int x){
        if(stack.isEmpty()){
            stack.push(x);
            return;
        }

        int num = stack.peek();
        stack.pop();
        insertAtBottom(stack,x);
        stack.push(num);
    }

    public static void main(String[] args) {
        Stack<Integer>s = new Stack<>();
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        System.out.println(s);
        reverse(s);
        System.out.println(s);
    }
}
