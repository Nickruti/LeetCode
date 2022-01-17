// Url - https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = word1.size(), w2 = word2.size();
        if (w1 < w2) return arrayStringsAreEqual(word2, word1);
        string str1 = "", str2 = "";
        int i = 0;
        
        while(i < w2)
        {
            str1 += word1[i];
            str2 += word2[i];
            i++;
        }
        while(i < w1)
        {
            str1 += word1[i];
            i++;
        }    
        return (str1 == str2);
    }
};