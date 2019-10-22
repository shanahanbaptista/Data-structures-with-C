# CS580u Programming and System Tools
## Shanahan Michael Baptista - Binghamton University (Fall 2018)

## REFERENCES:
- To delete a node in a doubly linked list, the basic concept was found here,
https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/


## Part A: Vectors

Creation of a dynamic array data structure, Vector. Struct and internal array have been created on the heap (using malloc). Dynamic array has, at minimum, the following:

    ```
        Data data //A pointer to a Data struct array
        int current_size//an integer containing the current size
        int max_size // an integer containing the maximum capacity
        void (*insert)(Vector *, int, Data) //a function pointer to an insert function
        Data * (*read)(Vector *, int)//a function pointer to an read function
        void (*remove)(Vector *, int)//a function pointer to an delete function
        void (*delete)(Vector *)//a function pointer to a destructor
    ```
* Constructor - initializes the vector struct attributes and returns a pointer to a Vector struct created on the heap
    * `Vector * newVector()`

:bulb: The remaining function names are suggestions since the driver code calls them all via function pointers

* Insert - inserts an element at the specified index. Use the 2n+1 geometric expansion formula to increase the size of your list if the index is out of the current bounds.
    * `void insertVector(Vector *, int, Data);`
* Remove - deletes an element from the list at the specified index.
    * `void removeVector(Vector *, int);`
        * You must implement true deletion, which will reduce the size of the vector by 1
* Read - return the pointer to the data struct from the specified index, return NULL if the index is out of bounds, and a data struct with the value set to -1 if the index has not been initialized
    * `Data * readVector(Vector * array, int index);`
* Destructor - free all allocated memory for the vector
    * `void * deleteVector`
        * frees all struct memory
        * You should return a NULL pointer from any delete procedure. This is just a convention.

## Part B: Linked Lists

The node struct has the following:
```
    struct Node * next/prev; // A pointer to the next and previous nodes
    Data data; // A data object (:note: not a pointer)
```
The list struct has the following:
```
    Node * head, tail //A pointer to nodes at the head and tail
    void (*insert)(List *, int, Data) //a function pointer to an insert function
    Data * (*read)(List *, int) //a function pointer to a read function
    void (*remove)(List *, int) //a function pointer to an delete function
    void (*delete)(List *) //a function pointer to a destructor
```
Creation of a doubly linked list using a list and node structs. Linked list has been created on the heap (using malloc). The linked list has the following operations:
* Constructor - initializes the linked list struct:
    * `List * newList()`
        * A pointer to a head and tail node, both initialized to NULL
        * set function pointers to the appropriate functions
        * returns a pointer to a List struct created on the heap

:bulb: The remaining function names are suggestions since the driver code calls them all via function pointers

* Insert - inserts an element at a specified index in the list.
    * `void insertList(List * list, int index, Data value);`
        * Adds the Data to the specified index
        * If the index is out of bounds, adds the data to the end of your list.
* Delete - deletes an element from a specified index in the list.
    * `void removeData(List * list, int index);`
        * If the index is out of bounds, you should just return without doing anything.
* Read - returns a pointer to the data element stored in the list
    * `Data * readData(List * list, int index);`
        * If the index is out of bounds, return a NULL pointer

## Part C: Stacks and Queues

### Stack
Code has been broken up into stack.h and stack.c according to conventions learned.

We have two Stack structs, Stacklist and Stackvector. 

#### Stacklist

Stacklist has the following:
```
    List * data;
    Data (*peek)(struct stacklist *);
    Data (*pop)(struct stacklist *);
    void (*push)(struct stacklist *, Data);
    void (*clear)(struct stacklist *);
    void (*delete)(struct stacklist *);
```

Stacklist is created on the heap (using malloc). Stacklist has the following operations:
* Constructor - initializes the List struct:
    * `Stacklist * newStacklist()`
        * initializes internal List struct
        * set function pointers to the appropriate functions
        * returns a pointer to a Stacklist struct created on the heap

:bulb: The remaining function names are suggestions since the driver code calls them all via function pointers

* Push - pushes a value onto the top of the stack
    * `void pushStacklist(struct stacklist *, Data);`
        * Adds the Data to the stack
* Pop - deletes and returns an element from the stack
    * `Data popStacklist(struct stacklist *);`
        * Removes the top element on the stack
        * If the stack is empty return a Data struct with -1 for a value
* Peek - returns an element from the stack without deleting
    * `Data peekStacklist(struct stacklist *);`
        * Returns but does not remove the top element on the stack
        * If the stack is empty return a Data struct with -1 for a value
