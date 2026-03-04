Quick Sort

Quick Sort is another "Divide and Conquer" algorithm, but it works differently from Merge Sort. It is often faster in practice and uses less memory because it sorts the array in-place (without creating large temporary arrays).

The core idea is the Pivot.

How it works:

Pick a Pivot: Select an element from the array to be the "pivot" (commonly the last element).

Partition: Reorder the array so that all elements smaller than the pivot come before it, and all elements larger than the pivot come after it. The pivot is now in its final, correct sorted position.

Recursion: Apply the same steps to the sub-array on the left of the pivot and the sub-array on the right of the pivot.

Complexity:

Time Complexity:

Average Case: O(n log n) - Very fast.

Worst Case: O(n^2) - Happens if the array is already sorted and you always pick the last element as pivot. (Randomized pivots fix this).

Space Complexity: O(log n) - Used for the recursion stack (not for data storage).