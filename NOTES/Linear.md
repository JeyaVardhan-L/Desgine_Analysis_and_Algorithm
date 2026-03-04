Linear Search is the simplest searching algorithm. It works by checking every element in a list one by one, from the beginning to the end, until the desired element is found or the list runs out.

Linear Search Logic
Start at the first element (index 0).

Compare the current element with the target value.

If they match, return the current index.

If they don't match, move to the next element.

If you reach the end of the array without finding a match, return -1 (to indicate "not found").

Complexity AnalysisTime Complexity:
Best Case: O(1) (The target is the very first element).
Worst Case: O(n) (The target is the last element or not present at all).
Average Case: O(n).

Space Complexity: O(1) (It does not use any extra memory proportional to the input size).