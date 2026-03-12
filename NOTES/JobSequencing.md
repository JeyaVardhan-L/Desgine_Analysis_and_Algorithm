# Job Sequencing with Deadlines

This is a classic Greedy Algorithm problem. The objective is to maximize your total profit by scheduling a given set of jobs within their respective deadlines. Each job takes exactly one unit of time to complete.

The greedy strategy here is simple: always prioritize the jobs that pay the most, and try to schedule them as close to their deadline as possible to keep earlier time slots open for other jobs.

### Complexity Analysis
* **Time Complexity:** O(n log n) + O(n * d)
  * Sorting the jobs using `qsort` takes O(n log n) time.
  * For each job, we might scan backwards from its deadline 'd' to find an empty slot, taking O(n * d) time in the worst case (where 'd' is the maximum deadline).
* **Space Complexity:** O(d) - We dynamically allocate memory for the time slots array proportional to the maximum deadline 'd'.

### Real-World Use Cases
1. **CPU Task Scheduling:** Operating systems use variations of this to prioritize high-value processes that need to be executed within a certain timeframe.
2. **Manufacturing:** Scheduling high-priority client orders on an assembly line that only has a limited number of production slots per day.