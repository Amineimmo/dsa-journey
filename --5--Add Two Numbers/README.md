# 2. Add Two Numbers

**LeetCode Problem:** [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

**Difficulty:** Medium  
**Topic:** Linked List, Mathematics, Simulation

## Approach: Dummy Head + Carry

The key observation is that the two linked lists represent numbers in reverse order. This allows us to perform addition digit by digit, just like elementary-school addition.

Instead of converting the linked lists into integers, we directly simulate the addition using pointers.

### Algorithm

1. Create a dummy node to serve as the starting point of the resulting linked list.
2. Maintain a `tail` pointer to track where the next digit should be inserted.
3. Initialize `carry = 0`.
4. Iterate while at least one input list is not exhausted or a carry remains.
5. Extract the current digit from each list. If a list is exhausted, use `0`.
6. Calculate the sum of both digits and the previous carry:

   `sum = x + y + carry`

7. Extract the digit to insert using `sum % 10`.
8. Update the carry using `sum / 10`.
9. Create a new node containing the calculated digit and append it to the result.
10. Advance the input pointers when possible.

Finally, return `dummy.next`, which points to the actual beginning of the resulting linked list.

### Important Observations

- **Dummy Head:** Simplifies insertion by avoiding special handling for the first node.
- **Carry:** Must be included in every subsequent addition.
- **Different List Lengths:** Missing digits are treated as zero.
- **Final Carry:** The loop must continue if a carry remains, even when both input lists are exhausted.
- **New Nodes:** The result is constructed as a completely new linked list without modifying the original lists.

### Complexity Analysis

Let `n` and `m` be the lengths of the two linked lists.

| Complexity | Cost         | Explanation                                           |
| ---------- | ------------ | ----------------------------------------------------- |
| Time       | O(max(n, m)) | Each input node is visited once.                      |
| Space      | O(max(n, m)) | A new linked list is constructed to store the result. |

### Key Takeaway

The problem is fundamentally about simulating elementary-school addition using linked-list traversal.

The combination of a dummy head, a tail pointer, and a carry variable provides a clean and efficient solution.
