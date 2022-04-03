// Url - https://leetcode.com/contest/weekly-contest-287/problems/minimum-number-of-operations-to-convert-time/

class Solution {
public:
    int convertTime(string current, string correct) {
        if(current == correct)
        {
            return 0;
        }

        int currentHour = stoi(current.substr(0,2));
        int correctHour = stoi(correct.substr(0,2));
        
        int currentMin = stoi(current.substr(3,5));
        int correctMin = stoi(correct.substr(3,5));
        
        int ans = correctHour - currentHour;
        if(currentMin == correctMin)
            return ans;
        
        if(correctMin % 5 == 0 && currentMin % 5 != 0)
        {
            ans += (5 - currentMin % 5);
            currentMin += (5 - currentMin % 5);
        }
        if(currentMin > correctMin)
        {
            currentMin = correctMin + (60 - currentMin);
            ans--;   
        }
        else
        {
            currentMin = correctMin - currentMin;
        }
        cout << currentMin << "\n";
        ans += currentMin/15;

        currentMin = currentMin % 15;
        ans += currentMin/5;

        currentMin = currentMin % 5;
        ans += currentMin;
        
        return ans;
    }
};