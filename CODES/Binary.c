#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Helper function to make sure the user didn't give us garbage data.
// Binary search goes completely off the rails if the array isn't sorted.
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// The classic divide and conquer. Cuts the search space in half every iteration.
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        // Safe way to find the middle to prevent integer overflow on massive arrays
        int mid = low + (high - low) / 2;

        // Nailed it on the first try (or eventually)
        if (arr[mid] == target) {
            return mid;
        }

        // Target is bigger than mid, so we toss out the entire left half
        if (arr[mid] < target) {
            low = mid + 1;
        } 
        // Target is smaller than mid, so we toss out the entire right half
        else {
            high = mid - 1;
        }
    }

    // Crossed the streams, target isn't here
    return -1;
}

int main() {
    int n, target;

    printf("How many elements for the Binary Search array? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a valid positive number.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d numbers IN STRICTLY INCREASING ORDER (e.g., 2 5 8 12):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // The crucial edge-case check
    if (!isSorted(arr, n)) {
        printf("Error: Binary search requires a sorted array. Try again!\n");
        free(arr);
        return 1;
    }

    printf("What number are we searching for? ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result == -1) {
        printf("Element %d is not in the array.\n", target);
    } else {
        printf("Found it! Element %d is located at index %d.\n", target, result);
    }

    free(arr); // Clean up
    return 0;
}