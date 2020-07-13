class Solution:
    def numSub(self, s: str) -> int:
        if not s: return 0

        def counter(n):
            return (n * (n + 1)) // 2

        i = 0
        lengths = []
        while i < len(s):
            if s[i] == '1':
                localtotal = 0
                while i < len(s) and s[i] == '1':
                    localtotal += 1
                    i += 1
                lengths.append(localtotal)
            else:
                i += 1
        total = 0
        for i in lengths:
            total += counter(i)
        return total % (10**9 + 7)
