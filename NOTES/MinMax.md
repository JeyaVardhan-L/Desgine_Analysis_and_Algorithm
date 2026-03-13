# Find Minimum and Maximum (Pairwise Method)

Finding the minimum and maximum elements in an array is a fundamental operation. While a simple linear scan works, it requires 2(n-1) comparisons in the worst case, because every element is compared against both the current minimum and the current maximum.



To optimize this, we use the **Pairwise Comparison** method. Instead of processing elements one by one, we process them in pairs. We compare the pair against each other first. Then, we compare the larger of the pair against the current maximum, and the smaller of the pair against the current minimum. 

### Complexity Analysis
* **Time Complexity:** O(n). However, the absolute number of comparisons is significantly reduced. By processing in pairs, the total number of comparisons drops to approximately 1.5n (or exactly `3n/2 - 2` comparisons). This is a 25% reduction in operations compared to a naive linear scan!
* **Space Complexity:** O(1) auxiliary space. We only need a few variables to keep track of the current min, max, and the loop index.

### Real-World Use Cases
1. **Computer Graphics:** Finding the bounding box of a 3D object requires finding the minimum and maximum X, Y, and Z coordinates of all vertices.
2. **Data Normalization:** In Machine Learning, preparing a dataset often involves Min-Max scaling, which requires finding the absolute extremes of a feature column to scale the data between 0 and 1.