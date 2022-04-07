// Url - https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        
        if(i < j) return addBinary(b, a);
        
        while(j >= 0)
        {
            if(a[i] == '1' && b[j] == '1')
            {
                if(carry == 1)
                {
                    ans.push_back('1'); 
                }
                else
                {
                    ans.push_back('0');
                }
                carry = 1;
            }
            else if(a[i] == '0' && b[j] == '0')
            {
                if(carry == 1)
                {
                    ans.push_back('1'); 
                }
                else
                {
                    ans.push_back('0');
                }
                carry = 0;
            }
            else
            {
                if(carry == 1)
                {
                    ans.push_back('0'); 
                    carry = 1;
                }
                else
                {
                    ans.push_back('1');
                    carry = 0;
                }
            }
            i--;
            j--;
        }
        
        while(i >= 0)
        {
            if(a[i] == '1')
            {
                if(carry == 1)
                {
                    ans.push_back('0');
                    carry = 1;
                }
                else
                {
                    ans.push_back('1');
                    carry = 0;
                }
            }
            else
            {
                if(carry == 1)
                {
                    ans.push_back('1');
                }
                else
                {
                    ans.push_back('0');
                }
                carry = 0;
            }
            i--;
        }
        
        if(carry)
        {
            ans.push_back('1');
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);
        }
        if(carry) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};