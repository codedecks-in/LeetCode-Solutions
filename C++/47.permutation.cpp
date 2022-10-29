class Solution {
    private:
    bool checkmiddle(vector<int>& nums, int i , int index){
        for(auto j = index; j<i; j++)
            if(nums[i] == nums[j])
                return false;
        return true;
    }
    void solve(int index,vector<vector<int>> &ans,vector<int> nums){
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }   
       
        for(int i=index;i<nums.size();i++)
        { 
         if((nums[i]!=nums[index] || i == index) && checkmiddle(nums,i,index))
         {swap(nums[index],nums[i]);
          solve(index+1,ans,nums);
          swap(nums[index],nums[i]);
         }
        }
        
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int index=0;
        vector<vector<int>> ans;
        solve(index,ans,nums);
        return ans;
    }
};
