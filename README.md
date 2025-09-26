# Linked-lists
# Experiment 17: Linked Lists in C++
---
## Aim
To study and implement linked list data structures in C++ by performing:
1. Basic node creation and understanding syntax.
2. Linking multiple nodes together and traversing the list.
3. Insertion of nodes at the head of the list.

---

## Tools Used
VS Code

---


## Theory

## Linear Data Structures
- A linear data structure stores elements sequentially and allows traversal in a single logical sequence.
- Examples: Arrays, Stacks, Queues, Linked Lists.
- Operations like insertion, deletion, and traversal are performed sequentially.
- Linear data structures are used to implement many real-world systems and dynamic storage solutions.

---

## Linked Lists
- A linked list is a **dynamic linear data structure** consisting of nodes.
- Each node contains:
  - **Data** – the value stored.
  - **Pointer (next)** – address of the next node.
- The first node is called the **head**.
- The last node points to **NULL** (except in circular lists).
- Nodes are stored **non-contiguously** in memory and connected via pointers.

---

## Block Representation of a Node

```
+-----------+-----------+
|   Data    |   Next    |
+-----------+-----------+

```

### Example of linked list with multiple nodes
```
Head → [11 | next] → [4 | next] → [6 | NULL]

```

---

## Types of Linked Lists
### 1. Singly Linked List
- Each node contains data and a pointer to the next node.
- Traversal is only forward.
- Requires less memory per node (only one pointer).
- Insertion and deletion are easier at the beginning.
- Searching requires traversal from head.
- Last node points to NULL.
```
[Head] -> [Data | Next] -> [Data | Next] -> [Data | Next] -> NULL
```

### 2. Doubly Linked List
- Each node has three fields: data, next pointer, previous pointer.
- Traversal is forward and backward.
- Requires more memory per node.
- Insertion and deletion are easier at any position.
- Suitable for Undo/Redo operations.
- First node prev = NULL, last node next = NULL.
```
NULL <- [Prev | Data | Next] <-> [Prev | Data | Next] <-> [Prev | Data | Next] -> NULL
```

### 3. Circular Linked List
- Last node points back to the first node.
- Can be singly or doubly circular.
- Useful for round-robin scheduling.
- Traversal is continuous; no NULL termination.
- Memory is efficiently used; no dead ends.
- Used in cyclic structures like buffers and queues.

```
      +-----------------------------+
        |                             |
[Head] -> [Data | Next] -> [Data | Next] -> [Data | Next]
        ^                             |
        +-----------------------------+
```

---

## Difference between Types of Linked Lists


| Feature                    | Singly Linked List            | Doubly Linked List                     | Circular Linked List                       |
|----------------------------|-------------------------------|----------------------------------------|--------------------------------------------|
| Direction of Traversal     | Forward only                  | Forward and backward                   | Forward only (Singly) or both (Doubly)     |
| Number of Pointers per Node| 1 (Next)                      | 2 (Prev and Next)                      | 1 or 2 (depending on singly/doubly)        |
| End of List                | NULL                          | NULL                                   | Last node points to Head                   |
| Insertion Complexity       | Easy at head, moderate at tail| Easy at head/tail, moderate in middle  | Easy at head, moderate at tail/middle      |
| Deletion Complexity        | Moderate                      | Easy if pointer to node is known       | Moderate, need to adjust circular link     |
| Memory Requirement         | Low (1 pointer per node)      | Higher (2 pointers per node)           | Slightly higher than singly, depends       |
| Traversal Cost             | Linear                        | Linear                                 | Linear, but can loop infinitely            |
| Use Case                   | Simple lists, stacks          | Undo/Redo, Browser history             | Round-robin, circular queues               |
| Head Pointer               | Required                      | Required                               | Required                                   |
| Tail Pointer               | Optional                      | Optional                               | Useful to keep for circular navigation     |

---

## How a Linked List Works
- A linked list consists of nodes connected via pointers.
- Each node stores data and the address of the next node.
- Head points to the first node.
- Traversal follows the next pointers until NULL.
- Deletion updates the previous node’s pointer and frees memory.
- Nodes can exist at scattered memory locations.

---

## Memory Storage
- Nodes are dynamically allocated in the heap.
- Non-contiguous storage allows flexible size.
- Each node stores the address of the next node.
- Memory fragmentation does not affect linked list traversal.
- Extra memory is required for pointers compared to arrays.

---

## Advantages of Linked Lists over Arrays

1. Dynamic Size:
   - Linked lists can grow or shrink at runtime.
   - No need to predefine the size, unlike arrays which have a fixed size.
   
2. Efficient Insertions/Deletions:
   - Inserting or deleting a node in a linked list (especially at the head or middle) is faster.
   - Only pointers need to be updated, no shifting of elements like in arrays.
   
3. Memory Utilization:
   - No memory wastage due to unused elements (as can happen with arrays if preallocated size is large).
   - Nodes are allocated dynamically, so memory is used as needed.
   
4. Easy to Implement Complex Data Structures:
   - Linked lists can be used to implement stacks, queues, graphs, and other structures more efficiently.
   
5. Flexibility:
   - Nodes can be easily rearranged by changing pointers without moving the actual data.

