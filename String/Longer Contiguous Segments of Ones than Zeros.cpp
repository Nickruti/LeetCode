// Url - https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/

class Solution {
public:
    bool checkZeroOnes(string s) {
        
        int cntOne = 0, cntZero = 0, maxOne = 0, maxZero = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                cntZero++;
                cntOne = 0;
            }
            else
            {
                cntOne++;
                cntZero = 0;
            }
            if (maxOne < cntOne) 
            {
                maxOne = cntOne;
            }
            else if (maxZero < cntZero) 
            {
                maxZero = cntZero;
            }
        }
        return (maxOne > maxZero);
    }
};