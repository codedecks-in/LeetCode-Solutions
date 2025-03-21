/*

Difficulty: Medium

_____________________________________________________________
Examples:
Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 
______________________________________________________________________________________________________________________________

Steps and logic for below solution:

as vector nums contain integers and we have to find integers whose occurence is more than third size of vector nums.

we will sort the vector then traverse it and while traversing we will count for each elements occurnec
and if occrence is more than or equal to k(k=nums.size()/3) we will push that element in vector res;

return vector res;

time complexity is O(n+nlog(n))=>O(nlogn);


*/




class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            
            int n=nums.size();
            int k=n/3;
            vector<int> res;
            int count=0;
            for(int i=0;i<n;i++){
                int a=nums[i];
                count=0;
                while(i<n and nums[i]==a){
                    i++;
                    count++;
                }
                i--;
                if(count>k) res.push_back(a);
            }
            return res;
    
        }
    };