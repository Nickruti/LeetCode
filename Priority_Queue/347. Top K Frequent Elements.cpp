// Url - https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        priority_queue<pair<int, int>> maxHeap;
        
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        
        for(auto& it: m)
        {
            maxHeap.emplace(it.second, it.first);
        }
        
        while(k--)
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
            
        return ans;
        
    }
};