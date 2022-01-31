// Url - https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1;
        string ans;
        
        int carry = 0;
        while (i >= 0 && j >= 0)
        {
            int currentSum = (num1[i] - '0') + (num2[j] - '0') + carry;
            
            string tempSum = to_string(currentSum);
            
            if( currentSum > 9)
            {
                carry = 1;
                ans += tempSum[1];
            }
            else
            {
                carry = 0;
                ans += tempSum;
            }
            i--;
            j--;
        }

        while (i >= 0)
        {
            int currentSum = (num1[i] - '0') + carry;
            string tempSum = to_string(currentSum);
            
            if( currentSum > 9)
            {
                carry = 1;
                ans += "0";
            }
            else
            {
                carry = 0;
                ans += tempSum;
            }
            i--;  
        }
        
        while (j >= 0)
        {
            int currentSum = (num2[j] - '0') + carry;
            string tempSum = to_string(currentSum);
            
            if( currentSum > 9)
            {
                carry = 1;
                ans += "0";
            }
            else
            {
                carry = 0;
                ans += tempSum;
            }
            j--;  
        }
        
        if (carry)
        {
            ans += "1";
        }
        
        ans = string(ans.rbegin(), ans.rend());
        return ans;
        
    }
};