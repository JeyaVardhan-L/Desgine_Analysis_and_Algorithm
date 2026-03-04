Finding Maximum and Minimum Elements

This is a fundamental array problem. The goal is to find both the largest and the smallest numbers in an array with the fewest number of comparisons possible.

How it works (Linear Scan Method):

Initialize: Assume the first element is both the temporary min and max.

Traverse: Loop through the rest of the array (from the second element to the end).

Compare:

If the current element is greater than max, update max.

If the current element is smaller than min, update min.

Result: Once the loop finishes, you have the true minimum and maximum.

Complexity:

Time Complexity: O(n) - We scan the array once.

Space Complexity: O(1) - We only store two variables.