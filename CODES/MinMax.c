#include <stdio.h>

// Structure to return two values (min and max)
struct Pair {
    int min;
    int max;
};

// Function to find the minimum and maximum elements
struct Pair getMinMax(int arr[], int n) {
    struct Pair minmax;
    int i;

    // If there is only one element
    if (n == 1) {
        minmax.max = arr[0];
        minmax.min = arr[0];
        return minmax;
    }

    // Initialize min and max based on the first two elements
    if (arr[0] > arr[1]) {
        minmax.max = arr[0];
        minmax.min = arr[1];
    } else {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }

    // Traverse remaining elements
    for (i = 2; i < n; i++) {
        if (arr[i] > minmax.max)
            minmax.max = arr[i];
        else if (arr[i] < minmax.min)
            minmax.min = arr[i];
    }

    return minmax;
}

int main() {
    int n, i;

    // Ask user for the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Basic validation
    if (n <= 0) {
        printf("Array size must be at least 1.\n");
        return 1; // Exit with error code
    }

    int arr[n]; // Declare array of size n

    // Ask user to input the elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call function to find min and max
    struct Pair minmax = getMinMax(arr, n);

    printf("\nMinimum element is %d", minmax.min);
    printf("\nMaximum element is %d\n", minmax.max);

    return 0;
}