---

## Disadvantages of Linked Lists over Arrays

1. Extra Memory:
   - Each node requires extra memory for storing pointer(s) in addition to the data.
   
2. Sequential Access:
   - Cannot access elements by index directly; must traverse from head (O(n) access time).
   - Arrays allow direct indexing (O(1) access time).
   
3. Cache Performance:
   - Arrays have better cache locality since elements are stored contiguously in memory.
   - Linked lists are scattered in memory, which can lead to slower access.
   
4. Complexity:
   - Linked lists require more careful handling of pointers (risk of memory leaks or dangling pointers).
   
5. Reverse Traversal:
   - Singly linked lists do not allow backward traversal without extra work.
   - Doubly linked lists solve this but increase memory usage.
   
6. Searching:
   - Searching for an element requires linear traversal (O(n)), unlike arrays where binary search is possible on sorted data.

---

## Difference Between Array, Stack, Queue, and Linked List


| Aspect              | Array                          | Stack                           | Queue                           | Linked List                          |
|---------------------|--------------------------------|---------------------------------|---------------------------------|--------------------------------------|
| Structure           | Contiguous memory              | LIFO (Last In First Out)        | FIFO (First In First Out)       | Nodes connected via pointers         |
| Access              | O(1) by index                  | O(n) search                     | O(n) search                     | O(n) traversal                       |
| Insertion           | Costly (shifting needed)       | O(1) push/pop at top            | O(1) enqueue/dequeue at ends    | O(1) at head/tail                    |
| Deletion            | Costly (shifting needed)       | O(1) at top                     | O(1) at front                   | O(1) with pointer update             |
| Size                | Fixed                          | Dynamic (if implemented with LL)| Dynamic (if implemented with LL)| Dynamic, flexible size               |
| Memory              | Only data stored               | Structure overhead if dynamic   | Structure overhead if dynamic   | Extra pointer per node               |
| Traversal           | Forward/backward via index     | Forward only                    | Forward only                    | Forward (and backward if doubly)     |
| Applications        | Tables, matrices               | Function calls, undo stack      | Scheduling, buffering           | Dynamic memory management, graphs    |


---

## Algorithms and Flowcharts

### Program 1: Basic Node Creation

**Algorithm**
1. Start.
2. Define Node class with data and pointer.
3. Create a new node dynamically.
4. Print data and pointer.
5. Stop.

**Flowchart**
```
+----------------+
|     Start      |
+----------------+
       |
       v
+----------------------+
| Create Node (data=20)|
+----------------------+
       |
       v
+----------------+
| Print data,next|
+----------------+
       |
       v
+----------------+
|      End       |
+----------------+

```

---


### Program 2: Linking Multiple Nodes

**Algorithm**
1. Start.
2. Create multiple nodes dynamically.
3. Link nodes sequentially.
4. Traverse list from head and print data.
5. Stop.

**Flowchart**
```
+----------------+
|     Start      |
+----------------+
       |
       v
+--------------------------+
| Create 3 nodes (n1,n2,n3)|
+--------------------------+
       |
       v
+--------------------+
| Link n1->n2, n2->n3|
+--------------------+
       |
       v
+--------------------+
| Traverse from head |
+--------------------+
       |
       v
+----------------+
| Print all data |
+----------------+
       |
       v
+----------------+
|      End       |
+----------------+

```

---

### Program 3: Insertion at Head

**Algorithm**
1. Start with head = NULL.
2. Create a new node.
3. Set new_node->next = head.
4. Update head = new_node.
5. Display list.
6. Repeat as needed.
7. Stop.

**Flowchart**
```
+----------------+
|     Start      |
+----------------+
       |
       v
+--------------------------+
| head = NULL (empty list) |
+--------------------------+
       |
       v
+-------------------------+
| Call insert_head(data)  |
+-------------------------+
       |
       v
+----------------------+
| Create new node      |
+----------------------+
       |
       v
+-----------------------------+
| new_node->next = head       |
+-----------------------------+
       |
       v
+----------------------+
| head = new_node      |
+----------------------+
       |
       v
+---------------------+
| Display Linked List |
+---------------------+
       |
       v
+----------------+
|      End       |
+----------------+

```

---

## Industrial Applications of Linked Lists
1. **Memory Management Systems** – dynamic allocation, free lists; Microsoft, Linux.  
2. **File Systems** – FAT (File Allocation Table); Microsoft FAT32, IBM.  
3. **Operating Systems** – process scheduling queues; Red Hat, Windows, Ubuntu.  
4. **Networking** – packet buffering and routing; Cisco, Juniper.  
5. **Database Systems** – indexing, rollback features; Oracle, MySQL, PostgreSQL.  
6. **Compilers** – syntax trees, symbol tables; GCC, LLVM.  
7. **Gaming & Graphics** – scene graphs, animations; Unity, Unreal Engine.  
8. **Telecommunication Systems** – call/message queues; Nokia, Ericsson, Huawei.

---

## Significance
- Dynamic memory utilization and flexible size.
- Efficient insertion and deletion for real-time systems.
- Backbone for advanced data structures (graphs, hash maps).
- Reduces memory wastage.
- Useful for queues, scheduling, and buffer management.
