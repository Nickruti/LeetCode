// url - https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        int temp;
        
        temp = columnNumber % 26;
        if (temp == 0)
        {
            ans.push_back(26 + 'A' - 1);
            columnNumber -= 26;
        }
        else
        {
            ans.push_back(temp + 'A' - 1);
            columnNumber -= temp;
        }
        
        while ((columnNumber / 26) != 0)
        {
            columnNumber = columnNumber / 26;
            
            temp = columnNumber % 26;
            if (temp == 0)
            {
                ans.push_back(26 + 'A' - 1);
                break;
            }
            else
            {
                ans.push_back(temp + 'A' - 1);
            }

            columnNumber -= temp;
            }
        
        return string(ans.rbegin(), ans.rend());
            
    }
};
