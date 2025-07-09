def my_atoi(s: str) -> int:
    if not s:
        return 0
    
    i, n = 0, len(s)
    INT_MAX = 2**31 - 1
    INT_MIN = -2**31
    
    while i < n and s[i] == ' ':
        i += 1
    
    sign = 1
    if i < n and s[i] in ['+', '-']:
        if s[i] == '-':
            sign = -1
        i += 1
    
    result = 0
    while i < n and '0' <= s[i] <= '9':
        digit = ord(s[i]) - ord('0')

        if result > INT_MAX // 10 or (result == INT_MAX // 10 and digit > 7):
            return INT_MAX if sign == 1 else INT_MIN

        result = result * 10 + digit
        i += 1
        
    return result * sign