#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype> // For tolower()

using namespace std;

// Global comparison counter
unordered_map<string, int> comparison_count;

// Partition function for QuickSort
int partition(vector<int>& arr, int low, int high, bool ascending) {
    int pivot = arr[high]; // Pivot element
    int i = low - 1; // Smaller element index

    for (int j = low; j < high; j++) {
        comparison_count["total"]++; // Track comparisons

        if ((ascending && arr[j] < pivot) || (!ascending && arr[j] > pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(vector<int>& arr, int low, int high, bool ascending) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending);
        quickSort(arr, low, pi - 1, ascending);
        quickSort(arr, pi + 1, high, ascending);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    char flag;
    cout << "Enter the order (A for ascending, D for descending): ";
    cin >> flag;

    bool ascending = (tolower(flag) == 'a');

    comparison_count["total"] = 0; // Reset counter

    quickSort(arr, 0, n - 1, ascending);

    cout << "\nElements after QuickSort: ";
    for (int num : arr) {
        cout << num << " ";
    }

    cout << "\nTotal comparisons: " << comparison_count["total"] << endl;
    
    return 0;
}
