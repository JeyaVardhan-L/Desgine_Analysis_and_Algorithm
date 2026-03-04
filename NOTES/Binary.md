Binary Search Logic:

Imagine you have a dictionary and you are looking for the word "Planet." You wouldn't start at 'A' and read every word. You open the book to the middle.

If the middle is "M," you know "P" comes after "M," so you ignore the entire first half of the book.

You split the remaining second half in the middle again.

You keep repeating this until you pinpoint the word.

The Algorithm:

Find the Middle element of the current range.

If Target = Middle: You found it!

If Target < Middle: The answer must be in the Left half.

If Target > Middle: The answer must be in the Right half.

Complexity Analysis

Time Complexity: O(log n) This is extremely fast. For an array of 1,000,000 elements, Linear Search might take 1,000,000 steps. Binary Search takes at most roughly 20 steps (log 1,000,000 base 2 approx 20).

Space Complexity: O(1) (Iterative approach).

Key TakeawayBinary Search is vastly superior to Linear Search for large datasets, but the overhead of keeping the data sorted is the trade-off.