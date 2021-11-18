// url -> https://leetcode.com/problems/n-th-tribonacci-number/

class Solution {
public:
    int tribonacci(int n) {
        int x = 0, y = 1, z = 1;
        if (n == 0)
        {return 0;}
        else if (n == 1)
        {return 1;}
        else if (n == 2)
        {return 1;}
        
        
        for(int i = 3; i <= n; i++)
        {
            z += x + y;
            y = z - (x + y);
            x = z - y - x;
            
        }
        return z;
    }
};
