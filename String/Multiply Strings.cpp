// Url - https://leetcode.com/problems/multiply-strings/

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
    
    string multiply(string num1, string num2) {
        int nums2Len = num2.length(), nums1Len = num1.length();
        
        if (num1 == "0" || num2 == "0") return "0";
        
        string ans = "";
        int carry = 0;
            
        for(int i = nums2Len - 1; i >= 0; i--)
        {
            int currMult;
            string currSum = "";
            
            for(int j = nums1Len - 1; j >= 0; j--)
            {
                currMult = (num2[i] - '0') * (num1[j] - '0') + carry;
                carry = currMult / 10;
                currSum = to_string(currMult % 10) + currSum;
            } 
            if (carry)
                currSum = to_string(carry) + currSum;
            carry = 0;
            currSum.append(nums2Len - i - 1, '0');
            
            ans = addStrings(ans, currSum);  
            
        }
        
        return ans;
    }
};