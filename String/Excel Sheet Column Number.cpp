// url - https://leetcode.com/problems/excel-sheet-column-number/

// One Solution - 

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int cl = columnTitle.length();
        map<char, int> alphabets = {{'A',1}, {'B',2}, {'C',3},
                                   {'D',4}, {'E',5}, {'F',6},
                                   {'G',7}, {'H',8}, {'I',9},
                                   {'J',10}, {'K',11}, {'L',12},
                                   {'M',13}, {'N',14}, {'O',15},
                                   {'P',16}, {'Q',17}, {'R',18},
                                   {'S',19}, {'T',20}, {'U',21},
                                   {'V',22}, {'W',23}, {'X',24},
                                   {'Y',25}, {'Z',26}};
        int ans = 0;
        for (int i = 0; i < cl; i++)
        {
            ans += alphabets[columnTitle[i]] * pow(26, cl - i - 1);
        }
        
        return ans;

    }
};

// Second Solution -
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int cl = columnTitle.length();
    
        int ans = 0;
        for (int i = 0; i < cl; i++)
        {
            ans += (columnTitle[i] - 64) * pow(26, cl - i - 1);
        }
        
        return ans;

    }
};

// Third Solution - 100% Accuracy - More Correct way

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int cl = columnTitle.length();
    
        int ans = 0;
        for (int i = 0; i < cl; i++)
        {
            ans += (columnTitle[i] - 'A' + 1) * pow(26, cl - i - 1);
        }
        
        return ans;

    }
};
