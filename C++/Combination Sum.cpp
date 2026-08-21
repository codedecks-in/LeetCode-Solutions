class Solution {
public:
    
    //Firse
    vector<vector<int>> ans;
    
    void fun(vector<int> v, int target, int ind, vector<int> ds, vector<vector<int>> &ans){
        if(ind==v.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        //include curr element than we will not increment the ind  and target value decrease by v[ind]
        
        if(v[ind]<=target){
            ds.push_back(v[ind]);
            fun(v, target-v[ind], ind, ds, ans);
            ds.pop_back();   //backtrack
        }
        //otherwise if not include current element
        fun(v, target, ind+1, ds, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<int> ds;
        fun(cand, target, 0, ds, ans);
        return ans;
    }
};
