// Url - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minV = prices[0], maxV = prices[0], profit = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < minV)
            {
                minV = prices[i];
                maxV = prices[i];
            }
            else if (prices[i] > maxV)
            {
                maxV = prices[i];
                profit = max(profit, maxV - minV);
            }
        }
        return profit;
    }
};