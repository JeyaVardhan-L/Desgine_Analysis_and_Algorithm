# Fractional Knapsack Problem

The Fractional Knapsack problem is a classic algorithmic puzzle solved perfectly by a **Greedy Strategy**. 

Imagine you are a thief in a vault with a knapsack that can only hold a certain amount of weight. There are various items, each with a specific weight and value. Unlike the "0/1 Knapsack" where you must take an item whole or leave it, the Fractional Knapsack allows you to break items apart (like gold dust or liquids) and take a fraction of them.



The greedy choice here is to calculate the value-to-weight ratio for every item, sort them from highest ratio to lowest, and stuff your knapsack with the highest ratio items first until you run out of space.

### Complexity Analysis
* **Time Complexity:** O(n log n) - The bottleneck of this algorithm is sorting the items. Calculating the ratios and iterating through the sorted list both take O(n) time, but the standard `qsort` takes O(n log n).
* **Space Complexity:** O(1) auxiliary space, though we use O(n) space to store the initial array of items in memory.

### Real-World Use Cases
1. **Resource Allocation:** Distributing limited computing resources (like bandwidth or CPU time) among various tasks to maximize overall system throughput.
2. **Finance:** Portfolio optimization where you want to maximize return on investment (ROI) given a fixed budget, assuming fractional shares are allowed.