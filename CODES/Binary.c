#include <stdio.h>

// Function to perform Binary Search
// Returns index of x if present, otherwise returns -1
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        // Calculate mid to avoid potential overflow for large integers
        // Standard formula: mid = (low + high) / 2 works for small arrays
        // Safer formula: low + (high - low) / 2
        int mid = low + (high - low) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            low = mid + 1;

        // If target is smaller, ignore the right half
        else
            high = mid - 1;
    }

    // If we reach here, the element was not present
    return -1;
}

int main() {
    // Array MUST be sorted for Binary Search
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, n, target);

    if (result == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    
    return 0;
}