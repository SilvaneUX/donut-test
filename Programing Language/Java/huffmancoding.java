import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Map;

// Node class representing each character in the Huffman Tree
class HuffmanNode {
    char ch;
    int freq;
    HuffmanNode left = null, right = null;

    HuffmanNode(char ch, int freq) {
        this.ch = ch;
        this.freq = freq;
    }

    HuffmanNode(char ch, int freq, HuffmanNode left, HuffmanNode right) {
        this.ch = ch;
        this.freq = freq;
        this.left = left;
        this.right = right;
    }
}

public class HuffmanCoding {
    // Traverse the Huffman Tree and store Huffman Codes in a map
    public static void encode(HuffmanNode root, String str, Map<Character, String> huffmanCode) {
        if (root == null) {
            return;
        }

        // Found a leaf node
        if (root.left == null && root.right == null) {
            huffmanCode.put(root.ch, str);
        }

        encode(root.left, str + '0', huffmanCode);
        encode(root.right, str + '1', huffmanCode);
    }

    // Decode the encoded string
    public static String decode(HuffmanNode root, String binaryString) {
        StringBuilder decodedString = new StringBuilder();
        HuffmanNode currentNode = root;
        for (int i = 0; i < binaryString.length(); i++) {
            currentNode = (binaryString.charAt(i) == '0') ? currentNode.left : currentNode.right;

            // Reached leaf node
            if (currentNode.left == null && currentNode.right == null) {
                decodedString.append(currentNode.ch);
                currentNode = root;
            }
        }
        return decodedString.toString();
    }

    // Build Huffman Tree and return its root
    public static HuffmanNode buildHuffmanTree(Map<Character, Integer> frequencyMap) {
        PriorityQueue<HuffmanNode> priorityQueue = new PriorityQueue<>(
            (l, r) -> l.freq - r.freq);

        // Create a leaf node for each character and add it to the priority queue
        for (Map.Entry<Character, Integer> entry : frequencyMap.entrySet()) {
            priorityQueue.add(new HuffmanNode(entry.getKey(), entry.getValue()));
        }

        // Iterate until the size of the queue is 1
        while (priorityQueue.size() != 1) {
            // Remove the two nodes with the lowest frequency
            HuffmanNode left = priorityQueue.poll();
            HuffmanNode right = priorityQueue.poll();

            // Create a new internal node with a frequency equal to the sum of the two nodes
            int sum = left.freq + right.freq;
            priorityQueue.add(new HuffmanNode('\0', sum, left, right));
        }

        // The remaining node is the root node
        return priorityQueue.peek();
    }

    public static void main(String[] args) {
        String text = "Huffman coding is a data compression algorithm.";

        // Count the frequency of appearance of each character
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : text.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        // Build the Huffman Tree
        HuffmanNode root = buildHuffmanTree(frequencyMap);

        // Store Huffman Codes in a map
        Map<Character, String> huffmanCode = new HashMap<>();
        encode(root, "", huffmanCode);

        // Print the Huffman Codes
        System.out.println("Huffman Codes: " + huffmanCode);
        System.out.println("Original String: " + text);

        // Encode the input text using Huffman Codes
        StringBuilder encodedString = new StringBuilder();
        for (char c : text.toCharArray()) {
            encodedString.append(huffmanCode.get(c));
        }
        System.out.println("Encoded String: " + encodedString);

        // Decode the encoded string
        String decodedString = decode(root, encodedString.toString());
        System.out.println("Decoded String: " + decodedString);
    }
}
