# Linked List
Implementation of a double linked list.
Node of this List ``` Element<T> ``` stores two pointers  ``` Element<T>* next ``` - on next node and ``` Element<T>* prev``` - previous node.
Linked List has:
1) different constructors, including copy constructor
2) push_back function - one can push back ``` Element<T> ``` or ``` T info ```
3) insert to the specified location ``` insert(int index, t info) ```:

   + In the beginning, the new node is the head -> ``` insert(0, info) ``` 
   + In the end, the new node is the tail -> ``` insert(list.size(), info) ```
   + Between the head and tail, ![equation][0<=index<=list.size()](https://latex.codecogs.com/svg.image?&space;0<=index<=list.size()) -> ``` insert(index, info) ```
