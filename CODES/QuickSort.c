#include <stdio.h>
#include <stdlib.h>

// Simple helper to swap two memory locations
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// The core logic of Quick Sort. We pick a 'pivot' and move everything smaller 
// to its left, and everything bigger to its right.
int partition(int arr[], int low, int high) {
    // Going with the standard approach: picking the last element as the pivot
    int pivot = arr[high]; 
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If we find something smaller than our pivot, toss it to the left side
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    // Finally, put the pivot right in the middle where it belongs
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The recursive engine. It partitions the array, then calls itself on the left and right chunks.
void quickSort(int arr[], int low, int high) {
    // Base case check to make sure we don't infinitely recurse
    if (low < high) {
        // Find the pivot index. The element at arr[pi] is now in its permanent, sorted spot.
        int pi = partition(arr, low, high);

        // Recursively sort the left chunk
        quickSort(arr, low, pi - 1);
        // Recursively sort the right chunk
        quickSort(arr, pi + 1, high);
    }
}

// Helper to quickly print out the array state
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("How many elements are we quick-sorting today? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. We need a positive integer.\n");
        return 1;
    }

    // Dynamic allocation handles whatever size the user throws at us
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Bailing out.\n");
        return 1;
    }

    printf("Enter the %d numbers, separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nUnsorted array: \n");
    printArray(arr, n);

    // Kick off the sort. The initial bounds are the first and last indices.
    quickSort(arr, 0, n - 1);
    
    printf("\nSorted array: \n");
    printArray(arr, n);
    
    free(arr); // Keep it clean
    return 0;
}