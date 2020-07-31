/*
*
*
* Runtime : 80ms
* Memory : 9.6 MB
* Logic : 0/1 knapsack concept used to calculate subsetSum
*/
class Solution {
public:
    
    // using 0/1 knapsack top down approach
    bool subsetSum(vector<int>& nums, int sum)
    {
        // size = nums+1, sum+1
        bool t[nums.size()+1][sum+1];
        
        for(int i= 0;i<=nums.size();i++)
        {
            t[i][0] = true;
        }
        
        for(int i= 0;i<=sum;i++)
        {
            t[0][i] = false;
        }
        
        t[0][0] = true;
        
        for(int i= 1;i<nums.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1] <= j)
                {
                    //get max by including number in the subset || by not including in subset sum
                    t[i][j] = t[i-1][j - nums[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[nums.size()-1][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int sum = 0;
        for(int  i = 0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        if(sum%2 != 0 )
            return false;
        
        return subsetSum(nums, sum/2);
        
    }
};
