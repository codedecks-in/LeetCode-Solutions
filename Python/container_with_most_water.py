class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        #print(height)
        start=0
        end=len(height)-1
        max_area=0
        curr_area=0
        while(start!=end):
            if(height[start]<height[end]):
                curr_area=height[start]*(end-start)
                start+=1
            else:
                curr_area=height[end]*(end-start)
                end-=1
            if(curr_area>max_area):
                max_area=curr_area
            print(curr_area)
        return max_area
