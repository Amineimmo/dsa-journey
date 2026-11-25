# 23. Merge k Sorted Lists

**LeetCode:** [23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)  
**Difficulty:** Hard  
**Topic:** Linked Lists, Divide and Conquer, Two Pointers

## 💡 Approach: Divide and Conquer

Instead of merging all lists sequentially, we merge them in pairs.

Each iteration reduces the number of lists by approximately half until only one sorted list remains.

### Algorithm

1. Initialize an empty vector to store merged lists.
2. Iterate through the input lists, processing two lists at a time.
3. Merge each pair using `mergeTwoLists()`.
4. If the number of lists is odd, carry the last unpaired list into the next iteration.
5. Replace the original vector with the newly merged lists.
6. Repeat until only one list remains.

## 🔧 Helper Function: mergeTwoLists()

Uses a dummy node and a tail pointer to merge two sorted linked lists.

- Compare the current nodes of both lists.
- Attach the smaller node to the merged list.
- Advance the pointer of the selected list.
- Move the tail pointer forward.
- Once one list is exhausted, attach the remaining nodes directly.

**Important:** Existing nodes are reused. No new data nodes are allocated.

## 💻 Complexity Analysis

Let:

- `N` = Total number of nodes across all lists.
- `K` = Number of linked lists.

| Complexity      | Cost         | Explanation                                                         |
| --------------- | ------------ | ------------------------------------------------------------------- |
| Time            | `O(N log K)` | Each node is processed across approximately `log K` merging rounds. |
| Auxiliary Space | `O(K)`       | Temporary vector used to store merged lists.                        |

The merge operation itself uses `O(1)` auxiliary space.

## 🧠 Key Takeaways

- Divide and Conquer reduces the number of lists by half at each iteration.
- A dummy node simplifies linked-list construction.
- Two pointers allow efficient merging without allocating new nodes.
- Remaining nodes can be attached directly because their list is already sorted.
- Odd numbers of lists are handled by carrying the unpaired list forward.

## 🚀 What I Learned

This problem strengthened my understanding of linked-list pointer manipulation, in-place merging, and iterative Divide and Conquer.

**Main lesson:** Instead of repeatedly merging an increasingly large result with the next list, pairwise merging distributes the work across logarithmic rounds.
