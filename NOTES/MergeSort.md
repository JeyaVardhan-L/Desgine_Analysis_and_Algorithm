# Merge Sort

Merge Sort is a highly reliable divide-and-conquer algorithm. It works by repeatedly breaking down a list into several sublists until each sublist consists of a single element, and then merging those sublists in a manner that results in a sorted list.



### Complexity Analysis
* **Time Complexity:** O(n log n) across the board (Best, Average, and Worst cases). This predictability is Merge Sort's greatest strength. It will never randomly slow down on you.
* **Space Complexity:** O(n). Unlike Quick Sort, Merge Sort requires creating temporary arrays to hold data during the merging phase, which means it uses more memory.

### Why is this important?
Merge Sort is perfectly stable and predictable. If you are sorting a massive dataset where you absolutely cannot afford a worst-case scenario slow-down, Merge Sort is the go-to. It is also the standard choice for sorting Linked Lists, because nodes can be merged by just changing pointers without needing massive blocks of extra memory.