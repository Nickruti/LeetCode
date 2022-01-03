// Url - https://leetcode.com/problems/robot-return-to-origin/

class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.length() % 2 == 1) return false;
        unordered_map<char, int> m;
        
        for (int i = 0; i < moves.length(); i++)
        {
            if (moves[i] == 'L')
            {
                m['L'] += 1;
            }
            else if (moves[i] == 'R')
            {
                m['R'] += 1;
            }
            else if (moves[i] == 'U')
            {
                m['U'] += 1;
            }
            else if (moves[i] == 'D')
            {
                m['D'] += 1;
            }
        }
        if (m['L'] == m['R'] && m['U'] == m['D'])
        {
            return true;
        }
        return false;
    }
};

// Little Optimized Method

class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.length() % 2 == 1) return false;
        unordered_map<char, int> m;
        
        for (int i = 0; i < moves.length(); i++)
        {
            m[moves[i]] += 1;
        }
        if (m['L'] == m['R'] && m['U'] == m['D'])
        {
            return true;
        }
        return false;
    }
};

// Third Method

class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.length() % 2 == 1) return false;
        int up = 0, lr = 0;
        
        for (int i = 0; i < moves.length(); i++)
        {
            if (moves[i] == 'L')
            {
                lr += 1;
            }
            else if (moves[i] == 'R')
            {
                lr -= 1;
            }
            else if (moves[i] == 'U')
            {
                up += 1;
            }
            else if (moves[i] == 'D')
            {
                up -= 1;
            }
        }
        if (lr == 0 && up == 0)
        {
            return true;
        }
        return false;
    }
};
