// Link to the problem - https://leetcode.com/problems/pascals-triangle-ii/description/
// Topics - Array, Dynamic Programming
// Runtime - 0 ms Beats 100.00% of users with C++
// Memory - 7.58 MB Beats 65.06% of users with C++

// My Solution -------------------------------------------------------------------
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> lastArr = {1};
        vector<int> currArr = {};
        if(rowIndex == 0){
            return lastArr;
        }
        lastArr = {1, 1};
        if(rowIndex == 1){
            return lastArr;
        }
        for(int i = 2; i <= rowIndex; i++){
            currArr.push_back(1);
            for(int j = 0; j < lastArr.size() - 1; j++){
                currArr.push_back(lastArr[j] + lastArr[j + 1]);
            }
            currArr.push_back(1);
            lastArr = currArr;
            currArr = {};
        }
        return lastArr;
     }
};
