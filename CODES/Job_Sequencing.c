#include <stdio.h>
#include <stdbool.h> // Needed for the 'bool' data type

// A structure to represent a job
struct Job {
    char id;      // Job Name/ID (e.g., 'a', 'b', 'c')
    int dead;     // Deadline of job
    int profit;   // Profit if job is finished before or on deadline
};

// Function to sort jobs in descending order of profit
void sortJobs(struct Job arr[], int n) {
    struct Job temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the next job has a higher profit
            if (arr[j].profit < arr[j + 1].profit) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the maximum deadline to know how many slots we need
int findMaxDeadline(struct Job arr[], int n) {
    int max = arr[0].dead;
    for (int i = 1; i < n; i++) {
        if (arr[i].dead > max) {
            max = arr[i].dead;
        }
    }
    return max;
}

// Core function to schedule the jobs
void printJobScheduling(struct Job arr[], int n) {
    // 1. Sort all jobs according to decreasing order of profit
    sortJobs(arr, n);

    // 2. Find maximum deadline
    int maxDeadline = findMaxDeadline(arr, n);

    // Arrays to keep track of free time slots and the final sequence
    // We use maxDeadline + 1 so we can use 1-based indexing (Slot 1, Slot 2...)
    char result[maxDeadline + 1]; 
    bool slot[maxDeadline + 1];

    // Initialize all slots to be free
    for (int i = 1; i <= maxDeadline; i++) {
        slot[i] = false;
    }

    int totalProfit = 0;

    // 3. Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        
        // Find a free slot for this job (starting from its deadline down to 1)
        for (int j = arr[i].dead; j > 0; j--) {
            
            // If the slot is free, assign the job here
            if (slot[j] == false) {
                result[j] = arr[i].id;  // Add this job to the result sequence
                slot[j] = true;         // Mark this slot as occupied
                totalProfit += arr[i].profit;
                break; // Stop looking for a slot for this specific job
            }
        }
    }

    // Print the result
    printf("Maximum profit sequence of jobs: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i]) {
            printf("%c ", result[i]);
        }
    }
    printf("\nTotal Profit Earned: %d\n", totalProfit);
}

int main() {
    // Array of jobs: {ID, Deadline, Profit}
    struct Job arr[] = { 
        {'a', 2, 100}, 
        {'b', 1, 19}, 
        {'c', 2, 27}, 
        {'d', 1, 25}, 
        {'e', 3, 15} 
    };
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Available Jobs:\n");
    for(int i=0; i<n; i++) {
        printf("Job %c: Deadline=%d, Profit=%d\n", arr[i].id, arr[i].dead, arr[i].profit);
    }
    printf("\n");

    printJobScheduling(arr, n);
    
    return 0;
}