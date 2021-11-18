# url - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3813/

class Solution:
    def customSortString(self, order: str, str: str) -> str:
        
        o = {}
        ans = ""
        for i in range(len(str)):
            o[str[i]] = o.get(str[i], 0) + 1
          
        for i in range(len(order)):
            if order[i] in o:
                ans = ans + (order[i] * o[order[i]])
                del o[order[i]]
                
        for i in o:
            ans = ans + (i * o[i])
        return ans
