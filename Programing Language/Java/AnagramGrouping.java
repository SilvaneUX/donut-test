package algorithms;

import java.util.*;

public class AnagramGrouping {

    /**
     * Function to group words that are anagrams of each other.
     * 
     * @param words List of input words
     * @return A list of lists where each inner list contains anagrams
     */
    public static List<List<String>> groupAnagrams(String[] words) {
        // Create a HashMap where key = sorted version of the word, value = list of anagrams
        Map<String, List<String>> anagramMap = new HashMap<>();

        for (String word : words) {
            // Convert word into a char array and sort it
            char[] charArray = word.toCharArray();
            Arrays.sort(charArray);
            String sortedWord = new String(charArray);

            // Add the word to the corresponding group in the HashMap
            if (!anagramMap.containsKey(sortedWord)) {
                anagramMap.put(sortedWord, new ArrayList<>());
            }
            anagramMap.get(sortedWord).add(word);
        }

        // Return all grouped anagrams as a list of lists
        return new ArrayList<>(anagramMap.values());
    }

    public static void main(String[] args) {
        // Sample input
        String[] input = {"eat", "tea", "tan", "ate", "nat", "bat"};

        // Function call
        List<List<String>> result = groupAnagrams(input);

        // Print output
        System.out.println("Input: " + Arrays.toString(input));
        System.out.println("Grouped Anagrams:");
        for (List<String> group : result) {
            System.out.println(group);
        }
    }
}
