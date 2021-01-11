# Definitions & Declaration for use of indexed_priority_queue.h:

---

## About
 * Data Structure   :   Indexed Priority Queue implemented using Indexed Heap
 * Author 	        :   Aliasgar Musani <cs17b004 at iittp dot ac dot in> / <aliasgarmusani at gmail dot com>
 * Institute 	    :   Indian Institute of Technology Tirupati
 * Part of final year BTech Project
 * Professor	    :	Dr. Raghavendra K <raghavendrak at iittp dot ac dot in>

---

## Functioning
1. This is a min Indexed PQ implemantation using a min Indexed Heap.
1. For a set of M objects to be stored in the Priority Queue.
2. Each object is assigned a specific key, having a value [0, M).
3. Its value and key is inserted in heap.
4. Currently the objects supported are only of type numeric + char, it's open for contributors to make it support other data types.

Tip: If you want to use it is a max and to store numeric types, just negate your values while pushing / updating. And make sure to negate it again while using.
---

## Declaration
1. D-Arr PQ:
```C++
I_PQ<Type> name(int maxSize, int Degree);
```

2. Binary PQ:
```C++
I_OQ<Type> name(int maxSize)
```
---

## Variables:
1. Max size of the heap allowed:
```C++
int mSz;
```
2. Current size of the heap:
 ```C++
int cSz;
```

3. Values:
```C++
T vals[mSz];
```
PS: T is the data type, currently comparison is supported only for numeric types.

4. Position Map - Specifies at what position in the tree is the element present:
```C++
int posM[mSz];
```
Note: Position is standard BFS of the heap tree from root and left to right.

5. Ineverse Look Up Map - Inverse look up for position:
```C++
int invM[mSz];
```
Basically `invM[i]` gives what element is stored at position i in the heap.
Note: `posM[invM[i]] = invM[posM[i]] = i`

6. Degree of the heap tree:
```C++
int D;
```

7. Parent Array to maintain the parent node index:
```C++
int parent[mSz];
```

8. Child Array to maintain the index of first child
```C++
int child[mSz];
```

Note: 7 & 8 aren't required as such, but are used to make calculations a little less.

--

## Functions

--- 

### Public
1. Constructor:
a.
```C++
I_PQ (int max_Size, int degree)
```
b. 
```C++
I_PQ (int max_Size)
```

2. Returns current size of the heap:
```C++
int currSize ()
```

3. Returns max size of the heap:
```C++
int maxSize ()
```

4. To check hether the heap is empty or not, returns t/f:
```C++
bool empty ()
```

5. To check whether any value for a given key is present, return t/f:
```C++
bool checkI (int key)
```

6. To check the key at the top position, returns key of the top element:
```C++
int topI ()
```

7. To remove the topmost element, returns the key of the top element:
```C++
int popI ()
```

8. To check the value at the top position, returns value of the top element:
```C++
T top ()
```

9. To remove the topmost element, returns the key of the top element:
```C++
T pop ()
```

10. To check the value at the top position, returns pair of key & value of the top element:
```C++
pair<int, T> topJ ()
```

11. To remove the topmost element, returns pair of key & value of the top element:
```C++
pair<int, T> popJ ()
```

12. To insert new values:
```C++
void push (int key, T value)
```

13. To get value respective to particular key, returns the value associated with the given key:
```C++
T valAt (int key)
```

14. To delete value respective to particular key, returns the value associated with the given key:
```C++
T deleteAt (int key)
```

15. To update value respective to particular key, returns the value associated with the given key:
```C++
T updateAt (int key)
```

16. To update only when the value has increased from the ealier.
```C++
void increase (int key, int value)
```

17. To update only when the value has decreased from the ealier.
```C++
void decrease (int key, int value)
```

---

### Private
1. To bubble down/sink the value at given index to correct position in the tree, after updation to the tree: 
```C++
void bubble_down (int index)
```


2. To bubble up/swim the value at given index to correct position in the tree, after updation to the tree: 
```C++
void bubble_up (int index)
```

3. To find the minimum child of the given index. Returns the index of the child or, -1 if the current value is actually lesser than any of its children:
```C++
int minChild (int i)
```

4. Swap the nodes:
```C++
void swap (int index_1, int index_2)
```

5. To check which value is lesser among the given to index, returns true if value at pos i is lesser than value at pos j:
```C++
bool less (int i, int j)
```

---

### Internal Error Handling Functions

1. Throws an error if there is no instance of the given key:
```C++
void presenceCheck (int key)
```

2. Throws an error if there is an instance of the given key:
```C++
void absenceCheck (int key)
```

3. Throws an error if the heap is empty:
```C++
void emptyCheck()
```

4. Throws an error if the key is out of bounds:
```C++
void boundsCheck(int key)
```

Note - Commented function:
1. Throw error if the given value to insert is NULL:
```C++
void valueCheck (T val)
```
It is not required because currently it is capable of only handling the numeric values.
It has to be updated it if needed to be used in future, as in C++, while comparing the NULL value equals zero for numeric types.

---

## Attahced Files:

1. indexed_priority_queue.h
1. Readme.md - Gives a descrition of the code and respective files.
2. Few basic test files:
    (a) testIPQ.cpp - push and pop
    (b) testIPQD.cpp - push and pop for D-arr
    (c) testIPQpopJ.cpp - push, popJ & topJ
    (d) testIPQpopJD.cpp - push, popJ & topJ for D-arr
    (e) testIPQUpdate.cpp - updateAt, deleteAt & valueAt
    (f) testIPQUpdateD.cpp - updateAt, deleteAt & valueAt for D-arr

---

## Pending work:
1. Test Bench Setup
2. Testing of currSize, maxSize, checkI, topI, popI, increase and decrease
3. Detailed document on Heap and Indexed Heap
4. Support for objects other than numeric type
5. checkVal function
6. Could check out if PQ creation can use a heapify and then implement it not sure on this, contact me for reference to it. 
6. WIP..

PS: Probably I am not going to do the remaining work as this is a part of another project which I am working on and it doesn't majorly require the remaining stuff, if someone wants he is free to contribute to this or make it more efficient.

---

