# Python Bubble Sort

def bubbleSort(arr):
	n = len(arr)
	
	for i in range(n):
		for j in range(0, n-i-1):
			if arr[j] > arr[j+1] :
				arr[j], arr[j+1] = arr[j+1], arr[j]
# End of bubbleSort function

arr = [64, 69, 31, 128, 8, 32, 144, 1024, 512]

bubbleSort(arr)

print ("Sorted array is:")
for i in range(len(arr)):
	print ("%d" %arr[i]),
