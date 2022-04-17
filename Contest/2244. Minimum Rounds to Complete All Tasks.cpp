// URl - https://leetcode.com/contest/weekly-contest-289/problems/minimum-rounds-to-complete-all-tasks/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> m;
        int ans = 0;
        
        for(int i = 0; i < tasks.size(); i++)
        {
            m[tasks[i]]++;
        }
        
        for(auto &it: m)
        {
            cout<<it.second<<"\n";
            if(it.second < 2)
            {
                return -1;
            }
            
            if(it.second % 3 == 0)
            {
                ans += it.second/3;
            }
            else
            {
                if((it.second - 4)%3 == 0)
                    ans += ((it.second - 4) / 3) + 2;
                else if((it.second - 2)%3 == 0)
                    ans += ((it.second - 2) / 3) + 1;
            }
            
        }
        return ans;
    }
};