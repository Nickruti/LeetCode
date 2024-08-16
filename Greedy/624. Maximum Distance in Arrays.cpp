/* 
Link to the Problem - https://leetcode.com/problems/maximum-distance-in-arrays/description/?envType=daily-question&envId=2024-08-16
Problem - 624. Maximum Distance in Arrays
Difficulty - Medium
Topics - Array, Greedy
My Solution ==>
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int sNum = arrays[0][0];
        int bNum = arrays[0].back();
        int maxDist = 0;

        for(int i = 1; i < arrays.size(); i++){
            maxDist = max(maxDist, abs(arrays[i].back() - sNum));
            maxDist = max(maxDist, abs(bNum - arrays[i][0]));
            sNum = min(sNum, arrays[i][0]);
            bNum = max(bNum, arrays[i].back());
        }

        return maxDist;
    }
};
