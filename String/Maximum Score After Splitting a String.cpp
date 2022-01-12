// url - https://leetcode.com/problems/maximum-score-after-splitting-a-string/

class Solution {
public:
    int maxScore(string s) {
        
        int ans = 0, slen = s.length();
        for (int i = 0; i < slen - 1; i++)
        {
            int temp_sum = 0;
            for (int j = 0; j < i + 1; j++)
            {
                if (s[j] == '0')
                    temp_sum++;
            }
            for (int j = i + 1; j < slen; j++)
            {
                if (s[j] == '1')
                    temp_sum++;
            }
            if (temp_sum > ans)
            {
                ans = temp_sum;
            }
        }
        return ans;
    }
};

