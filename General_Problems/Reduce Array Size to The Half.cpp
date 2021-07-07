// url - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3804/

class Solution {
public:
    static bool cmp(pair<int, int>& a,
            pair<int, int>& b){
        
        return a.second > b.second;
        
    }
    
    int minSetSize(vector<int>& arr) {
        
        int size = arr.size();
        vector<int> maxcnt(size, 0);
        
        unordered_map<int, int> umap;
        
        vector<pair<int, int>> A;
        
        for (int i = 0; i < size; i++)
        {
            umap[arr[i]]++;
        }
        
        for (auto& it : umap)
        {
            A.push_back(it);
        }
        
        sort(A.begin(), A.end(), cmp);
        
        
        int cnt = 0, ans = 0;
        for (auto& it : A)
        {
            if (cnt >= (size/2))
            {
                break;
            }
            ans ++;
            cnt += it.second;
        }
        
        return ans;
      
    }
};
