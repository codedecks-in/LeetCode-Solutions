// Brute force solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2);
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size();j++){
                if(nums[j] == target-nums[i]){
                    v[0] = i;
                    v[1] = j;
                    return v;
                }
            }
        }
        return v;
    }
};

// Above solution is of O(n^2) time complexity

//O(n) time complexity 
//O(n) space complexity


vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
      //  make a vector final result
	vector<int> finalresult;
	for (int i = 0; i < numbers.size(); i++) {
		int n = target - numbers[i];

            //if n is found in map, return them
		if (hash.find(n) != hash.end()) {
			result.push_back(hash[n] + 1);
			result.push_back(i + 1);			
			return finalresult;
		}
}
}
