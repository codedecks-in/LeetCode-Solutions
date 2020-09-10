'''
Speed:  77.11%
Memory: 82.57%
Time Complexity: O(n)
'''
class Solution:
    def getRow(self, k: int) -> List[int]:
        res = [1]*(k+1)
        #res[0]=1
        for i in range(1,k):
            for j in range(i,0,-1):
                res[j]+=res[j-1]
        return res