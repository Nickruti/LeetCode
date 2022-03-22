// url - https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> alphaIndex(26, -1);
        vector<int> ans;

        for(int i = 0; i < s.length(); i++)
        {
            alphaIndex[s[i] - 'a'] = i;
        }
        
        int low = 0, high = alphaIndex[s[0] - 'a'], ptr;
        
        
        while(high != s.length() - 1)
        {
            ptr = high;
            while(low < ptr)
            {
                if(alphaIndex[s[ptr] - 'a'] > alphaIndex[s[high] - 'a'])
                {
                    high = alphaIndex[s[ptr] - 'a'];
                    break;
                }
                ptr--;
                
            }
            if(ptr == low)
            {
                ans.push_back(high - low + 1);
                low = high + 1;
                high = alphaIndex[s[low] - 'a']; 
            }
        }
        ans.push_back(high - low + 1);
        return ans;
    }
};