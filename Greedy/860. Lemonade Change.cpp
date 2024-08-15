// Link to the Problem - https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15
// Problem: 860. Lemonade Change

// My Solution
// Time Complexity - O(N)
// Comments: Runtime: 60ms Beats 92.98%
 
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollars = 0;
        int tenDollars = 0;
        for(int i = 0; i < bills.size(); i++){
            switch (bills[i]){
                case 5:
                    fiveDollars += 1;
                    break;
                case 10:
                    if(fiveDollars > 0){
                        fiveDollars -= 1;
                        tenDollars += 1;
                    } else {
                        return false;
                    }
                    break;
                case 20:
                    if(tenDollars > 0 && fiveDollars > 0){
                        tenDollars -= 1;
                        fiveDollars -= 1;
                    } else if (fiveDollars > 2){
                        fiveDollars -= 3;
                    } else {
                        return false;
                    }
                    break;
            }
        }
        return true;
    }
};
