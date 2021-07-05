# url - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3802/

class Solution:
    def countVowelPermutation(self, n: int) -> int:
        
        if n == 1:
            return 5
        if n == 2:
            return 10
        
        dp = [[0 for i in range(5)] for j in range(n)]
        
        dp[1][0] = 3
        dp[1][1] = 2
        dp[1][2] = 2
        dp[1][3] = 1
        dp[1][4] = 2
        
        conDict = {0:[1,2,4], 1:[0,2], 2:[1,3], 3:[2], 4:[2,3]}
        
        for i in range(2,n):
            for j in range(5):
                for k in conDict[j]:
                    dp[i][j] += dp[i-1][k]
        
        return sum(dp[n-1])%((10**9) + 7)
        
