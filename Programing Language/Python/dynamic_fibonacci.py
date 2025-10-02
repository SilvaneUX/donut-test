#USING THIS METHOD, WE CAN FIND THE NTH FIBONACCI NUMBER BY STORING THE VALUES OF THE PREVIOUS FIBONACCI NUMBERS INSIDE A DICTIONARY D
import time
recursions = 0
lookups = 0
updates = 0
def fibonacci(n, d={}):
#As the function recursively repeats itself, it keeps on
updating the array d so with values of all fibonacci numbers
less than and equal to n
global recursions, lookups, updates
recursions += 1
if n in d:
lookups += 1
return d[n]
if n <= 1:
return n
else:
result = fibonacci(n - 1, d) + fibonacci(n - 2, d)
d[n] = result
updates += 1
return result
# Get input from the user
n = int(input("Enter the value of n: "))
# Record the start time
start_time = time.time()
# Calculate the nth Fibonacci number
fib_number = fibonacci(n)
# Record the end time
end_time = time.time()
# Calculate the execution time
execution_time = end_time - start_time
# Print the results
print("The", n, "th Fibonacci number is:", fib_number)
print("Number of recursive calls:", recursions)
print("Number of dictionary lookups:", lookups)
print("Number of dictionary updates:", updates)
print("Time taken:", execution_time, "seconds")
