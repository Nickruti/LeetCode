'''
You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
Example 3:

Input: nums = []
Output: []
Example 4:

Input: nums = [-1]
Output: ["-1"]
Example 5:

Input: nums = [0]
Output: ["0"]
'''

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        len_ = len(nums)
        
        if len_ == 0:
            return []
        
        elif len_== 1:
            return [str(nums[0])]
        
        else:
            arr = []
            init = nums[0]
            cnt = 1
            for i in range(1,len_): 
                if nums[i] == nums[i-1]+1:
                    cnt = cnt + 1
                    if i!=len_-1:
                        continue
                    else:
                        arr.append(str(str(init)+"->"+str(nums[i])))
                        break
                
                if (nums[i] - nums[i-1])>1 and cnt == 1:
                    arr.append(str(nums[i-1]))
                 
                else:
                    arr.append(str(str(init)+"->"+str(nums[i-1])))
                   
                init = nums[i]
                cnt = 1
                if i == len_-1:
                    arr.append(str(nums[i]))
                    break
                
            return arr
            
'''
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
'''
                
                
        
        
        
