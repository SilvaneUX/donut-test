import java.util.*;

/**
 * ----------------------------------------------------------
 *  Word Frequency Counter in Java
 * ----------------------------------------------------------
 * This program takes a sentence or paragraph as input from the user
 * and counts how many times each unique word appears in it.
 * 
 * - It ignores punctuation marks.
 * - It is case-insensitive (e.g., "Java" and "java" are treated the same).
 * - Words are displayed in descending order of their frequency.
 * 
 * ----------------------------------------------------------
 * 🧠 Example:
 * Input:
 *   Hello world, hello Java! Java is fun.
 * 
 * Output:
 *   Word Frequencies:
 *   hello: 2
 *   java: 2
 *   world: 1
 *   is: 1
 *   fun: 1
 * ----------------------------------------------------------
 * 
 * ⏱️ Time Complexity: O(n)
 *      - n = number of words in the input string.
 *      - Each word is processed once and inserted/updated in a HashMap.
 * 
 * 💾 Space Complexity: O(k)
 *      - k = number of unique words (size of the HashMap).
 * 
 * Author: YourName
 * For: Hacktoberfest Contribution
 */

public class WordFrequencyCounter {

    /**
     * Method to count and display frequency of words in a given text.
     *
     * @param text the input string from the user
     */
    public static void countWordFrequency(String text) {
        // Remove punctuation and convert to lowercase
        String cleanedText = text.replaceAll("[^a-zA-Z0-9\\s]", "").toLowerCase();

        // Split text into words based on whitespace
        String[] words = cleanedText.split("\\s+");

        // HashMap to store word counts
        Map<String, Integer> wordCount = new HashMap<>();

        // Count each word's frequency
        for (String word : words) {
            if (!word.isEmpty()) { // avoid empty strings
                wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
            }
        }

        // Sort the entries by frequency in descending order
        Map<String, Integer> sortedWordCount = wordCount.entrySet()
                .stream()
                .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
                .collect(
                        LinkedHashMap::new,
                        (map, entry) -> map.put(entry.getKey(), entry.getValue()),
                        LinkedHashMap::putAll
                );

        // Print results
        System.out.println("\nWord Frequencies:");
        sortedWordCount.forEach((word, count) ->
                System.out.println(word + ": " + count));
    }

    /**
     * Main method to take user input and call the word counter.
     */
    public static void main(String[] args) {
        // Create Scanner object for input
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a sentence or paragraph:");
        String input = sc.nextLine(); // Read the entire line

        // Call the function to count and display word frequencies
        countWordFrequency(input);

        sc.close(); // Close scanner to prevent resource leak
    }
}
