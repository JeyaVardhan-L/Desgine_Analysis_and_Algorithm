# Quick Sort

Quick Sort is a highly efficient, divide-and-conquer sorting algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. 


The sub-arrays are then sorted recursively. 

### Complexity Analysis
* **Time Complexity:** * **Best Case:** O(n \log n) - The pivot divides the array into two nearly equal pieces every time.
  * **Average Case:** O(n \log n) - Standard performance for randomized or average data.
  * **Worst Case:** O(n^2) - Happens when the array is already sorted (or reverse sorted) and we consistently pick the greatest or smallest element as the pivot.
* **Space Complexity:** O(\log n) - The algorithm sorts in-place, but requires stack memory for the recursive function calls.

### Why is this important?
Quick Sort is often the default sorting algorithm built into programming languages (like C's `qsort`) because its in-place sorting gives it excellent cache locality, making it faster in practice than other O(n \log n) algorithms like Merge Sort for standard arrays.