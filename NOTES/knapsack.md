Fractional Knapsack Problem

This problem is a classic example of a Greedy Algorithm.

Imagine you are a thief with a knapsack that can carry a maximum weight of W. You are in a room with several items, each having a specific weight and value. You want to maximize the total value in your knapsack.

The Rule: In "Fractional" Knapsack, you can break items. If you can't fit a whole item, you can take a fraction of it (e.g., half a bag of gold dust).

The Strategy (Greedy Approach):

Calculate the Value-to-Weight Ratio for every item. (Value / Weight).

Sort the items based on this ratio in descending order (highest ratio first).

Pick the item with the highest ratio:

If the whole item fits, take it all and reduce the remaining capacity.

If the whole item doesn't fit, take as much as possible (fill the remaining space) and stop.

Complexity:

Time Complexity: O(N log N) - Determining the ratios is O(N), but sorting them takes O(N log N).

Space Complexity: O(1) - If we ignore the space for storing the inputs.