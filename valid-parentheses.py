#Runtime: 32 ms, faster than 63.62% of Python3 online submissions for Valid Parentheses.
#Memory Usage: 14.3 MB, less than 66.49% of Python3 online submissions for Valid Parentheses.
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 1:
            return 0
        stack = []
        for i in range(len(s)):
            if s[i] == ')' or s[i] == '}' or s[i] == ']':
                if len(stack) != 0:
                    bracket = stack.pop()
                    if s[i] != bracket:
                        return 0
                else:
                    return 0
            elif s[i] == '(':
                stack.append(')')
            elif s[i] == '{':
                stack.append('}')
            elif s[i] == '[':
                stack.append(']')
        
        if len(stack) == 0:
            return 1
        else:
            return 0
