// url - https://leetcode.com/problems/palindrome-number/

// by converting number in to string
class Solution {
public:
    bool isPalindrome(int x) {
        string xNum = to_string(x);
        int xlen = xNum.length();
        
        for(int i = 0; i < xlen/2; i++)
        {
            if(xNum[i] != xNum[xlen-i-1])
                return false;
        }
        return true;
    }
};

// using math

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x>=2147483647){
            return false;
        }else{
            long int y=x;
            long int num=0;
            while(x>0){
                cout<<num<<"\t"<<x<<"\n";
                num=num*10;
                num=num+(x%10);
                x=x/10;
            }
            return num==y;
        }
    }
};
