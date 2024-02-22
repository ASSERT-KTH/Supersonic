The provided code implements a topological sort algorithm using a vector of vectors to represent the adjacency list of a directed graph. The algorithm calculates the in-degree of each vertex and uses a stack-based approach to perform the topological sort. 

Upon analyzing the code, the following optimizations can be made to improve performance and memory usage:

1. Use a more efficient data structure for the adjacency list:
   The current implementation uses a vector of vectors to represent the adjacency list. However, this can be optimized by using a single vector and storing the target vertices directly without the need for the `Edge` struct. This change will reduce memory usage and eliminate the need for unnecessary object constructions and function calls.

2. Avoid unnecessary copies of vectors:
   In the current code, the `topological_order` vector is repeatedly copied during the topological sort loop. This can be avoided by using a single vector and keeping track of the position to insert the next vertex. This change will reduce memory usage and improve performance.

3. Reduce the number of assertions:
   The code includes assertions to check the correctness of the input graph and the topological order. While assertions can be useful during development, they have a performance impact. In a production environment, it is better to remove these assertions or replace them with error handling code.

4. Use a more efficient loop for inserting zero-indegree vertices:
   The current code iterates over all vertices to find the ones with zero in-degree. This can be optimized by using a separate vector to store the zero-indegree vertices and updating it during the calculation of in-degrees. This change will reduce the time complexity of finding zero-indegree vertices from O(V) to O(1) per vertex.

5. Optimize the loop for decrementing in-degrees:
   The loop that decrements the in-degrees of the target vertices can be optimized by using a reverse loop and accessing the `G[v]` vector directly instead of using the `Edge` struct. This change will eliminate unnecessary object constructions and function calls.

6. Use pass-by-reference to avoid copying the input graph:
   The `topological_sort` function currently takes the graph `G` by value, which results in a copy of the input graph being made. To avoid this unnecessary overhead, the function should take the graph by reference.
