#Time Complexity:   O(n)
#Space Complexity:  O(1)
#Speed: 92.57%
#Memory: 15.17%

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if not n: return 1
        power = self.myPow(x, int(n/2))
        if n % 2 == 0:
            return power * power
        else:
            return power * power / x if n < 0 else power * power * x