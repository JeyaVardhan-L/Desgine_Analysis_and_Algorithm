#include <stdio.h>
#include <stdlib.h>

// Simple helper to swap two memory locations
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Selection Sort works by repeatedly finding the absolute smallest element 
// in the unsorted portion of the array and moving it to the front.
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // We incrementally shrink the "unsorted" portion of the array
    for (i = 0; i < n - 1; i++) {
        
        // Assume the first unsorted element is the smallest one we've seen so far
        min_idx = i;
        
        // Scan through the rest of the array to see if we can find anything smaller
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Found a new minimum, update our tracker
            }
        }

        // Optimization: Only perform the swap if the minimum element is actually 
        // in a different position. No point in swapping an element with itself!
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

// Quick helper to dump array contents to the screen
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("How many elements are we sorting with Selection Sort? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    // Dynamic memory allocation
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. System might be out of RAM.\n");
        return 1;
    }

    printf("Enter the %d numbers, separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nUnsorted array: \n");
    printArray(arr, n);

    // Kick off the sorting process
    selectionSort(arr, n);

    printf("\nSorted array: \n");
    printArray(arr, n);

    // Always clean up dynamic memory
    free(arr);
    return 0;
}