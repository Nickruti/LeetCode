// Link to the problem: https://leetcode.com/problems/ugly-number/description/
// Beats 100% of the users
// Topics: Math
// My solution:
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0 ){
            return false;
        }
        int num = n;
        while(num > 0){
            if(num == 1){
                return true;
            } 
            if(num % 2 == 0){
                num = num / 2;
            } else if (num % 3 == 0){
                num = num / 3;
            } else if (num % 5 == 0){
                num = num / 5;
            } else {
                return false;
            }
        }
        return true;
    }
};
