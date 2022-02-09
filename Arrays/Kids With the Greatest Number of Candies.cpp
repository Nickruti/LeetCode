// Url - https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = candies[0];
        vector<bool> ans;
        for (int i = 1; i < candies.size(); i++)
        {
            if (candies[i] > maxCandies)
            {
                maxCandies = candies[i];
            }
        }
        
        for (int i = 0; i < candies.size(); i++)
        {
            if ((candies[i] + extraCandies) >= maxCandies)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};