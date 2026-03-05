#include <stdio.h>

// Structure to represent an Item
struct Item {
    int value;
    int weight;
    float ratio; // Value per unit weight
}; 

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items based on ratio in descending order
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Main function to solve Fractional Knapsack
void fractionalKnapsack(struct Item items[], int n, int capacity) {
    float totalValue = 0.0;
    int currentWeight = 0;

    // Calculate ratio for all items
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Sort items by ratio
    sortItems(items, n);

    printf("\nItems selected:\n");

    for (int i = 0; i < n; i++) {
        // If the item can fit completely
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Added Item (Value: %d, Weight: %d) - Full\n", items[i].value, items[i].weight);
        }
        // If item can't fit completely, take fraction
        else {
            int remain = capacity - currentWeight;
            totalValue += items[i].value * ((float)remain / items[i].weight);
            printf("Added Item (Value: %d, Weight: %d) - Fraction: %.2f%%\n", 
                   items[i].value, items[i].weight, ((float)remain / items[i].weight) * 100);
            break; // Knapsack is full
        }
    }

    printf("\nTotal Value in Knapsack: %.2f\n", totalValue);
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Value and Weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter Knapsack Capacity: ");
    scanf("%d", &capacity);

    fractionalKnapsack(items, n, capacity);

    return 0;
}