* Clear - removes all elements form the stack
    * `void clearStacklist(struct stacklist *);`
        * removes all elements from the stack
* Delete - frees all memory associated with the stack
    * `void * deleteStacklist(struct stacklist *);`
        * frees the stack memory, including the stack itself

#### Stackvector

Stackvector has the following:
```
    Vector * data;
    Data (*peek)(struct stackvector *);
    Data (*pop)(struct stackvector *);
    void (*push)(struct stackvector *, Data);
    void (*clear)(struct stackvector *);
    void (*delete)(struct stackvector *);
```

Stackvector is created on the heap (using malloc). Stackvector has the following operations:
* Constructor - initializes the vector struct:
    * `Stackvector * newStackvector()`
        * initializes internal vector struct
        * set function pointers to the appropriate functions
        * returns a pointer to a Stackvector struct created on the heap
* Push - pushes a value onto the top of the stack
    * `void pushStackvector(struct stackvector *, Data);`
        * Adds the Data to the stack
* Pop - deletes and returns an element from the stack
    * `Data popStackvector(struct stackvector *);`
        * Removes the top element on the stack
        * If the stack is empty return a Data struct with -1 for a value
* Peek - returns an element from the stack without deleting
    * `Data peekStackvector(struct stackvector *);`
        * Returns but does not remove the top element on the stack
        * If the stack is empty return a Data struct with -1 for a value
* Clear - removes all elements form the stack
    * `void clearStackvector(struct stackvector *);`
        * removes all elements from the stack
* Delete - frees all memory associated with the stack
    * `void * deleteStackvector(struct stackvector *);`
        * frees the stack memory, including the stack itself

#### Queuelist

Queuelist has the following:
```
    List * data;
    Data (*peek)(struct queuelist *);
    Data (*dequeue)(struct queuelist *);
    void (*enqueue)(struct queuelist *, Data);
    void (*clear)(struct queuelist *);
    void (*delete)(struct queuelist * s);
```

Queuelist is created on the heap (using malloc). Queuelist has the following operations:
* Constructor - initializes the linked list struct:
    * `List * newQueuelist()`
        * initializes internal list struct
        * set function pointers to the appropriate functions
        * returns a pointer to a Queuelist struct created on the heap

:bulb: The remaining function names are suggestions since the driver code calls them all via function pointers

* Enqueue - pushes a value onto the Queue
    * `void enqueueQueuelist(struct queuelist *, Data);`
        * Adds the Data to the Queue
* Dequeue - deletes and returns an element from the Queue
    * `Data dequeueQueuelist(struct queuelist *);`
        * Removes an element from the Queue
        * If the Queue is empty return a Data struct with -1 for a value
* Peek - returns an element from the Queue without deleting
    * `Data peekQueuelist(struct queuelist *);`
        * Returns but does not remove the top element on the Queue
        * If the Queue is empty return a Data struct with -1 for a value
* Clear - removes all elements from the Queue
    * `void clearQueuelist(struct queuelist *);`
        * removes all elements from the Queue
* Delete - frees all memory associated with the Queue
    * `void * deleteQueuelist(struct queuelist *);`
        * frees the Queue memory, including the Queue itself   

#### Queuevector

Queuevector must has the following:
```
    List * data;
    Data (*peek)(struct queuevector *);
    Data (*dequeue)(struct queuevector *);
    void (*enqueue)(struct queuevector *, Data);
    void (*clear)(struct queuevector *);
    void (*delete)(struct queuevector *);
```

Queuevector is created on the heap (using malloc). The Queuevector has the following operations:
* Constructor - initializes the vector struct:
    * `List * newQueuevector()`
        * initializes internal vector struct
        * set function pointers to the appropriate functions
        * returns a pointer to a Queuevector struct created on the heap

:bulb: The remaining function names are suggestions since the driver code calls them all via function pointers

* Enqueue - pushes a value onto the queue
    * `void pushQueuevector(struct queuevector *, Data);`
        * Adds the Data to the queue
* Dequeue - deletes and returns an element from the queue
    * `Data popQueuevector(struct queuevector *);`
        * Removes the next element on the queue
        * If the queue is empty return a Data struct with -1 for a value
* Peek - returns an element from the queue without deleting
    * `Data peekQueuevector(struct queuevector *);`
        * Returns but does not remove the top element on the queue
        * If the queue is empty return a Data struct with -1 for a value
* Clear - removes all elements form the queue
    * `void clearQueuevector(struct queuevector *);`
        * removes all elements from the queue
* Delete - frees all memory associated with the queue
    * `void * deleteQueuevector(struct queuevector *);`
        * frees the queue memory, including the queue itself
