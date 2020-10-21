 /*   The Optimized Solution
    Time Complexity: O(N)
    Space Complexity: O(1)

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
    int cs=0;
    int ms=INT_MIN;
    // if size of array is 1 return that elemnt .
    if(nums.size()==1){
        return nums[0];
    }
    //Linearly traverse the array and add to the current sum variable and take maximum .
	for (int i = 0; i < nums.size(); i++) {
		cs=cs+nums[i];
       
       
        ms=max(cs,ms);
        if(cs<0){
            cs=0;
        }
	}

	return ms;
}
        
        
        
    
    };