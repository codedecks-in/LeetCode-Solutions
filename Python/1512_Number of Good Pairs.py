class Solution(object):
    
    def numIdenticalPairs(self,nums):
        
        self.nums = nums
        num_count = {}
    
        good_pairs = 0
   
        for num in self.nums:
            
            if num in num_count:
                num_count[num] += 1
            else:     
                num_count[num] = 1
       
        for count in num_count.values():
            good_pairs += (count * (count - 1)) // 2
        
        return good_pairs
        
