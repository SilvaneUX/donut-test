def is_armstrong_number(num):
    # Convert the number to a string to iterate through its digits
    digits = str(num)
    power = len(digits)  # The number of digits in the number
    total = sum(int(digit) ** power for digit in digits)  # Sum of digits raised to the power of the number of digits

    # Check if the total is equal to the original number
    return total == num

# Example usage
if __name__ == "__main__":
    test_numbers = [153, 370, 371, 9474, 123, 5]
    for number in test_numbers:
        if is_armstrong_number(number):
            print(f"{number} is an Armstrong number.")
        else:
            print(f"{number} is not an Armstrong number.")
