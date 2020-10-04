// Solved using backtracking
class Solution {
public:
    void recur(vector<vector<int>>& ans, vector<int>& v, vector<int>& candidates, int target, int curr){
        if(target==0){
            ans.push_back(v);
        }
        if(target<0){
            return; 
        }
        for(int i = curr; i< candidates.size(); i++){
            if(candidates[i]<=target){
                v.push_back(candidates[i]);
                recur(ans,v,candidates,target-candidates[i],i);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<vector<int>>ans;
        vector<int> v;
        
        sort(candidates.begin(), candidates.end());
        
        recur(ans,v,candidates,target,0);
        
        return ans;
    }
};