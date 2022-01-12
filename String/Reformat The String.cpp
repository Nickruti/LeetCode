class Solution {
public:
    string reformat(string s) {
        if (s.length() <= 1) return s;
        
        vector<int> numbers;
        vector<char> characters;
        string ans = "";
        
        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {
                characters.push_back(s[i]);
            }
            else if (isdigit(s[i]))
            {
                numbers.push_back(s[i]);
            }
        }
        
        int n = numbers.size(), c = characters.size(), i = 0;
        if ( n != 0 && c != 0 )
        {
            if (n > c)
            {
                ans.push_back(numbers[0]);
                while((i != n) && (i != c))
                {
                    ans.push_back(characters[i]);
                    i++;
                    ans.push_back(numbers[i]);
                }
            }
            else if (c > n)
            {
                ans.push_back(characters[0]);
                while((i != n) && (i != c))
                {
                    ans.push_back(numbers[i]);
                    i++;
                    ans.push_back(characters[i]);
                }
            }
            else
            {
                while((i != n) && (i != c))
                {
                    ans.push_back(numbers[i]);
                    ans.push_back(characters[i]);
                    i++;
                }
            }
            
            if (i == n && (i + 1) < c || i == c && (i + 1) < n)
            {
                return "";
            }
            else
            {
                return ans;
            }
            
        }
        return ans;
    }
};

// A Better Solution

class Solution {
public:
    string reformat(string s) {
        if (s.length() <= 1) return s;
        
        vector<int> numbers;
        vector<char> characters;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {
                characters.push_back(s[i]);
            }
            else if (isdigit(s[i]))
            {
                numbers.push_back(s[i]);
            }
        }
        
        int n = numbers.size(), c = characters.size();
        string ans = "";
        
        if (abs(n - c) > 1)   return ans;
        
        int i = 0;
        if (n > c)
        {
            ans.push_back(numbers[0]);
            while(i != c)
            {
                ans.push_back(characters[i]);
                i++;
                ans.push_back(numbers[i]);
            }
        }
        else
        {
            while(i != n)
            {
                ans.push_back(characters[i]);
                ans.push_back(numbers[i]);
                i++;
            }
            if (c > n)
            {
                ans.push_back(characters[i]);
            }
        }

        return ans;      
    }
};