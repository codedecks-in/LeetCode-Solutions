//Medium
//Expected Time Complexity: O(n^2)

class Solution {
public:
    
    void solve(vector<int>nums,vector<int>output,int index,vector<vector<int>>&ans)
    {
        //base case
        if(index>=nums.size())
        {
            ans.push_back(output);
            return;
        }
        
        //Recursive Case
        
        //Exclude
        solve(nums,output,index+1,ans);
        
        //Include
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);        
        

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index=0;
        solve(nums,output,index,ans);
        return ans;
    }
};
