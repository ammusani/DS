# Definitions & Declaration for use of indexed_heap.h:

---

## About
 * Data Structure:  Indexed Heap
 * Author 	: 	    Aliasgar Musani <cs17b004 at iittp dot ac dot in>
 * Institute 	:	Indian Institute of Technology Tirupati
 * As a part of final year BTech Project
 * Professor	:	Dr. Raghavendra K <raghavendrak at iittp dot ac dot in>

---

## Functioning
1. This is a min Indexed PQ implemantation using a min Indexed Heap.
1. For a set of M objects to be stored in the Priority Queue.
2. Each object is assigned a specific key, having a value [0, M).
3. Its value and key is inserted in heap.
4. Currently the objects supported are only of type numeric + char, it's open for contributors to make it support other data types.

Tip: If you want to use it is a max and to store numeric types, just negate your values while pushing / updating. And make sure to negate it again while using.

---

## Attahced Files:

1. indexed_priority_queue.h
2. Readme.md
3. Few basic test files:
    (a) testIPQ.cpp - push and pop
    (b) testIPQD.cpp - push and pop for D-arr
    (c) testIPQpopJ.cpp - push, popJ & topJ
    (d) testIPQpopJD.cpp - push, popJ & topJ for D-arr
    (e) testIPQUpdate.cpp - updateAt, deleteAt & valueAt
    (f) testIPQUpdateD.cpp - updateAt, deleteAt & valueAt for D-arr
4. Documentation.md
5. Contributions.md

---

## Pending work:
1. Test Bench Setup
2. Testing of currSize, maxSize, checkI, topI, popI, increase and decrease
3. Detailed document on Heap and Indexed Heap
4. Support for objects other than numeric type
5. checkVal function
6. Could check out if PQ creation can use a heapify and then implement it not sure on this, contact me for reference to it. 
6. WIP..

PS: 
* Probably I am not going to do the remaining work as this is a part of another project which I am working on and it doesn't majorly require the remaining stuff. 
* If someone wants he is free to contribute to it by finishing the task from above list or make the code more efficient. 
* Just maintain the proper documentation and add your contribution to Contributions.md to get PR accepted.

---

