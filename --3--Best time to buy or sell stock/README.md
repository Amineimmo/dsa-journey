# Best Time to Buy and Sell Stock

**LeetCode 121 — Easy**

## Approach: Greedy (One Pass)

The idea is to traverse the array once while maintaining two variables:

- `minPrice`: The lowest stock price encountered so far.
- `maxProfit`: The maximum profit found so far.

For each day:

1. Calculate the potential profit if we sell at today's price using the lowest buying price encountered previously.
2. Update `maxProfit` if the current profit is greater.
3. Update `minPrice` if today's price is lower.

**Important:** Calculate the profit before updating `minPrice`. This ensures that the buying day always comes before the selling day.

## Complexity Analysis

- **Time Complexity:** O(n) — We traverse the array only once.
- **Space Complexity:** O(1) — We only maintain two variables.

## Key Takeaway

Instead of checking every possible buying and selling combination (O(n²)), we maintain the minimum buying price encountered so far and calculate the potential profit at each day.

**Pattern:** Greedy / One-pass Array.
