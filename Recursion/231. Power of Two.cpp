// Link to the problem: https://leetcode.com/problems/power-of-two/description/
// Faster than 100% of the user
// Difficulty: Easy
// Topics: Math, Bit Manipulation, Recursion
// My Solution:
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0){
            return false;
        } 
        int num = n;
        while(num > 0){
            if(num == 1){
                return true;
            }
            if(num % 2 != 0){
                return false;
            }
            num = num / 2;
        }
        return true;
    }
};
