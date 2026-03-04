#include <stdio.h>

// Function to perform Linear Search
// Returns the index of x if present, otherwise returns -1
int linearSearch(int arr[], int n, int target) {
    // Loop through every element in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Target found, return the index
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {10, 50, 30, 70, 80, 20};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements
    int target = 30;

    int result = linearSearch(arr, n, target);

    if (result == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }

    return 0;
}