# Binary Search

Binary Search is a highly efficient "divide and conquer" algorithm used to find an item in a **sorted** list. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.



### Complexity Analysis
* **Time Complexity:** * **Best Case:** O(1) - The target is perfectly in the middle on the first check.
  * **Worst Case:** O(log n) - The target is at the extreme ends, or not present, requiring the maximum number of halving steps.
  * **Average Case:** O(log n)
* **Space Complexity:** * **Iterative Approach:** O(1) - Only requires a few pointers (`low`, `high`, `mid`).
  * **Recursive Approach:** O(log n) - Due to the call stack overhead.

### Why is this important?
The difference between O(n) (Linear) and O(log n) (Binary) is massive at scale. If you have an array of 4 billion items, Linear Search might take 4 billion guesses. Binary Search will find the target in a maximum of just **32 guesses**. 

### Real-World Use Cases
1. Database indexing and querying.
2. Searching through standard libraries (like Java's `Arrays.binarySearch`).
3. Debugging (e.g., `git bisect` uses binary search to find which commit introduced a bug!).