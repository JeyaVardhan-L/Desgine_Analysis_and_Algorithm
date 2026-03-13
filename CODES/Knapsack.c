#include <stdio.h>
#include <stdlib.h>

// Structure to represent our loot
struct Item {
    int value;
    int weight;
    float ratio; // Value per unit weight. This is our greedy metric!
}; 

// Comparator function for qsort. We want items sorted by ratio in descending order.
int compareItems(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    
    // We want the highest ratio first
    if (itemB->ratio > itemA->ratio) return 1;
    else if (itemB->ratio < itemA->ratio) return -1;
    return 0;
}

// The core Greedy logic
void fractionalKnapsack(struct Item items[], int n, int capacity) {
    float totalValue = 0.0;
    int currentWeight = 0;

    // First step: figure out the "bang for your buck" (ratio) for every item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Sort the items based on our calculated ratio using standard library qsort
    qsort(items, n, sizeof(struct Item), compareItems);

    printf("\n--- Loading the Knapsack ---\n");

    for (int i = 0; i < n; i++) {
        // If the whole item fits, take it!
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Grabbed Full Item (Value: %d, Weight: %d) -> Capacity left: %d\n", 
                   items[i].value, items[i].weight, capacity - currentWeight);
        }
        // If it doesn't fit completely, we take whatever fraction fits and we are done.
        else {
            int remain = capacity - currentWeight;
            float fraction = (float)remain / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Grabbed Fraction %.2f%% of Item (Value: %d, Weight: %d) -> Knapsack is FULL!\n", 
                   fraction * 100, items[i].value, items[i].weight);
            break; 
        }
    }

    printf("\nTotal Value safely secured in Knapsack: %.2f\n", totalValue);
}

int main() {
    int n, capacity;

    printf("How many items are available to steal... I mean, collect? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. We need a positive number of items.\n");
        return 1;
    }

    // Swapping out the VLA for safe dynamic memory allocation
    struct Item *items = (struct Item *)malloc(n * sizeof(struct Item));
    if (items == NULL) {
        printf("Memory allocation failed. System might be low on RAM.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter Value and Weight for item %d (e.g., 60 10): ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("What is the maximum weight the Knapsack can hold? ");
    scanf("%d", &capacity);

    // Run the greedy algorithm
    fractionalKnapsack(items, n, capacity);

    // Always clean up dynamic memory
    free(items);
    return 0;
}