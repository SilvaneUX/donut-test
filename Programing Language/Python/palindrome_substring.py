# algorithms/palindrome_substring.py

def all_palindromic_substrings(s: str) -> set:
    """
    Find all palindromic substrings in the given string s.
    
    Args:
        s (str): Input string.
    
    Returns:
        set: A set containing all unique palindromic substrings.
    """
    palindromes = set()

    def expand_around_center(left: int, right: int):
        """
        Expand around the center and add palindromes to the set.
        """
        while left >= 0 and right < len(s) and s[left] == s[right]:
            palindromes.add(s[left:right+1])
            left -= 1
            right += 1

    for i in range(len(s)):
        expand_around_center(i, i)      # Odd-length palindromes
        expand_around_center(i, i + 1)  # Even-length palindromes

    return palindromes


def longest_palindrome(s: str) -> str:
    """
    Find the longest palindromic substring.
    """
    all_palindromes = all_palindromic_substrings(s)
    if not all_palindromes:
        return ""
    # Return the palindrome with maximum length
    return max(all_palindromes, key=len)


if __name__ == "__main__":
    # Take input from the user
    user_input = input("Enter a string: ")

    # Find all palindromic substrings
    all_palindromes = all_palindromic_substrings(user_input)
    print(f"All Palindromic Substrings: {all_palindromes}")

    # Find the longest palindrome
    longest = longest_palindrome(user_input)
    print(f"Longest Palindromic Substring: {longest}")
