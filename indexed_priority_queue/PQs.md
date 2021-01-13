# Priority Queue

---

## Why should you read the document?
* Before jumping to Indexed Priority Queue(IPQ), you should know what is Priority Queue.
* If you know what they're and their Binary-Heap/D-arry Heap implementation you can move on.

---
## What is a Priority Queue?
* PQ is an Abstract Data Type which operates similar to queue except that each element has a certain priority with which it is pop-ed. I.e. Priority defines the order of removal.
Note: Only same data type can be stored.

---
## PQ vs. Heap
* PQ is an ADT which is usually implemented using Heap, but mind me, there is a difference between both of them.
* PQ can be implemented using a Heap or any other data type like unsorted vector, etc. But it happens so that different heaps provide most efficient implementations.

---
## What is a Heap?
* A tree based DS that satisfies 'Heap Invariant'.
* Heap Invariant - A ordering that is satisfied between an node i & node j, s/t node i is parent of j, is satisfied by all the (Parent, Child) pairs.
* Tree is a complete tree.
* Most generic is a binary heap, but other implementations include Fibonacci, Indexed, Binomial, etc.

---
## Usage
* Dynamic fetch for next best/worst value
* Huffmann Coding
* Maximum/Minimum Spanning Trees

---

## Standard Instructions
* Create
* Push
* Pop
* Top
* Delete
* Find

---

## Time Complexity for Binnary/D-arry Heap
* Create    Naive - O(n log(n))     Heapify - O(n) {Yet to see how that is done}
* Push      O(log n)
* Pop       O(log n)
* Top       O(1)
* Delete    Naive - O(n)            Advance with Hash Table - O(log n)
* Find      Naive - O(n)            Advance with Hash Table - O(1)

---

## What is Complete Binary Tree property?
* Every level is completely filled, except the last.
* Nodes are as far left as possible.

---

## Implementations
* One of the best way to implement is to index each node in heap, top to bottom, righ to left, from Zero to N.
* Store it in an array/vector, with the same indices.
```
if i == parent:
    child_1 == 2*i + 1
    child_2 == 2*i + 2
```
PS: The above is for binary, code could be modified to D-arry as required.
---

## Functions
Note: Considering Min-Heap
### PUSH
1. Add a new node at bottommost, leftmost position (k) 
2. Compare k's value with parent
3. If smaller swap and update k to its parent index
4. Else exit
5. Goto 2

### POP
1. Replce zeroth index node with last node.
2. Compare k's value with its smallest child, 
3. If larger than swap and update k to its parent index
4. Else exit
5. Goto 2


### Delete
1. Naive: Linear search for the value
1. Advanced: Find the index wrt value in the table
2. Replce value at node with bottommost, right-most position node.
3. Compare k's value with parent
4. If smaller swap and update k to its parent index
5. Else exit
6. Goto 3

Note: More than one instance of the value can cause trouble with the advanced approach. Solution is to map multiple indices to the same value.

### Top
1. Return the value stored at index 0.

### Find
#### Naive
1. Search the table to find the value.
#### Advanced
1. Check in the map
---
