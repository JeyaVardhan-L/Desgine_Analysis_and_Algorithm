# Linear Search 

Linear search is the simplest searching algorithm. It sequentially checks each element of the list until a match is found or the whole list has been searched.


### Complexity Analysis
* **Time Complexity:** * **Best Case:** O(1) - The target is the very first element.
  * **Worst Case:** O(n) - The target is the very last element, or not in the array at all.
  * **Average Case:** O(n)
* **Space Complexity:** O(1) - It operates directly on the existing array without needing extra data structures.

### When to use it?
Honestly, in production, you rarely use Linear Search for large datasets. However, it is perfect when:
1. The dataset is very small.
2. The array is completely unsorted (and sorting it first would cost more time than just searching it).
3. You are dealing with a stream of data where elements are constantly being added, making maintaining a sorted order expensive.