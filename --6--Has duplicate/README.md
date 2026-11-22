# 287. Find the Duplicate Number

**LeetCode Difficulty:** Medium  
**Topic:** Arrays, Hash Set, Hashing  
**Language:** C++

## Problem Description

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive, return the only repeated number.

The array contains exactly one duplicate number, but it may appear more than once.

## Approach: Hash Set

Use an `unordered_set` to keep track of numbers that have already been encountered.

### Algorithm

1. Initialize an empty `unordered_set<int>` called `seen`.
2. Iterate through the array using a range-based for loop.
3. For each number, attempt to insert it into the set using `seen.insert(p)`.
4. Check the `.second` value returned by `insert()`:
   - `true`: The number was successfully inserted, meaning it has not appeared before.
   - `false`: The number already exists in the set, meaning we found the duplicate.
5. Return the duplicate immediately.
6. Return `0` as a fallback (unreachable under the problem constraints).

## C++ Solution

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (auto& p : nums) {
            if (!seen.insert(p).second) {
                return p;
            }
        }

        return 0;
    }
};
```

## Complexity Analysis

Let `n` be the number of elements in the array.

| Complexity | Analysis     |
| ---------- | ------------ |
| Time       | O(n) average |
| Space      | O(n)         |

- **Time:** Each insertion into `unordered_set` takes O(1) average time. We traverse at most `n` elements.
- **Space:** In the worst case, the set stores O(n) distinct elements before finding the duplicate.

## Key C++ Concept: `unordered_set::insert()`

The `insert()` function returns a pair:

- `.first`: An iterator pointing to the inserted or existing element.
- `.second`: A boolean indicating whether insertion actually happened.

This allows us to detect duplicates without explicitly searching the set first.

## Key Takeaway

Hash sets provide an efficient way to detect repeated values through uniqueness enforcement.

**Alternative challenge:** Can you solve this problem using O(1) extra space without modifying the input array? (Hint: Floyd's Cycle Detection Algorithm.)
