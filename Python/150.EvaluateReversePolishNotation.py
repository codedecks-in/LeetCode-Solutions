#Time Complexity:   O(n)
#Space Complexity:  O(1)
#Speed: 84.65%
#Memory: 84.34%

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token.isdigit() or token[1:].isdigit():
                stack.append(int(token))
            else:
                y = stack.pop()
                x = stack.pop()
                if token == '+': stack.append(x + y)
                if token == '-': stack.append(x - y)
                if token == '*': stack.append(x * y)
                if token == '/': stack.append(int(x / y))
        return stack[0]