// Url - https://leetcode.com/problems/count-integers-with-even-digit-sum/

class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        
        for(int i = 2; i <= num; i++)
        {
            int sum = 0, n = i;
            while(n > 0)
            {
                sum += n % 10;
                n = n/10;
            }
            if(sum % 2 == 0)
            {
                ans++;
            }
        }
        return ans;
    }
};