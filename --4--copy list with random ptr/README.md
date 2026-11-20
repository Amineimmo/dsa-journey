# 138. Copy List with Random Pointer

## Approach: Hash Map (Two Passes)

### 1. Understanding the Problem

Unlike a regular linked list, each node contains two pointers:

- `next`: Points to the next node.
- `random`: Points to any node in the list or `nullptr`.

The goal is to create a **deep copy** of the original linked list.

This means:

- Every original node must have a newly allocated copy.
- The copied `next` pointers must reference copied nodes.
- The copied `random` pointers must also reference copied nodes.
- No pointer in the copied list should reference an original node.

### 2. Key Idea

The main challenge is maintaining the relationship between original nodes and their copies.

We use an `unordered_map<Node*, Node*>` to establish this relationship:

- **Key:** Address of the original node.
- **Value:** Address of its corresponding copied node.

This allows us to retrieve any copied node directly using its original node's address.

### 3. Algorithm

**Pass 1 — Create all copied nodes**

- Traverse the original linked list.
- Create a new node for every original node, copying its value.
- Store the relationship between each original node and its copy in the hash map.

At this stage, all copied nodes exist, but their pointers are not connected.

**Pass 2 — Connect the pointers**

- Traverse the original list again.
- For each original node, retrieve its corresponding copy from the map.
- Assign its `next` pointer using the map.
- Assign its `random` pointer using the map.

For example:

If `A.random` points to `C`, then `mp[A]` gives us `A'`, and `mp[C]` gives us `C'`.

Therefore, `A'.random` must point to `C'`.

Accessing `mp[nullptr]` also correctly produces a null pointer.

### 4. Complexity Analysis

Let `n` be the number of nodes.

- **Time Complexity:** O(n) — Two traversals, with average O(1) hash map operations.
- **Space Complexity:** O(n) — The hash map stores one mapping per original node, alongside the newly allocated nodes.

### 5. Key Takeaway

The important insight is that copying pointer-based structures requires more than copying values.

We must preserve the relationships between objects while ensuring that every reference in the copied structure points to the corresponding copied object.

Using a hash map allows us to establish these relationships efficiently.
