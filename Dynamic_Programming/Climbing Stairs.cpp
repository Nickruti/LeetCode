// url - https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int x = 1, y = 2;
        if(n == 1)
        {return 1;}
        else if(n == 2)
        {
            return 2;
        }
        
        for(int i = 3; i <= n; i++)
        {
            y += x;
            x = y - x;
        }
        return y;
        
    }
};
