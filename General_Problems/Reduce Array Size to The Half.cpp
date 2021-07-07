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

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt;
        for (int x : arr) ++cnt[x];

        vector<int> bucket(n + 1);
        for (auto [_, freq] : cnt) ++bucket[freq];

        int ans = 0, removed = 0, half = n / 2, freq = n;
        while (removed < half) {
            ans += 1;
            while (bucket[freq] == 0) --freq;
            removed += freq;
            --bucket[freq];
        }
        return ans;
    }
};
