/*Problem url : https://leetcode.com/problems/subsets-ii/ */

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.



class Solution {
public:
    set<vector<int>> stt;
    void print(int index, vector<int> &v, vector<vector<int>> &ans, vector<int> &nums,int n)
    {
        if(index == n)
        {
            if(stt.find(v)==stt.end())
            {
                ans.push_back(v);
                stt.insert(v);
            }
            
            return;
        }
        
        print(index+1,v,ans,nums,n);
        
        v.push_back(nums[index]);
        print(index+1,v,ans,nums,n);
        v.pop_back();           
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        int n = nums.size();
        print(0,v,ans,nums,n);
        
        return ans;
    }
};
