'''
Prolem Url - https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3573/
'''
#Time Complexity - O(n)
class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int:
        A.sort()
        minA, maxA = A[0], A[-1]
        result = maxA - minA
        for i in range(len(A) - 1):
            num1, num2 = A[i], A[i+1]
            result = min(result, max(maxA-K, num1+K) - min(minA+K, num2-K))
        return result
        
