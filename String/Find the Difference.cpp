// url - https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        if (s == "") return t[0];
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        int i = 0;
        for(i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
            {
                break;
            }
        }
        return t[i];
    }
};

// Second Solution - A better Solution - Time: O(n), Space: O(1)

class Solution {
public:
    char findTheDifference(string s, string t) {
     int size=s.size();
        char ans=t[size];
        for(int i=0;i<size;i++){
            ans=ans^(s[i]^t[i]);
        }
        return ans;
    }
};

// Third Solution

class Solution {
public:
    char findTheDifference(string s, string t) {
        if (s == "") return t[0];
        
        int i = 1;
        char temp = s[0] ^ t[0];
        while(i < s.length())
        {
            temp = temp ^ s[i];
            temp = temp ^ t[i];
            i++;
        }
        temp = temp ^ t[i];
        
        return temp;
    }
};

