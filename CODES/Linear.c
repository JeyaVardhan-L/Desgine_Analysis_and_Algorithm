#include <stdio.h>
#include <stdlib.h>

// Basic linear search. Returns the index if found, -1 if we hit the end empty-handed.
int linearSearch(int arr[], int n, int target) {
    // Just walking through the array one by one. Nothing fancy, but it gets the job done for unsorted data.
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Boom, found it. Bail out early.
        }
    }
    return -1; // Scanned the whole thing, no luck.
}

int main() {
    int n, target;

    printf("Enter the number of elements you want in the array: ");
    // Quick check to make sure the user doesn't enter a negative size or a letter
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Let's keep it positive!\n");
        return 1;
    }

    // Dynamically allocating memory so the user can go as big or small as they want
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Yikes.\n");
        return 1;
    }

    printf("Awesome. Now enter the %d elements separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("What number are we hunting for today? ");
    scanf("%d", &target);

    int result = linearSearch(arr, n, target);

    if (result == -1) {
        printf("Bummer, %d is nowhere to be found in this array.\n", target);
    } else {
        printf("Success! Found %d sitting at index %d.\n", target, result);
    }

    free(arr); // Good habit: always clean up the mess
    return 0;
}