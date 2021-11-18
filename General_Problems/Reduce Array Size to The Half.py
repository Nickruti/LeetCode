# url - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3804/

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        
        counts = {}
        
        for i in arr:
            counts[i] = counts.get(i, 0) + 1
            
        counts = sorted(counts.items(), key=lambda x: x[1], reverse=True)
            
        ans = 0
        cnt = 0
        leng = len(arr)
        
        for i in counts:
            if cnt >= (leng//2):
                break
            ans += 1
            cnt += i[1]
            
        
        return ans
