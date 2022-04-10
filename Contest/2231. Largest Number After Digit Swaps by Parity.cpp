// URL - https://leetcode.com/contest/weekly-contest-288/problems/largest-number-after-digit-swaps-by-parity/

class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> oddPQ;
        priority_queue<int> evenPQ;
        
        int i = 0;
        string originalNum = to_string(num);
        
        while(num > 0)
        {
            int tempMod = num % 10;
            
            if(tempMod %2 == 1)
            {
                oddPQ.push(tempMod);
            }
            else
            {
                evenPQ.push(tempMod);
            }
            num = num / 10;
        }
        
        
        for(int i = 0; i < originalNum.length(); i++)
        {
            if((originalNum[i] - '0') % 2 == 1)
            {
                num += oddPQ.top() * pow(10, originalNum.length() - i - 1);
                oddPQ.pop();
            }
            else
            {
                num += evenPQ.top() * pow(10,originalNum.length() - i - 1);
                evenPQ.pop();
            }
        }
        return num;
    }
};