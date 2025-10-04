// Java program to implement Selection Sort

public class SelectionSort {
    public static void main(String[] args) {
        int[] arr = {64, 25, 12, 22, 11};

        System.out.println("Original Array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }

        int n = arr.length;

        // Selection Sort logic
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;

            // Find the smallest element in the unsorted part
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            // Swap the found minimum with the first element of unsorted part
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }

        System.out.println("\nSorted Array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
