/*1512 Number of Good Pairs
  Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j. */

//Solution
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
    
    //created a new unoredered map
     unordered_map<int, int > mp;
        int ans =0;
        int n= nums.size();
        
        for (int i=0; i<n;i++){
        
           //inserting the elements of vector in map
           ++ mp [nums [i]];
            
            if(mp[nums[i]]>1){
                ans += mp[nums[i]] -1;
              }
        }
        return ans;
        
    }
};

 
