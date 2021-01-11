# Definitions & Declaration for use of indexed_heap.h:

---

## Original Author
 * Data Structure:  Indexed Heap
 * Author 	: 	    Aliasgar Musani <cs17b004 at iittp dot ac dot in>
 * Institute 	:	Indian Institute of Technology Tirupati
 * As a part of final year BTech Project
 * Professor	:	Dr. Raghavendra K <raghavendrak at iittp dot ac dot in>

## indexed_priority_queue.h

#### Constructor
a.
```C++
I_PQ (int max_Size, int degree)
```
b. 
```C++
I_PQ (int max_Size)
```
---

#### Public Functions
```C++
int currSize ()
```

```C++
int maxSize ()
```

```C++
bool empty ()
```

```C++
bool checkI (int key)
```

```C++
int topI ()
```

```C++
int popI ()
```

```C++
T top ()
```


```C++
T pop ()
```

```C++
pair<int, T> topJ ()
```

```C++
pair<int, T> popJ ()
```

```C++
void push (int key, T value)
```

```C++
T valAt (int key)
```

```C++
T deleteAt (int key)
```

```C++
T updateAt (int key)
```

```C++
void increase (int key, int value)
```

```C++
void decrease (int key, int value)
```

#### Private Functions

```C++
void bubble_down (int index)
```

```C++
void bubble_up (int index)
```

```C++
int minChild (int i)
```

```C++
void swap (int index_1, int index_2)
```

```C++
bool less (int i, int j)
```


#### Internal Error Handling Functions


```C++
void presenceCheck (int key)
```


```C++
void absenceCheck (int key)
```


```C++
void emptyCheck()
```


```C++
void boundsCheck(int key)
```

#### Commented function:

```C++
void valueCheck (T val)
```

### Test Files:


1. testIPQ.cpp - push and pop
2. testIPQD.cpp - push and pop for D-arr
3. testIPQpopJ.cpp - push, popJ & topJ
4. testIPQpopJD.cpp - push, popJ & topJ for D-arr
5. testIPQUpdate.cpp - updateAt, deleteAt & valueAt
6. testIPQUpdateD.cpp - updateAt, deleteAt & valueAt for D-arr


### MD Files
1. Readme.md
2. Contributions.md
3. Documentaion.md

---

---

