def peak_index_in_mountain_array(arr):
    left = 0
    right = len(arr) - 1
    
    while left < right:
        mid = left + (right - left) // 2
        
        # Agar mid element less than next element, peak right me hai
        if arr[mid] < arr[mid + 1]:
            left = mid + 1
        else:  # otherwise peak left me ya mid hi peak hai
            right = mid
    
    return left  # ya right, dono same hain

# Example
arr = [1, 3, 5, 7, 6, 4, 2]
peak_index = peak_index_in_mountain_array(arr)
print(f"Peak index is: {peak_index}, Peak element is: {arr[peak_index]}")
