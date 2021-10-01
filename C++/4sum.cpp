/*
Difficulty Level: Medium
Time cmplexity: O(N^3)


/////
Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

///////
Test cases:
Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

*/
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                while (l < r)
                {
                    if (sum == nums[l] + nums[r])
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        vec.push_back(v);
                        while (l < r and nums[l] == v[2])
                            ++l;
                        while (l < r and nums[r] == v[3])
                            --r;
                    }
                    else if (sum > nums[l] + nums[r])
                        l++;
                    else
                        r--;
                }
                while (j + 1 < n and nums[j + 1] == nums[j])
                    ++j;
            }
            while (i + 2 < n and nums[i + 1] == nums[i])
                ++i;
        }
        return vec;
    }
};