numbers = []
flag = False
number_of_values = int(input("Enter the number of values "))

for i in range(number_of_values):
    x = int(input("Enter a number "))
    numbers.append(x)
    
value = int(input("Enter a number to seach for "))

for i in range(len(numbers)):
    if numbers[i] == value:
        flag = True
        break
    
if flag == True:
    print(value, "found at index", (i+1))
else:
    print("Number not found")