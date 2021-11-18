// url - https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int slen = s.length();
        
        if (numRows == slen || numRows == 1) return s;
        int i;
        
        for(int row = 1; row <= numRows; row++)
        {
            i = row - 1;
            if(row == 1 || row == numRows)
            {
                while(i < slen)
                {
                    ans.push_back(s[i]);
                    i = i + ((numRows - 1) * 2);
                }
            }
            else
            {
                int flag = 0;
                while(i < slen)
                {
                    ans.push_back(s[i]);
                    if (flag == 0)
                    {
                        i = i + ((numRows - row) * 2);
                        flag = 1;
                    }
                    else
                    {
                        i = i + ((row - 1) * 2);
                        flag = 0;
                    }
                }
                
            }
        }
        return ans;
        
    }
};


