#------------- Strings Problems -------------------

#Runtime: 40 ms, faster than 91.64% of Python3 online submissions for Roman to Integer.
#Memory Usage: 14.2 MB, less than 58.30% of Python3 online submissions for Roman to Integer.

class Solution:
    def romanToInt(self, s: str) -> int:
        romToIntDict = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        
        num = 0
        prev = 0
        for i in s:
            if prev < romToIntDict[i]:
                if romToIntDict[i] % 500 == 0 and prev == 100:
                    num -= 200
                elif romToIntDict[i] % 50 == 0 and prev == 10:
                    num -= 20
                elif romToIntDict[i] % 5 == 0 and prev == 1:
                    num -= 2
            num += romToIntDict[i]
            
            prev = romToIntDict[i]
        return num
