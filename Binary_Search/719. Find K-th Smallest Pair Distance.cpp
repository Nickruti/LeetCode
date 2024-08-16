// Link to the Problem- https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/?envType=daily-question&envId=2024-08-14
// Problem - 719. Find K-th Smallest Pair Distance
// Difficulty Level - Hard
// Runtime - 9ms

/*
Intuition
When I first looked at this problem, my initial thought was that the brute force approach of calculating all possible pair distances and then finding the k-th smallest would work, but it'd be painfully slow for large inputs. We're talking about potentially millions of calculations for a decent-sized array.
Then it hit me - we don't actually need to calculate all the distances explicitly. What if we could somehow guess the right distance and then check if our guess is too high or too low? This sounds an awful lot like a binary search problem.
But how do we check if our guessed distance is too high or too low? Well, if we can count how many pairs have a distance less than or equal to our guess, we'd know if we need to guess higher or lower.
This led me to think about how to efficiently count pairs with a distance less than or equal to a given value. If we sort the array first, we could use a sliding window approach to count these pairs quickly.
So, the core intuition boils down to:
Use binary search to guess the k-th smallest distance
For each guess, count how many pairs have a distance less than or equal to it
Use this count to decide if we need to guess higher or lower
Approach
Let's break this down step by step:
1. Sorting the Array

First, we sort the input array numbers. This is crucial because it allows us to use a sliding window approach later on. The sorting step takes O(n log n) time, where n is the length of the array. Sorting helps in two main ways:
It allows us to work with distances in a systematic manner (from smallest to largest).
It enables the use of the sliding window technique to efficiently count pairs within a specific distance.
Example:
For the array numbers = [1, 3, 1], after sorting, we get numbers = [1, 1, 3].

2. Setting up Binary Search

We're going to use binary search, but not on the array itself. Instead, we're searching the range of possible distances. The minimum possible distance is 0 (if there are duplicate elements), and the maximum possible distance is the difference between the largest and smallest elements in the sorted array.
minDistance is initialized to 0 (smallest distance).
maxDistance is initialized to numbers[numbers.length - 1] - numbers[0] (largest distance).
Example:
For numbers = [1, 1, 3], the maximum distance is 3 - 1 = 2. So, minDistance = 0 and maxDistance = 2.

3. Binary Search Loop

We enter a loop that continues while minDistance < maxDistance. In each iteration:

a) Calculate the Midpoint Distance: midDistance = minDistance + (maxDistance - minDistance) / 2

We calculate the middle distance (midDistance) of the current search range. This midDistance represents our "guess" for the k-th smallest distance.
(We use this formula instead of (minDistance + maxDistance) / 2 to avoid potential integer overflow)
 int midDistance = minDistance + (maxDistance - minDistance) / 2;
Example:
For minDistance = 0 and maxDistance = 2, midDistance would be 1

b) Count Pairs with Distance ≤ midDistance:

We now count how many pairs in the sorted array have a distance less than or equal to midDistance. This is where the sliding window technique comes into play.
(We'll get to how this counting works in a moment)

c) Adjust the Search Range:

If the count of pairs is less than k, it means our guess (midDistance) is too small, so we need to increase minDistance. If the count is greater than or equal to k, our guess might be too high or correct, we set maxDistance = midDistance.
The loop continues until minDistance and maxDistance converge, at which point we've found our answer.
if (pairsCount < k) {
        minDistance = midDistance + 1;
} else {
        maxDistance = midDistance;
}
Example:
If midDistance = 1 and the count of pairs with distance ≤ 1 is 2, and k = 3, we would adjust minDistance to midDistance + 1 = 2.

4. Counting Pairs with Distance ≤ midDistance

This step is crucial for the binary search to work. To count the number of pairs with a distance less than or equal to midDistance, we use the sliding window technique:
Initialize two pointers: left starts at the beginning of the array, and right starts at 1.
Move the right pointer: For each position of right, we check the distance between numbers[right] and numbers[left].
If the distance is greater than midDistance, move the left pointer forward until the distance is within midDistance.
The number of valid pairs ending at right is right - left.
Why Sliding Window Works:
The sorted array ensures that once a pair exceeds the midDistance, all subsequent pairs involving the current left index will also exceed midDistance. This allows us to increment the left pointer efficiently without rechecking unnecessary pairs.
Example:
For numbers = [1, 1, 3] and midDistance = 1, we would find:
Pair (1, 1) with distance 0 is valid.
Pair (1, 3) with distance 2 is not valid, so we move left.
Pair (1, 3) is still invalid after moving left.
The total count is 1.

5. Finalizing the Result

When the binary search loop ends, minDistance will be equal to maxDistance, and this value is our answer - the k-th smallest pair distance.
Now, let's delve deeper into why this approach works:
The binary search allows us to efficiently narrow down the possible range for the k-th smallest distance. Each iteration, we effectively eliminate half of the remaining possibilities.
The counting step is the key to making this work. By sorting the array first, we ensure that as we slide our window (moving the right pointer), we're always looking at increasing distances. This allows us to efficiently count all pairs with a distance less than or equal to our current guess.
The thing about this approach is that we never actually need to calculate and store all the pair distances. We're always working with the original array and just counting pairs that meet our criteria.
One thing to note: this method will always find the smallest distance that has at least k pairs less than or equal to it. In other words, if there are multiple pairs with the same distance, we'll get the correct result for the k-th smallest distance.

Complexity Analysis
Time Complexity: O(nlogn+nlogW)

Let's break this down step by step:

Sorting the array: O(nlogn)
Where n is the length of the input array.

Binary search: O(logW)
Where W is the range of possible distances (max element - min element).
In the worst case, this is O(log M), where M is the maximum possible value in the array (10^6 according to the problem constraints).

Counting pairs: O(n) per binary search iteration
We do this counting step for each iteration of the binary search.

Putting it all together:
O(nlogn)+O(logW)∗O(n)=O(nlogn+nlogW)

In the worst case, this simplifies to O(n log n + n log M), where M is the maximum possible value in the array.
It's worth noting that while this looks similar to O(n log n), the log M factor can be significant when M is large. However, it's still much better than the O(n^2) complexity of the brute force approach.

Space Complexity:O(1)

The space complexity is O(1), or constant space, excluding the space needed for sorting.
We're not using any extra data structures that grow with the input size. We're just using a few variables for our pointers and counters.
However, it's important to note that many sorting algorithms require O(n) extra space. If we're using an in-place sorting algorithm like heapsort, we can maintain the O(1) space complexity. But if we're using a sorting algorithm like mergesort, the space complexity would be O(n).
*/

// Solution:
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minDistance = 0, maxDistance = nums.back() - nums.front();

        while (minDistance < maxDistance) {
            int midDistance = minDistance + (maxDistance - minDistance) / 2;
            if (countPairsWithinDistance(nums, midDistance) < k) {
                minDistance = midDistance + 1;
            } else {
                maxDistance = midDistance;
            }
        }

        return minDistance;
    }

private:
    int countPairsWithinDistance(vector<int>& nums, int targetDistance){
        int count = 0, left = 0;
        for(int right = 1; right < nums.size(); ++right){
            while(nums[right] - nums[left] > targetDistance){
                ++left;
            }
            count += right - left;
        }
        return count;
    }
};
