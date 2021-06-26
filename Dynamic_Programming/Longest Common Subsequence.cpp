

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
        int sl1 = text1.length(), sl2 = text2.length();
        
        int subseq[sl1+1][sl2+1];
        
        for(int i = 0; i <= sl2; i++)
        {
            subseq[0][i] = 0;
        }
        for(int i = 0; i <= sl1; i++)
        {
            subseq[i][0] = 0;
        }
        
        for(int i = 1; i <= sl1; i++)
        {
            for(int j = 1; j <= sl2; j++)
            {
                if (text1[i-1] == text2[j-1])
                {
                    subseq[i][j] = subseq[i-1][j-1] + 1;
                }
                else
                {
                    subseq[i][j] = max(subseq[i-1][j], subseq[i][j-1]);
                }
            }
        }
        
        int i = sl1, j = sl2;
        vector<char> ans;
        
        while(i && j)
        {
            while(i && j && subseq[i][j] == subseq[i-1][j])
            {
                i--;
            }
            ans.push_back(text1[i-1]);
            i--;
            while(i && j && subseq[i][j] == subseq[i][j-1])
            {
                j--;
            }
        }
        
        for (auto ir = ans.rbegin(); ir != ans.rend(); ++ir)
        cout << *ir ;
        //return subseq[sl1][sl2];
}

int main()
{
    string t1, t2;
    cin >> t1;
    cin >> t2;
    longestCommonSubsequence(t1, t2);
    return 0;
}
