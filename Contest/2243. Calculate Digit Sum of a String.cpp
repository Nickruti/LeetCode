// URL - https://leetcode.com/contest/weekly-contest-289/problems/calculate-digit-sum-of-a-string/

class Solution {
public:
    string digitSum(string s, int k) {
        string tempSum = "";
        int sum = 0, cnt = 0;
        while(s.length() > k)
        {
            for(int i = 0; i < s.length(); i++)
            {
                sum += (s[i] - '0');
                cnt++;
                if(cnt == k)
                {
                    tempSum += to_string(sum);
                    sum = 0;
                    cnt = 0;
                } 
            }
            if(cnt)
            {
                tempSum += to_string(sum);
                sum = 0;
                cnt = 0;
            }
            s = tempSum;
            tempSum = "";
        }
        return s;
    }
};