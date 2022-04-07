// url - https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int lastInd = digits.size() - 1;
        if(digits[lastInd] < 9)
        {
            digits[lastInd]++;
            return digits;
        }
        for(int i = lastInd; i > -1; i--)
        {
            if(digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                return digits;
            }
        }
        
        digits.push_back(0);
        digits[0] = 1;
        return digits;
        
    }
};