# Selection Sort

Selection Sort is a simple, in-place comparison sorting algorithm. It divides the input list into two parts: a sorted sublist of items which is built up from left to right at the front of the list, and a sublist of the remaining unsorted items that occupy the rest of the list. 



The algorithm proceeds by finding the smallest element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element, and moving the sublist boundaries one element to the right.

### Complexity Analysis
* **Time Complexity:** O(n^2) for Best, Average, and Worst cases. Because it always scans the entire remaining unsorted portion of the array to find the absolute minimum, it takes the exact same amount of time regardless of whether the array is already sorted or completely reversed.
* **Space Complexity:** O(1). It only requires a single temporary variable for swapping.

### When to use it?
Selection sort is rarely used in high-performance applications because O(n^2) time complexity is very slow for large datasets. However, it has one major advantage over algorithms like Bubble Sort: it makes the absolute minimum number of memory swaps (maximum of O(n) swaps). If you are writing software for a system where writing to memory is extremely "expensive" (like certain types of flash memory or EEPROMs on embedded devices), Selection Sort can actually be a smart choice.