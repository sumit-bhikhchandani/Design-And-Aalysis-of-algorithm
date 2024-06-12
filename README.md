# Design and Analysis of Algorithms

## Overview

This repository contains C++ implementations and performance analyses of several algorithms as part of the Design and Analysis of Algorithms course. The key algorithms covered are Merge Sort, Quick Sort, and Kruskal's Algorithm for Minimum Spanning Tree (MST).

## Contents

- [Merge Sort](#merge-sort)
- [Quick Sort](#quick-sort)
- [Performance Comparison: Merge Sort vs Quick Sort](#performance-comparison-merge-sort-vs-quick-sort)
- [Kruskal's Algorithm](#kruskals-algorithm)
- [Performance Comparison: Kruskal's vs Prim's Algorithm](#performance-comparison-kruskals-vs-prims-algorithm)

## Merge Sort

### Description

Merge Sort is a divide-and-conquer algorithm that splits the input array into two halves, recursively sorts each half, and then merges the sorted halves.

### Time Complexity
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

### Space Complexity
- O(n) due to additional space required for temporary arrays.

### Implementation
The code for Merge Sort can be found in `merge_sort.cpp`.

## Quick Sort

### Description

Quick Sort is an efficient, in-place sorting algorithm that selects a 'pivot' element and partitions the array around the pivot, recursively sorting the subarrays.

### Time Complexity
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n^2) (rare, occurs when pivot selection is poor)

### Space Complexity
- O(log n) to O(n) depending on the implementation.

### Implementation
The code for Quick Sort can be found in `quick_sort.cpp`.

## Performance Comparison: Merge Sort vs Quick Sort

### Description

Both Merge Sort and Quick Sort have an average time complexity of O(n log n). However, their performance can vary based on the input data characteristics and implementation details.

### Highlights
- **Merge Sort** is stable and performs consistently across all scenarios.
- **Quick Sort** is an in-place algorithm, often faster in practice due to better cache locality, especially for smaller arrays.

### Implementation
The code comparing Merge Sort and Quick Sort performance can be found in `performance_comparison.cpp`.

## Kruskal's Algorithm

### Description

Kruskal's Algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph by adding edges in increasing order of their weights while avoiding cycles.

### Time Complexity
- **Overall:** O(E log E) due to edge sorting and union-find operations.

### Space Complexity
- O(E + V) where E is the number of edges and V is the number of vertices.

### Implementation
The code for Kruskal's Algorithm can be found in `kruskals_algorithm.cpp`.

## Performance Comparison: Kruskal's vs Prim's Algorithm

### Description

Kruskal's and Prim's algorithms are both used to find the minimum spanning tree (MST) of a graph, but they have different approaches and performance characteristics.

### Highlights
- **Kruskal's Algorithm** is more efficient for sparse graphs.
- **Prim's Algorithm** can be more efficient for dense graphs.

### Implementation
The code comparing Kruskal's and Prim's algorithm performance can be found in `mst_comparison.cpp`.
