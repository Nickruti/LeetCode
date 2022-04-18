// URL - https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

class Solution {
public:
    int minimumSum(int num) {
        string numStr = to_string(num);
        sort(numStr.begin(), numStr.end());
        int ans = (numStr[0] - '0' + numStr[1] - '0') * 10 + numStr[2] - '0' + numStr[3] - '0';
  
        return ans;
    }
};