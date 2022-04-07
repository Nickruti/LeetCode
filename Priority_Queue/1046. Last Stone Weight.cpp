// Url - https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int len = stones.size();

//	   Naive Solution - O(n^2 log n)
//         if(len == 1) return stones[0];
        
//         sort(stones.begin(), stones.end());
        
//         int i = len - 1;
//         int j = len - 2;
        
//         while(stones[i] > 0 && stones[j] > 0)
//         {
//             stones[i] = stones[i] - stones[j];
//             stones[j] = 0;
//             sort(stones.begin(), stones.end());
//         }
        
//         return stones[len - 1];
        
        priority_queue<int> pq(stones.begin(),stones.end());

        while( pq.size() > 1 )
        {
            int i = pq.top();
            pq.pop();
            
            int j = pq.top();
            pq.pop();
            
            if( i != j ) pq.push( i - j );
        }
        
        return pq.empty()? 0 : pq.top();
    }
};