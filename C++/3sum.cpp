class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        
        int target = -nums[i];
        int front = i + 1;
        int back = nums.size() - 1;

        while (front < back) {

            int sum = nums[front] + nums[back];
            
            // Finding answer which start from number nums[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[front];
                triplet[2] = nums[back];
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && nums[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && nums[back] == triplet[2]) back--;
            }
            
        }

        // Processing duplicates of Number i
        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
            i++;

    }
    
    return res;
    }
};