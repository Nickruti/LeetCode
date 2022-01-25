// Url - https://leetcode.com/problems/jump-game-iv/

// Hard Problem

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int len = arr.size();
        
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < len; i++)
        {
            m[arr[i]].push_back(i);            
        }
        
        vector<int> visited(len, 0);
        vector<int> distance(len, 0);
        
        queue<int> bfs;
        
        int i = 0;
        bfs.push(0);
        visited[0] = 1;
        distance[0] = 0;
        
        while(!bfs.empty())
        {
            i = bfs.front();
            bfs.pop();
            if (i == (len - 1))
                return distance[i];
            if ((i-1) >= 0 && visited[i-1] == 0)
            {
                bfs.push(i-1);
                visited[i - 1] = 1;
                distance[i - 1] = distance[i] + 1;
            }
            if (visited[i+1] == 0)
            {
                bfs.push(i+1);
                visited[i + 1] = 1;
                distance[i + 1] = distance[i] + 1;
            }
            if (m.count(arr[i]))
            {
                for(auto node:m[arr[i]])
                {
                    if (!visited[node])
                    {
                        bfs.push(node);
                        visited[node] = 1;
                        distance[node] = distance[i] + 1;
                    }
                        
                }
                m.erase(arr[i]);
            }
            
        }
        return 0;
    }
};