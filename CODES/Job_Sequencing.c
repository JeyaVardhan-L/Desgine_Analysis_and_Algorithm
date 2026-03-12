#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A structure to represent a single job
struct Job {
    char id;
    int dead;
    int profit;
};

// Comparator function required by C's built-in qsort.
// We want to sort jobs in descending order based on profit.
int compareJobs(const void *a, const void *b) {
    struct Job *jobA = (struct Job *)a;
    struct Job *jobB = (struct Job *)b;
    // Returning positive means jobB comes before jobA (descending)
    return (jobB->profit - jobA->profit);
}

// Quick helper to find the absolute latest deadline so we know how many time slots to create
int findMaxDeadline(struct Job arr[], int n) {
    int max = arr[0].dead;
    for (int i = 1; i < n; i++) {
        if (arr[i].dead > max) {
            max = arr[i].dead;
        }
    }
    return max;
}

// Core scheduling logic using a Greedy approach
void printJobScheduling(struct Job arr[], int n) {
    // 1. Sort jobs using the highly optimized standard library qsort instead of a slow nested loop
    qsort(arr, n, sizeof(struct Job), compareJobs);

    // 2. Figure out our max time horizon
    int maxDeadline = findMaxDeadline(arr, n);

    // Dynamically allocating our time slot trackers to handle massive deadlines
    char *result = (char *)malloc((maxDeadline + 1) * sizeof(char)); 
    bool *slot = (bool *)malloc((maxDeadline + 1) * sizeof(bool));

    // Initialize all slots as wide open
    for (int i = 1; i <= maxDeadline; i++) {
        slot[i] = false;
    }

    int totalProfit = 0;

    // 3. Try to schedule each job, starting with the most profitable one
    for (int i = 0; i < n; i++) {
        // We iterate backwards from the job's deadline. 
        // We want to schedule it as late as possible to leave early slots open for other jobs.
        for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == false) {
                result[j] = arr[i].id;  
                slot[j] = true;         
                totalProfit += arr[i].profit;
                break; // Job scheduled, move on to the next one
            }
        }
    }

    // Print out our final schedule
    printf("\nMaximum profit sequence of jobs: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i]) {
            printf("%c ", result[i]);
        }
    }
    printf("\nTotal Profit Earned: %d\n", totalProfit);

    // Free up our dynamic arrays
    free(result);
    free(slot);
}

int main() {
    int n;

    printf("How many jobs do we have on the docket today? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. We need a positive integer.\n");
        return 1;
    }

    // Dynamic allocation for our jobs array
    struct Job *arr = (struct Job *)malloc(n * sizeof(struct Job));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Clearing the input buffer just in case
    while ((getchar()) != '\n'); 

    printf("Enter Job ID (single character), Deadline, and Profit for each job.\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d -> ID, Deadline, Profit (e.g., A 2 100): ", i + 1);
        scanf(" %c %d %d", &arr[i].id, &arr[i].dead, &arr[i].profit);
    }

    printJobScheduling(arr, n);
    
    // Always clean up your toys
    free(arr);
    return 0;
}