# url - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3811/

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if s == t:
            return True
        
        d = {}
        
        for i in range (len(s)):
            if s[i] in d:
                if d[s[i]] != t[i]:
                    return False
        
            elif t[i] in d.values():
                return False
            
            d[s[i]] = t[i] 
            
        return True
        
