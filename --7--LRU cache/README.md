# 146. LRU Cache

**LeetCode Problem:** [146. LRU Cache](https://leetcode.com/problems/lru-cache/)  
**Difficulty:** Medium  
**Topics:** Hash Table, Doubly Linked List, Design

## Approach: Hash Map + Doubly Linked List

Implement an LRU (Least Recently Used) Cache with two data structures working together to achieve **O(1) average time complexity** for both `get()` and `put()`.

### 1. Data Structures

- **`unordered_map<int, list<pair<int,int>>::iterator>`**
  - Maps each key to an iterator pointing to its node in the linked list.
  - Provides O(1) average lookup.

- **`list<pair<int,int>>`**
  - Stores key-value pairs.
  - Maintains usage order.
  - Front = Most Recently Used (MRU).
  - Back = Least Recently Used (LRU).

### 2. Operations

**GET(key)**

1. Search for the key in the hash map.
2. If it doesn't exist, return `-1`.
3. If it exists, move its node to the front using `list::splice()`.
4. Return its associated value.

**PUT(key, value)**

1. Check whether the key already exists.
2. If it exists:
   - Update its value.
   - Move its node to the front.
3. Otherwise:
   - If the cache is full, remove the least recently used entry from both structures.
   - Insert the new key-value pair at the front.
   - Store its iterator in the hash map.

### 3. Key C++ Concept: `list::splice()`

```cpp
usageOrder.splice(
    usageOrder.begin(),
    usageOrder,
    it->second
);
```

Moves an existing node to the beginning of the list in O(1), without copying or recreating the node.

### 4. Complexity Analysis

| Operation | Average Time |
| --------- | ------------ |
| `get()`   | O(1)         |
| `put()`   | O(1)         |
| Eviction  | O(1)         |
| Space     | O(capacity)  |

### 5. Key Takeaways

- Hash maps provide fast key-based access.
- Doubly linked lists allow efficient node removal and repositioning.
- Iterators connect the hash map to specific linked-list nodes.
- `splice()` allows efficient repositioning without traversal.
- Both data structures must remain synchronized.

**Core insight:** Combining a hash map with a doubly linked list achieves efficient lookup and usage-order management simultaneously.
