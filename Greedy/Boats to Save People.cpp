// Url - https://leetcode.com/problems/boats-to-save-people/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int j = people.size() - 1, i = 0;
        int ans = 0;
        
        while(i <= j)
        {
            if(people[i] + people[j] <= limit)
                i++;
            ans++;
            j--;
        }
        return ans;
    }
};