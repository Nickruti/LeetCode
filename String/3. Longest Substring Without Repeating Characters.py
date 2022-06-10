# Url - https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        store = [0] * 256
        left = 0
        right = 0
        ans = 0
        
        while right < len(s):
            store[ord(s[right])] += 1
            
            while store[ord(s[right])] > 1:
                store[ord(s[left])] -= 1
                left += 1
                
            ans = max(ans, right - left + 1)
            right += 1
            
        return ans