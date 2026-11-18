# Remove Nth Node From End of List

## Approach: Two Pointers

The idea behind this problem is that `n` represents the position of the node **from the end of the linked list**, not from the beginning. That was the main trap.

After understanding the two-pointer technique, the approach becomes clear:

1. Define two pointers, `fast` and `slow`, both pointing to the beginning of the linked list (`head`).

2. First, move `fast` forward by `n` nodes.

3. After that, check whether `fast` is pointing to `nullptr` or not.
   - If it is `nullptr`, it means that `n` is equal to the length of the linked list. In this case, we simply return `head->next`, since we need to remove the head node.

4. Otherwise, continue moving both pointers forward, one node at a time, until `fast` reaches the last node.

5. At this point, `slow` should be pointing exactly to the node **before the one we want to delete**.

6. Now, we save the address of the node we want to delete using a temporary pointer:
   - Save `slow->next` in a temporary pointer.
   - Move `slow->next` to `slow->next->next`, skipping the node we want to remove.
   - Delete the temporary node to free its allocated memory.

And that's it! We return `head`.

## Complexity Analysis

- **Time Complexity:** `O(L)` — We traverse the linked list only once, where `L` is its length.
- **Space Complexity:** `O(1)` — We only use a constant number of pointers.
