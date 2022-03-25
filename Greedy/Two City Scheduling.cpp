// Url - https://leetcode.com/problems/two-city-scheduling/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> difference;
        int totalCost = 0;
        
        for(int i = 0; i < costs.size(); i++)
        {
            totalCost += costs[i][0];
            difference.push_back(costs[i][1] - costs[i][0]);
        }
        
        sort(difference.begin(), difference.end());
        
        for(int i = 0; i < costs.size()/2; i++)
        {
            totalCost += difference[i];
        }
        
        return totalCost;
    }
};