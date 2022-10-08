class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        isPrime = [True] * n
        for i in xrange(2, n):
            if i * i >= n:
                break
            if not isPrime[i]:
                continue
            for j in xrange(i * i, n, i):
                isPrime[j] = False
        count = 0
        for i in xrange(2, n):
            if isPrime[i]:
                count += 1
        return count
