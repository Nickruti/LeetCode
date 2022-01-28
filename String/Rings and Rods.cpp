// Url - https://leetcode.com/problems/rings-and-rods/

class Solution {
public:
    int countPoints(string rings) {
        int rlen = rings.length();
        vector<int> R (10, 0);
        vector<int> G (10, 0);
        vector<int> B (10, 0);
        
        for (int i = 0; i < rings.length(); i= i + 2)
        {
            if (rings[i] == 'R')
            {
                R[rings[i+1]-'0']++;
            }
            else if (rings[i] == 'G')
            {
                G[rings[i+1]-'0']++;
            }
            else if (rings[i] == 'B')
            {
                B[rings[i+1]-'0']++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
	    // If rod[i] contains all three rings, increment rod count
            if (R[i] > 0 && G[i] > 0 && B[i] > 0)
            {
                ans++;
            }
        }
        return ans;
    }
};