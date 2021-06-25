class Solution {
public:
    int fib(int n) {
        int x = 0, y = 1;
        if(n == 0)
        {
            return 0;
        }
        else if(n == 1)
        {
            return 1;
        }
        
        for(int i = 2; i <= n; i++)
        {
            y = x + y;
            x = y - x;
        }
        return y;
    }
};