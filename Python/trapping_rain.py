class Solution:
    def trap(self, height: List[int]) -> int:
        water=0
        left=-1
        right=len(height)
        current=0
        arr1=[]
        arr2=[]
        left_max=0
        right_max=0
        for current in range(len(height)):
            while(left!=current):
                left+=1
                if(left_max<=height[left]):
                    left_max=height[left]
            arr1.append(left_max)
            while(right!=current):
                right-=1
               
                if(right_max<=height[right]):
                    right_max=height[right]
            arr2.append(right_max)
            right_max=0   
                
            right=len(height)
            left=-1
        
        
        for i in range(len(arr1)):
            s=min(arr1[i],arr2[i])-height[i];
            if(s>0):
                water+=s
                
        return water
