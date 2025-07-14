# 20. Valid parenthesis
# https://leetcode.com/problems/valid-parentheses/description/
# Difficulty: Easy
# Strategy: Stack.

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        parenthesis = {"(": ")", "[": "]", "{": "}"}

        for p in s:
            if stack:
                top = stack[-1]
                if top in parenthesis and parenthesis[top] == p:
                    stack.pop()
                else: 
                    stack.append(p)
            else:
                stack.append(p)

        if stack:
            return False
        else:
            return True
        

def test():
    sol = Solution()
    s = "([)]"
    return sol.isValid(s)

print(test())
