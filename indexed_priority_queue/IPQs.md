# Indexed Priority Queue

---
## Why should you read the document?
* Before jumping to the code or documentaion, it is good to know what has been implemented.
* We are using a Min-IPQ so this describes everything with that bias.

## What is an Indexed Priority Queue?
* IPQ is an Abstract Data Type which operates similar to PQ with addition that it allows you to see, modify and delete values at any index in the tree.
Note: Only same data type can be stored.

---
## Implementation
### Data Structures:
* One Array to store value
* Two Arrays (Position Map & Inverse Look-Up Map) for Binary Maping
* User is required to generate and maintain a table of Data-Key pair mapping, Key has to be of range [0, N), where N is the maximum possible size of the heap.

### Usage
* It takes in a key, and returns the respective value.
* Maintains an indexed binary/d-arry heap to maintain the structure.
* Stored in order of the key
* Position Map give you the position of value wrt to key in the heap.
* Inverse Look-Up use the input as index and gives you the key at the input index.
---

## Standard Instructions
* Create
* Push
* Pop
* Top
* Delete
* Is Present?
* Value Of
* Update 

---

## Time Complexity for Indexed Binnary/D-arry Heap
* Create        O(n log(n))
* Push          O(log n)
* Pop           O(log n)
* Top           O(1)
* Delete        O(log n)
* Is Present?   O(1)
* Value of      O(1)
* Update        O(log n)

Note: There can be 3 different versions of pop, top and delete. One where it returns the key, one where it returns the value and last one where it returns both.
---

## Functions

### PUSH
1. Add a new node at bottommost, leftmost position (k) 
2. Compare k's value with parent
3. If smaller swap and update k to its parent index
4. Else exit
5. Goto 2

### POP
1. Get the key at index 0.
2. Go to key.
3. Replce zeroth index node with last node.
4. Compare k's value with its smallest child, 
5. If larger than swap and update k to its parent index
6. Else exit
7. Goto 4


### Delete
1. Given the key as input, go to the key in the array
2. Find its index in the heap
3. Replace it with last node.
4. Compare k's value with its smallest child, 
5. If larger than swap and update k to its parent index
6. Else exit
7. Goto 4

Note: More than one instance of the value can cause trouble with the advanced approach. Solution is to map multiple indices to the same value.

### Top
1. Get the key at index 0.
2. Go to the key and return the value.

### Is Present?
1. Check if the key has a value stored in it.

### Value of
1. Return the value at the given key

### Update
1. Update the value at the given key
2. Compare it with its parent and child
3. If doesn't satisfy the property, exchange
4. Else break
5. Goto 2

---