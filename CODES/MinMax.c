#include <stdio.h>
#include <stdlib.h>

// Structure to elegantly return both our answers at once
struct Pair {
    int min;
    int max;
};

// Optimized Min-Max using the Pairwise Comparison method.
// Instead of comparing every element against the current min and max separately, 
// we compare elements in pairs first, and then compare the winner/loser to the max/min.
struct Pair getMinMax(int arr[], int n) {
    struct Pair minmax;
    int i;

    // Setting up our initial state depending on if the array size is even or odd
    if (n % 2 == 0) {
        // If even, compare the first two elements to set the initial min and max
        if (arr[0] > arr[1]) {
            minmax.max = arr[0];
            minmax.min = arr[1];
        } else {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }
        i = 2; // Set starting index for the rest of the loop
    } else {
        // If odd, initialize both min and max to the very first element
        minmax.min = arr[0];
        minmax.max = arr[0];
        i = 1; // Set starting index for the rest of the loop
    }

    // Now, we process the remaining elements in pairs!
    while (i < n - 1) {
        // Compare the pair together first
        if (arr[i] > arr[i + 1]) {
            // arr[i] is the bigger one, so check it against the current max
            if (arr[i] > minmax.max) minmax.max = arr[i];
            // arr[i+1] is the smaller one, so check it against the current min
            if (arr[i + 1] < minmax.min) minmax.min = arr[i + 1];
        } else {
            // arr[i+1] is the bigger one
            if (arr[i + 1] > minmax.max) minmax.max = arr[i + 1];
            // arr[i] is the smaller one
            if (arr[i] < minmax.min) minmax.min = arr[i];
        }
        i += 2; // Jump forward by 2 since we processed a pair
    }

    return minmax;
}

int main() {
    int n;

    printf("How many elements are we scanning for Min and Max? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    // Swapping out the VLA for safe dynamic memory allocation
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. System might be low on RAM.\n");
        return 1;
    }

    printf("Enter the %d elements, separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Run our optimized algorithm
    struct Pair minmax = getMinMax(arr, n);

    printf("\nResults:\n");
    printf("Minimum element is: %d\n", minmax.min);
    printf("Maximum element is: %d\n", minmax.max);

    // Always clean up dynamic memory
    free(arr);
    return 0;
}