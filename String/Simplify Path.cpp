// Url - https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string tempStr = "";
        tempStr += path[0];
        
        if(path[path.length() - 1] != '/')
        {
            path.push_back('/');
        }
        
        for(int i = 1; i < path.length(); i++)
        {
            if(path[i] != '/')
            {
                tempStr += path[i];
            }
            else
            {
                if(tempStr == "/..")
                {
                    if(!s.empty())
                        s.pop();
                }
                else if(tempStr == "/" || tempStr == "/.")
                {      
                    if(!s.empty())
                    {
                        tempStr = "/";
                        continue;
                    }
                }
                else
                {
                    s.push(tempStr);
                } 
                tempStr = path[i];
            }
        }
        
        string ans = "";
        while(!s.empty())
        {
            ans = s.top() + ans;
            s.pop();
        }
        
        return ans.length() == 0 ? tempStr : ans;
    }
};