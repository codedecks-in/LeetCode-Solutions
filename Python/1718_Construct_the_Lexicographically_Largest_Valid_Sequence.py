'''
making a backtracking based sol which uses all the permutations to fit a number at a pos using backtracking.
link:-https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/?envType=daily-question&envId=2025-02-16
'''
class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        ans = [0] * (2 * n - 1)
        use = set()
        
        def back(i):
            if i == len(ans):
                return True
            if ans[i]:  # Skip filled positions
                return back(i + 1)
            
            for num in range(n, 0, -1):
                if num in use:
                    continue
                if num > 1 and (i + num >= len(ans) or ans[i + num]):
                    continue
                
                # Place the number
                use.add(num)
                ans[i] = num
                if num > 1:
                    ans[i + num] = num
                
                # Recurse to next available position
                if back(i + 1):
                    return True
                
                # Backtrack
                use.remove(num)
                ans[i] = 0
                if num > 1:
                    ans[i + num] = 0
            
            return False
        
        back(0)
        return ans
if __name__ == "__main__":
  s= Solution()
  num = int(input())
  print(s.constructDistancedSequence(num))
