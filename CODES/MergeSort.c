#include <stdio.h>
#include <stdlib.h>

// The merging step. This is where the actual sorting happens by combining two sorted halves.
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Merge sort needs extra memory. Dynamically allocating temp arrays here.
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copying data over to our temporary left and right arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Now we weave them back together into the main array in sorted order
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Mopping up any leftovers in the Left array
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Mopping up any leftovers in the Right array
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    // Crucial step: free the temp arrays to prevent massive memory leaks
    free(L);
    free(R);
}

// The recursive splitting engine
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Finding the middle point safely to avoid integer overflow
        int m = l + (r - l) / 2;

        // Split the left half
        mergeSort(arr, l, m);
        // Split the right half
        mergeSort(arr, m + 1, r);

        // Stitch them back together
        merge(arr, l, m, r);
    }
}

// Quick helper to dump array contents to the screen
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int n;

    printf("How many elements for Merge Sort today? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Oops, please enter a valid positive number.\n");
        return 1;
    }

    // Dynamically sizing our main array based on user input
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. System might be out of RAM!\n");
        return 1;
    }

    printf("Enter the %d numbers, separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nUnsorted array: \n");
    printArray(arr, n);

    // Kick off the sorting process
    mergeSort(arr, 0, n - 1);

    printf("\nSorted array: \n");
    printArray(arr, n);

    // Clean up the main array
    free(arr);
    return 0;
}