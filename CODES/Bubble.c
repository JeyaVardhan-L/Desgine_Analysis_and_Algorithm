#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Simple helper to swap two memory locations
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Optimized Bubble Sort. 
// Standard bubble sort is slow, but adding a 'swapped' flag helps us bail out early if the list is already sorted.
void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    
    // Outer loop handles the number of passes
    for (i = 0; i < n - 1; i++) {
        swapped = false; // Reset the flag for this pass
        
        // Inner loop does the actual heavy lifting and comparisons.
        // We do 'n - i - 1' because the heaviest elements naturally "bubble" to the end after each pass.
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true; // We had to make a move, so keep the sort going
            }
        }
        
        // If we went through a whole pass without swapping anything, the array is perfectly sorted!
        if (swapped == false) {
            break; 
        }
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

    printf("How many numbers do you want to sort? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    // Dynamic allocation so we aren't restricted by a fixed array size
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Check your system resources!\n");
        return 1;
    }

    printf("Enter the %d numbers, separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nInitial unsorted array: \n");
    printArray(arr, n);

    // Let the algorithm do its thing
    bubbleSort(arr, n);
    
    printf("\nSorted array: \n");
    printArray(arr, n);
    
    free(arr); // Always free up dynamically allocated memory
    return 0;
}