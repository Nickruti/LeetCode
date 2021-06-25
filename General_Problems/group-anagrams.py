class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashDict = {}
        result = []
        
        for i in strs:
            sorted_i = "". join(sorted(i))
            
            if sorted_i in hashDict.keys():
                hashDict[sorted_i].append(i)
            else:
                hashDict[sorted_i]= [i]
       
        for i,j in hashDict.items():
            result.append(j)
        return result
