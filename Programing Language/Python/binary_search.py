def binary_search(arr, target):
    """
    Binary Search Algorithm
    Time Complexity: O(log n)
    Space Complexity: O(1)
    
    Args:
        arr: A sorted list of numbers
        target: The number to search for
        
    Returns:
        index: The index of the target if found, -1 otherwise
    """
    left = 0
    right = len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1

def binary_search_recursive(arr, target, left, right):
    """
    Recursive implementation of Binary Search
    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursive call stack
    
    Args:
        arr: A sorted list of numbers
        target: The number to search for
        left: Left boundary of the search
        right: Right boundary of the search
        
    Returns:
        index: The index of the target if found, -1 otherwise
    """
    if left > right:
        return -1
        
    mid = (left + right) // 2
    
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search_recursive(arr, target, mid + 1, right)
    else:
        return binary_search_recursive(arr, target, left, mid - 1)

# Example usage and test cases
if __name__ == "__main__":
    # Test both iterative and recursive implementations
    test_array = [1, 3, 5, 7, 9, 11, 13, 15, 17]
    target = 7
    
    # Test iterative binary search
    result_iterative = binary_search(test_array, target)
    print(f"Iterative Binary Search: Found {target} at index {result_iterative}")
    
    # Test recursive binary search
    result_recursive = binary_search_recursive(test_array, target, 0, len(test_array) - 1)
    print(f"Recursive Binary Search: Found {target} at index {result_recursive}")
    
    # Test with target not in array
    target_not_found = 10
    result_not_found = binary_search(test_array, target_not_found)
    print(f"Searching for {target_not_found}: {'Not found' if result_not_found == -1 else f'Found at index {result_not_found}'}")